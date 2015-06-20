#include "Player.h"
#include <algorithm>


Player::Player():score_(0){}
Player::~Player(){}

bool Player::contains(Suit s, Rank r) const{
	for (int i = 0; i < hand_.size(); i++){
		if (hand_[i]->getSuit() == s && hand_[i]->getRank() == r){
			return true;
		}
	}
	return false;
}

std::ostream &operator<<(std::ostream & sout, Player& p){
	for (int i = 0; i < p.hand_.size(); i++){
		sout << " " << *p.hand_[i];
	}
	return sout;
}

void Player::discardCard(Card* card){
	std::vector<Card *>::iterator it = std::find(hand_.begin(), hand_.end(), card);
	discarded_.push_back(*it);
	hand_.erase(it);
}

void Player::discardHand(){
	hand_.clear();
	discarded_.clear(); // assuming that we call this function at the end of the round
}

void Player::newHand(int number, Deck& d){
	for (int i = 0; i < 13; i++){
		hand_.push_back(d.getCard(i + (number * 13)));
	}
}

int Player::getScore() const
{
	return score_;
}

void Player::outputDiscardList() const {
	for (int i = 0; i < discarded_.size(); i++){
		std::cout << " " << *discarded_[i];
	}
	std::cout << std::endl;
}

int Player::valueOfDiscarded() const {
	int value = 0;
	for (int i = 0; i < discarded_.size(); i++){
		value += discarded_[i]->getRank() +  1;
	}
	return value;
}

void Player::updateScore(){
	score_ = getScore() + valueOfDiscarded();
}