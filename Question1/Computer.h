#ifndef _COMPUTER_
#define _COMPUTER_
#include "Player.h"

class Computer : public Player{
public:
	Computer();
	~Computer();
	Computer(Player*);
	void legalPlays(Card*);
	void discardCard(Card&, Card*);
private:
};

#endif