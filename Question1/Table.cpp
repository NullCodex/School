#include "Table.h"
#include <string>

void Table::placeCard(Card* card){
	cardsOnTable_.push_back(card);
	if (card->getSuit() == CLUB){
		clubs_.insert(card->getRank() + 1); //this might not work
	}
	else if (card->getSuit() == SPADE){
		spades_.insert(card->getRank() + 1); //this might not work
	}
	else if (card->getSuit() == HEART){
		hearts_.insert(card->getRank() + 1); //this might not work
	}
	else{
		diamonds_.insert(card->getRank() + 1); //this might not work
	}
}

Card* Table::lastCardPlayed(){
	if (cardsOnTable_.size() == 0){
		return NULL;
	}
	return cardsOnTable_[cardsOnTable_.size() - 1];
}

void Table::clear(){
	cardsOnTable_.clear();
	hearts_.clear();
	diamonds_.clear();
	spades_.clear();
	clubs_.clear();
}

std::ostream &operator<<(std::ostream & sout, const Table& deck){
	sout << "Clubs:";
	for (std::set<int>::iterator it = deck.clubs_.begin(); it != deck.clubs_.end(); ++it){
		sout << " " << *it;
	}
	sout << "\n";
	sout << "Diamonds:";
	for (std::set<int>::iterator it = deck.diamonds_.begin(); it != deck.diamonds_.end(); ++it){
		sout << " " << *it;
	}
	sout << "\n";
	sout << "Hearts:";
	for (std::set<int>::iterator it = deck.hearts_.begin(); it != deck.hearts_.end(); ++it){
		sout << " " << *it;
	}
	sout << "\n";
	sout << "Spades:";
	for (std::set<int>::iterator it = deck.spades_.begin(); it != deck.spades_.end(); ++it){
		sout << " " << *it;
	}
	sout << "\n";
	return sout;
}