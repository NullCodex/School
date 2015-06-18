#include "Human.h"
#include <iostream>
#include <math.h>
#include <algorithm>

Human::Human():Player(){} 
Human::~Human(){}

void Human::legalPlays(std::unordered_set <Card*> cards){
	if (cards.size() == 0){
		std::cout << " 7S";
		return;
	}
	for (int i = 0; i < hand_.size(); i++){
		if (cards.find(hand_[i]) != cards.end()){
			std::cout << " " << *hand_[i];
		}
	}
}


void Human::discardCard(Card& card, std::unordered_set<Card*> cards){
	for (int i = 0; i < hand_.size(); i++){
		if (cards.find(&card) != cards.end()){
			throw CanPlayCardException(card);
		}
	}
	removeCard(card);
}

template <typename T>
struct pointer_values_equal
{
	const T* to_find;

	bool operator()(const T* other) const
	{
		return *to_find == *other;
	}
};

void Human::playCard(Card card, std::unordered_set<Card*> cards){
	if (!contains(card.getSuit(), card.getRank())){ //Card must be in your hand before you play it
		throw InvalidCardException(card);
	}
	//Check if the play is legal
	if (cards.find(&card) == cards.end()){
		throw InvalidCardException(card);
	}
	Card* to_find = new Card(card.getSuit(), card.getRank());
	pointer_values_equal<Card> eq = { to_find };
	std::vector<Card *>::iterator it = std::find_if(hand_.begin(), hand_.end(), eq);
	std::cout << "Iterator is pointing to " << **it << std::endl;
	hand_.erase(it); //remove card from hand
}