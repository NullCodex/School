#include "Table.h"

void Table::placeCard(Card* card){
	cardsOnTable_.push_back(card);
}

Card* Table::lastCardPlayed(){
	if (cardsOnTable_.size() == 0){
		return NULL;
	}
	return cardsOnTable_[cardsOnTable_.size() - 1];
}