#include "Deck.h"
#include <random>


Deck::Deck(int seed_){
	seed = seed_;
	for (int i = 0; i < 52; i++){
		cards_[i] = new Card(Suit(i/4), Rank(i%13));
	}
}

Deck::~Deck(){
	for (int i = 0; i < cards_.size(); i++){
		delete cards_[i];
	}
}
void Deck::shuffle(){
	static std::mt19937 rng(seed);

	int n = Card::CARD_COUNT;

	while (n > 1) {
		int k = (int)(rng() % n);
		--n;
		Card *c = cards_[n];
		cards_[n] = cards_[k];
		cards_[k] = c;
	}
}

Card* Deck::getCard(int i){
	return cards_[i];
}
//set the value of seed