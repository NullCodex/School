#include "Game.h"
#include <iostream>
#include <typeinfo>

Game::Game(std::vector<char> players, int seed) : deck_(seed), playerTypes_(players){
	quit_ = false;
	for (int i = 0; i < players.size(); i++){
		if (players[i] == 'h'){
			players_.push_back((Player*)new Human());
		}
		else{
			players_.push_back(new Computer());
		}
	}
}
Game::~Game(){
	for (int i = 0; i < players_.size(); i++){
		delete players_[i];
	}
}
void Game::newRound(){
	table_.clear();
	deck_.shuffle();
	for (int i = 0; i < players_.size(); i++){
		players_[i]->discardHand();
		players_[i]->newHand(i, deck_);
	}
	determineFirstPlayer();
	std::cout << "A new round begins. It's player " << firstPlayer_ << "'s turn to play." << std::endl;
}

void Game::determineFirstPlayer(){
	for (int i = 0; i < players_.size(); i++){
		if (players_[i]->contains(SPADE, SEVEN)){
			firstPlayer_ = i;
			break;
		}
	}
}

void Game::nextTurn(){
	int curPlayer = firstPlayer_;
	for (int i = 0; i < players_.size() && !quit_; i++){
		if (playerTypes_[curPlayer] == 'h'){
			Command c;
			outputCurrentTable();
			updatePossiblePlays();
			std::cout << "Your hand:" << *players_[curPlayer] << std::endl;
			std::cout << "Legal plays:";
			players_[curPlayer]->legalPlays(possiblePlays_);
			std::cout << "\n";
			c.type = DECK;
			while (c.type == DECK && !quit_){
				std::cin >> c;
				if (c.type == PLAY){
					try{
						Human* human = dynamic_cast<Human*>(players_[curPlayer]);
						human->playCard(c.card, possiblePlays_);
						table_.placeCard(&c.card);
					}
					catch (Human::InvalidCardException &e){
						std::cout << "This is not a legal play." << std::endl;
						c.type = DECK;
					}
				}
				else if (c.type == DISCARD){
					try{
						Human* human = dynamic_cast<Human*>(players_[curPlayer]);
						human->discardCard(c.card, possiblePlays_);
					}
					catch (Human::CanPlayCardException &e){
						std::cout << "You have a legal play. You may not discard." << std::endl;
						c.type = DECK;
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
					//players_[curPlayer] = Computer(players_[curPlayer]);
					// Want to make game a friend of both computer and human?
					// Need to transfer the ownership of cards to Computer.

				}
			}
		}
		else{
			//Do Computer player's turn
			std::cout << "Player " << curPlayer << " ";
			players_[curPlayer]->legalPlays(possiblePlays_);
		}
		(curPlayer += 1) % 4;
	}
}

void Game::outputCurrentTable() const{
	std::cout << "Cards on the table:\n" << table_;
}

bool Game::winnerExists() const // function to check we have a winnder
{
	for(int i = 0; i < players_.size(); i++)
	{
		if(players_[i]->getScore() >= 80)
		{
			return true;
		}
	}
	return false;
}

bool Game::hasQuit() const{
	return quit_;
}

void Game::endRound() {
	for (int i = 0; i < players_.size(); i++){
		std::cout << "Player " << (i + 1) << "'s discards :";
		players_[i]->outputDiscardList();
		std::cout << "Player " << (i + 1) << "'s score : " << players_[i]->getScore() << " + " << players_[i]->valueOfDiscarded() <<
			" = " << (players_[i]->getScore() + players_[i]->valueOfDiscarded()) << std::endl;
		players_[i]->updateScore();
	}

}

void Game::outputWinners() const{
	for (int i = 0; i < players_.size(); i++){
		if (players_[i]->getScore() >= 80){
			std::cout << "Player " << (i + 1) << " wins!\n";
		}
	}
}

void Game::updatePossiblePlays(){
	Card* card = table_.lastCardPlayed();
	if (card==NULL){
		return;
	}
	std::vector <Card*> possiblePlays;
	for (int i = 0; i < 4; i++){
		Card temp = Card((Suit)i, card->getRank());
		possiblePlays.push_back(&temp);
	}
	if (card->getSuit() == ACE){
		Card temp = Card(card->getSuit(), Rank(1));
		possiblePlays.push_back(&temp);
	}
	else if (card->getSuit() == KING){
		Card temp = Card(card->getSuit(), Rank(11));
		possiblePlays.push_back(&temp);
	}
	else{
		Card temp = Card(card->getSuit(), (Rank)(card->getRank()-1));
		possiblePlays.push_back(&temp);
		Card temp2 = Card(card->getSuit(), (Rank)(card->getRank() + 1));
		possiblePlays.push_back(&temp2);
	}
	for (int i = 0; i < possiblePlays.size(); i++){
		if (possiblePlays_.find(possiblePlays[i]) == possiblePlays_.end()){
			possiblePlays_.insert(possiblePlays[i]);
		}
		else{
			delete possiblePlays[i]; //gets rid of duplicates from memory
		}
		
	}
}