#include "Deck.h"
#include <vector>

class Player{
public:
	bool contains(Suit, Rank) const;
	//default destructor is fine, deck will take care of deleting card*
	friend std::ostream &operator<<(std::ostream &, Player&);
	virtual Card* legalPlays(Card*) = 0;
	void removeCard(Card&);
	void discardHand();
	Card* findCard(Suit, Rank);
	void newHand(int, Deck);
protected:
	std::vector <Card*> hand_; //should only point to cards created by Deck
};

