#include "Deck.h"
#include <vector>

class Player{
public:
	Player();
	bool contains(Suit, Rank);
	//default destructor is fine, deck will take care of deleting card*
	friend std::ostream &operator<<(std::ostream &, Player&);
	virtual void legalPlays(Card*) const = 0;
protected:
	std::vector <Card*> hand_; //should only point to cards created by Deck
};

