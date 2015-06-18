#include "Deck.h"


Deck::Deck(int seed){
	seed_ = seed;
	for (int i = 0; i < 52; i++){
		cards_.push_back(new Card(Suit(i/13), Rank(i%13)));
	}
}

Deck::~Deck(){
	for (int i = 0; i < cards_.size(); i++){
		delete cards_[i];
	}
}
void Deck::shuffle(){
	static std::mt19937 rng (seed_);
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

std::ostream &operator<< (std::ostream & sout, const Deck & deck){
	int i = 0;
	sout << *deck.cards_[i];
	for (i = 1; i < deck.cards_.size(); i++){
		if (i % 13 == 0){
			sout << "\n";
			sout << *deck.cards_[i];
		}
		else{
			sout << " " << *deck.cards_[i];
		}
	}
	return sout;
}