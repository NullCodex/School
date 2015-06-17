#include "Player.h"


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
		sout << p.hand_[i];
		if (i != 12){
			sout << " ";
		}
	}
	return sout;
}

void Player::removeCard(Card& card){
	std::vector<Card *>::iterator it = std::find(hand_.begin(), hand_.end(), card);
	discarded_.push_back(*it); // Not sure if the syntax work
	hand_.erase(it);
}

void Player::discardHand(){
	hand_.clear();
	discarded_.clear(); // assuming that we call this function at the end of the round
}

void Player::newHand(int number, Deck d){
	for (int i = 0; i < 13; i++){
		hand_.push_back(d.getCard(i + (number * 13)));
	}
}

int Player::getScore() const
{
	return score_;
}

int Player::roundScore() const // Grab the score for the currrent round
{
	int sum = 0;
	for(int i = 0; i < discarded_.size(); i++)
	{
		sum += discarded_[i]->getRank+1;
	}
	return sum;
}

void Player::playCard(Card card, Card* lastCard){
	if (!contains(card.getSuit(), card.getRank())){ //Card must be in your hand before you play it
		throw InvalidCardException(card);
	}
	//Check if the play is legal
	if (!isLegalPlay(card, lastCard)){
		throw InvalidCardException(card);
	}
	std::vector<Card *>::iterator it = std::find(hand_.begin(), hand_.end(), card);
	hand_.erase(it); //remove card from hand
	
}

bool Player::isLegalPlay(Card card, Card* lastCard){
	if (lastCard == NULL){
		if (card == Card(SPADE, SEVEN)){
			return true;
		}
		return false;
	}
	if (card.getRank() == lastCard->getRank()){
		return true;
	}
	else if (card.getSuit() == lastCard->getSuit()){
		if (abs(card.getRank() - lastCard->getRank()) == 1){
			return true;
		}
	}
	return false;
}


void Player::discardCard(Card& card, Card* lastCard){
	for (int i = 0; i < hand_.size(); i++){
		if (isLegalPlay(card, lastCard)){
			throw CanPlayCardException(card);
		}
	}
	removeCard(card);
}