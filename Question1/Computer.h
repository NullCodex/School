#include "Player.h"

class Computer : public Player{
public:
	Computer(int, Deck);
	void legalPlays(Card*) const;
private:
};