#include "Player.h"

bool Player::contains(Suit s, Rank r){
	for (int i = 0; i < hand_.size(); i++){
		if (hand_[i]->getSuit() == s && hand_[i]->getRank() == r){
			return true;
		}
	}
	return false;
}

std::ostream &operator<<(std::ostream & sout, Player& p){
	for (int i = 0; i < p.hand_.size(); i++){
		sout << p.hand_[i];
		if (i != 12){
			sout << " ";
		}
	}
	return sout;
}