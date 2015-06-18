#include "Computer.h"
#include <iostream>
#include <vector>


Computer::Computer():Player() {} // Use player constructor to set score
Computer::Computer(Player* player) : Player(*player){}
void Computer::legalPlays(std::unordered_set <Card*> cards){
	if (cards.size() == 0){
		std::cout << "plays 7S.\n";
		for (int i = 0; i < hand_.size(); i++){
			if (*hand_[i] == Card(SPADE, SEVEN)){
				removeCard(*hand_[i]);
			}
			return;
		}
	}
	for (int i = 0; i < hand_.size(); i++){
		if (cards.find(hand_[i]) != cards.end()){
			std::cout << "plays " << hand_[i] << ".\n";
			removeCard(*hand_[i]);
			return;
		}
	}
	std::cout << "discards " << hand_[0] << ".\n";
	removeCard(*hand_[0]);
	return;
}