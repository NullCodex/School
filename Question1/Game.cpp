#include "Game.h"
#include <iostream>

Game::Game(std::vector<char> players, int seed) : deck_(seed){
	quit_ = false;
	for (int i = 0; i < players.size(); i++){
		if (players[i] == 'h'){
			players_.push_back(Human());
		}
		else{
			players_.push_back(Computer());
		}
	}
}

void Game::newRound(){
	table_.clear();
	deck_.shuffle();
	for (int i = 0; i < players_.size(); i++){
		players_[i].discardHand();
		players_[i].newHand(i, deck_);
	}
	determineFirstPlayer();
	std::cout << "A new round begins. It's player " << firstPlayer_ << "'s turn to play." << std::endl;
}

void Game::determineFirstPlayer(){
	for (int i = 0; i < players_.size(); i++){
		if (players_[i].contains(SPADE, SEVEN)){
			firstPlayer_ = i;
			break;
		}
	}
}

void Game::nextTurn(){
	int curPlayer = firstPlayer_;
	for (int i = 0; i < players_.size() && !quit_; i++){
		if (typeid(players_[curPlayer]) == typeid(Human())){
			Command c;
			outputCurrentTable();
			std::cout << "Your hand: " << players_[curPlayer] << std::endl;
			std::cout << "Legal plays: ";
			players_[curPlayer].legalPlays(table_.lastCardPlayed());
			std::cout << "\n";
			c.type = DECK;
			while (c.type == DECK){
				std::cin >> c;
				if (c.type == PLAY){
					try{
						players_[curPlayer].playCard(c.card, table_.lastCardPlayed());
						table_.placeCard(&c.card);
					}
					catch (Player::InvalidCardException &e){
						std::cout << "This is not a legal play." << std::endl;
						c.type == DECK;
					}
				}
				else if (c.type == DISCARD){
					try{

					}
					catch (CanPlayCardException &e){
						std::cout << "You have a legal play. You may not discard." << std::endl;
						c.type == DECK;
					}
				}
				else if (c.type == DECK){
					std::cout << deck_ << std::endl;
				}
				else if (c.type == QUIT){
					quit_ = true;
				}
				else{
					//ragequit
					players_[curPlayer] = Computer();
					// Want to make game a friend of both computer and human?
					// Need to transfer the ownership of cards to Computer.

				}
			}
			

		}
		else{
			//Do Computer player's turn
			std::cout << "Player " << curPlayer << " ";
			players_[curPlayer].legalPlays(table_.lastCardPlayed());
		}
	}
}

void Game::outputCurrentTable() const{
	std::cout << "Cards on the table:\n" << table_;
}

bool Game::winnerExists() const // function to check we have a winnder
{
	for(int i = 0; i < players_.size(); i++)
	{
		if(players_[i].getScore >= 80)
		{
			return true;
		}
	}
	return false;
}