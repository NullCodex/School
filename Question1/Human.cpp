#include "Human.h"
#include <iostream>
#include <math.h>
#include <algorithm>

Human::Human():Player(){} 
Human::~Human(){}

void Human::legalPlays(Card* card){
	if (card == NULL){
		std::cout << " 7S";
		return;
	}
	for (int i = 0; i < hand_.size(); i++){
		if (isLegalPlay(*hand_[i], card)){
			std::cout << " " << *hand_[i];
		}
		
	}
}


void Human::discardCard(Card& card, Card* lastCard){
	for (int i = 0; i < hand_.size(); i++){
		if (isLegalPlay(card, lastCard)){
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

void Human::playCard(Card card, Card* lastCard){
	if (!contains(card.getSuit(), card.getRank())){ //Card must be in your hand before you play it
		throw InvalidCardException(card);
	}
	//Check if the play is legal
	if (!isLegalPlay(card, lastCard)){
		throw InvalidCardException(card);
	}
	Card* to_find = new Card(card.getSuit(), card.getRank());
	pointer_values_equal<Card> eq = { to_find };
	std::vector<Card *>::iterator it = std::find_if(hand_.begin(), hand_.end(), eq);
	hand_.erase(it); //remove card from hand

}