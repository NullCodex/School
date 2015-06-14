#include "Computer.h"

Computer::Computer(int number, Deck d){
	for (int i = 0; i < 13; i++){
		hand_.push_back(d.getCard(i + (number * 13)));
	}
}

void Computer::legalPlays(Card* card) const{
}