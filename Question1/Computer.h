#include "Player.h"

class Computer : public Player{
public:
	Computer();
	~Computer();
	Card* legalPlays(Card*);
private:
};