#include "Player.h"

class Human : public Player{
public:
	Human(int, Deck);
	void action();
	void legalPlays(Card*) const;
private:

};