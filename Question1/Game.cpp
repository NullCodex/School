#include "Game.h"
#include <iostream>
#include <typeinfo>
#include <set>

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
	possiblePlays_.clear();
	for (int i = 0; i < players_.size(); i++){
		players_[i]->discardHand();
		players_[i]->newHand(i, deck_);
	}
	determineFirstPlayer();
	std::cout << "A new round begins. It's player " << (firstPlayer_+1) << "'s turn to play." << std::endl;
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
		updatePossiblePlays();
		if (playerTypes_[curPlayer] == 'h'){
			Command c;
			outputCurrentTable();
			std::cout << "Your hand:" << *players_[curPlayer] << std::endl;
			std::cout << "Legal plays:";
			players_[curPlayer]->legalPlays(possiblePlays_);
			std::cout << "\n";
			c.type = DECK;
			while (c.type == DECK && !quit_){
				std::cout << ">";
				std::cin >> c;
				if (c.type == PLAY){
					try{
						Card* card = getCardReference(c.card);
						Human* human = dynamic_cast<Human*>(players_[curPlayer]);
						human->playCard(card, possiblePlays_);
						table_.placeCard(card);
					}
					catch (Human::InvalidCardException &e){
						std::cout << "This is not a legal play." << std::endl;
						c.type = DECK;
					}
				}
				else if (c.type == DISCARD){
					try{
						Card* card = getCardReference(c.card);
						Human* human = dynamic_cast<Human*>(players_[curPlayer]);
						human->discardCard(card, possiblePlays_);
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
				else{ //ragequit
					Human* temp = dynamic_cast<Human*>(players_[curPlayer]);
					players_[curPlayer] = new Computer(players_[curPlayer]);
					delete temp;
					std::cout << "Player " << (curPlayer + 1) << " ragequits. A computer will now take over." << std::endl;
					playerTypes_[curPlayer] = 'c';
					curPlayer--;
					// Want to make game a friend of both computer and human?
					// Need to transfer the ownership of cards to Computer.

				}
			}
		}
		else{
			//Do Computer player's turn
			Computer* computer = dynamic_cast<Computer*>(players_[curPlayer]);
			std::cout << "Player " << (curPlayer+1) << " ";
			players_[curPlayer]->legalPlays(possiblePlays_);
			Card* card = computer->getLastCardPlayed();
			if (card != NULL){
				table_.placeCard(card);
			}
			
		}
		curPlayer = (curPlayer + 1) % 4;
	}
}

Card* Game::getCardReference(Card card){
	Card* cardReference = NULL;
	for (int i = 0; i < 52; i++){
		if (*deck_.getCard(i) == card){
			cardReference = deck_.getCard(i);
			return cardReference;
		}
	}
	return cardReference;
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
	std::set<int> scores;
	for (int i = 0; i < players_.size(); i++){
		scores.insert(players_[i]->getScore());
	}
	for (int i = 0; i < players_.size(); i++){
		if (*scores.begin() == players_[i]->getScore()){
			std::cout << "Player " << (i + 1) << " wins!\n";
		}
	}
}

void Game::updatePossiblePlays(){
	Card* card = table_.lastCardPlayed();
	if (card==NULL){
		for (int i = 0; i < 52; i++){
			if (*deck_.getCard(i) == Card(SPADE, SEVEN)){
				possiblePlays_.insert(deck_.getCard(i));
				return;
			}
		}
	}
	std::vector <Card*> possiblePlays;
	for (int i = 0; i < 52; i++){
		if (deck_.getCard(i)->getRank() == card->getRank()){
			possiblePlays.push_back(deck_.getCard(i));
		}
		else if (deck_.getCard(i)->getSuit() == card->getSuit()){
			if (abs(deck_.getCard(i)->getRank() - card->getRank()) == 1){
				possiblePlays.push_back(deck_.getCard(i));
			}
		}
	}
	
	for (int i = 0; i < possiblePlays.size(); i++){
		possiblePlays_.insert(possiblePlays[i]);		
	}
}