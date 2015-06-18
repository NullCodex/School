#ifndef _DECK_
#define _DECK_
#include "Card.h"
#include <vector>
#include <random>
class Deck{
public:
	friend std::ostream &operator<< (std::ostream &, const Deck &);
	void shuffle();
	Deck(int);
	~Deck(); //delete Card pointers
	Card* getCard(int);
private:
	std::vector <Card*> cards_;
	int seed_;
};

std::ostream &operator<< (std::ostream &, const Deck &);

#endif