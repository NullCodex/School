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
	for (int i = 0; i < players_.size(); i++){
		if (typeid(players_[curPlayer]) == typeid(Human())){
			Command c;
			outputCurrentTable();
			
		}
	}
}

void Game::outputCurrentTable() const{
	std::cout << "Cards on the table:\n" << table_;
}