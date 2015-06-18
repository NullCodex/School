#include "Computer.h"
#include <iostream>
#include <vector>
#include <algorithm>


Computer::Computer():Player() {} // Use player constructor to set score
Computer::Computer(Player* player) : Player(*player){}
void Computer::legalPlays(std::unordered_set <Card*> cards){
	if (cards.size() == 1){
		std::cout << "plays 7S.\n";
		for (int i = 0; i < hand_.size(); i++){
			if (*hand_[i] == Card(SPADE, SEVEN)){
				lastCardPlayed_ = hand_[i];
				playCard(hand_[i]);
				return;
			}
			
		}
	}
	for (int i = 0; i < hand_.size(); i++){
		if (cards.find(hand_[i]) != cards.end()){
			std::cout << "plays " << *hand_[i] << ".\n";
			lastCardPlayed_ = hand_[i];
			playCard(hand_[i]);
			return;
		}
	}
	std::cout << "discards " << *hand_[0] << ".\n";
	discardCard(hand_[0]);
	return;
}

Card* Computer::getLastCardPlayed(){
	Card* temp = lastCardPlayed_;
	lastCardPlayed_ = NULL;
	return temp;
}

void Computer::playCard(Card* card){
	std::vector<Card *>::iterator it = std::find(hand_.begin(), hand_.end(), card);
	hand_.erase(it);
}