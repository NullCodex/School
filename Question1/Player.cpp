#include "Player.h"
#include <algorithm>


Player::Player():score_(0){} // Player constructor sets the player score to 0
Player::~Player(){} // Player destructor 

// Function to check if a player has a certain card
bool Player::contains(Suit s, Rank r) const{
	for (int i = 0; i < hand_.size(); i++){
		if (hand_[i]->getSuit() == s && hand_[i]->getRank() == r){
			return true;
		}
	}
	return false;
}

// Overloaded ostream to print the hand
std::ostream &operator<<(std::ostream & sout, Player& p){
	for (int i = 0; i < p.hand_.size(); i++){
		sout << " " << *p.hand_[i];
	}
	return sout;
}

// Discard a card from the hand
void Player::discardCard(Card* card){
	std::vector<Card *>::iterator it = std::find(hand_.begin(), hand_.end(), card);
	discarded_.push_back(*it);
	hand_.erase(it);
}

// Wipe the player's hand
void Player::discardHand(){
	hand_.clear();
	discarded_.clear(); // assuming that we call this function at the end of the round
}

// Grab a new set of cards
void Player::newHand(int number, Deck& d){
	for (int i = 0; i < 13; i++){
		hand_.push_back(d.getCard(i + (number * 13)));
	}
}

// Returns the player score
int Player::getScore() const
{
	return score_;
}

// Prints the player's discarded list
void Player::outputDiscardList() const {
	for (int i = 0; i < discarded_.size(); i++){
		std::cout << " " << *discarded_[i];
	}
	std::cout << std::endl;
}

// Function to help tabulating the score, grabs the value of each discard
int Player::valueOfDiscarded() const {
	int value = 0;
	for (int i = 0; i < discarded_.size(); i++){
		value += discarded_[i]->getRank() +  1;
	}
	return value;
}

// Update the player's score
void Player::updateScore(){
	score_ = getScore() + valueOfDiscarded();
}
