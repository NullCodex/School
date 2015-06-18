#include "Computer.h"
#include <iostream>
#include <vector>

Computer::Computer():Player() {} // Use player constructor to set score
Computer::Computer(Player* player) : Player(*player){}
void Computer::legalPlays(Card* card){
	if (card == NULL){
		std::cout << "plays 7S.\n";
		for (int i = 0; i < hand_.size(); i++){
			if (*hand_[i] == Card(SPADE, SEVEN)){
				removeCard(*hand_[i]);
			}
			return;
		}
	}
	for (int i = 0; i < hand_.size(); i++){
		if (card->getRank() == hand_[i]->getRank()){
			std::cout << "plays " << hand_[i] << ".\n";
			removeCard(*hand_[i]);
			return;
		}
		else if (card->getSuit() == hand_[i]->getSuit()){
			if (abs(card->getRank() - hand_[i]->getRank()) == 1){
				std::cout << "plays " << hand_[i] << ".\n";
				removeCard(*hand_[i]);
				return;
			}
		}
	}
	std::cout << "discards " << hand_[0] << ".\n";
	removeCard(*hand_[0]);
	return;
}