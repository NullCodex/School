#include "Human.h"
#include <iostream>
#include <math.h>

Human::Human(int number, Deck d){
	for (int i = 0; i < 13; i++){
		hand_.push_back(d.getCard(i + (number * 13)));
	}
}

void Human::legalPlays(Card* card) const{
	bool printed = false;
	if (card == NULL){
		std::cout << "7S";
		return;
	}
	for (int i = 0; i < hand_.size(); i++){
		if (card->getRank() == hand_[i]->getRank()){
			if (!printed){
				printed = true;
				std::cout << " ";
			}
			std::cout << hand_[i];
		}
		else if (card->getSuit() == hand_[i]->getSuit()){
			if (abs(card->getRank() - hand_[i]->getRank()) == 1){
				if (!printed){
					printed = true;
					std::cout << " ";
				}
				std::cout << hand_[i];
			}
		}
	}
}