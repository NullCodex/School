#ifndef _COMPUTER_
#define _COMPUTER_
#include "Player.h"
#include <unordered_set>

class Computer : public Player{
public:
	Computer();
	~Computer();
	Computer(Player*);
	void legalPlays(std::unordered_set <Card*>);
	void discardCard(Card&, Card*);
private:
};

#endif