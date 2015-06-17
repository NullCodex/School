#include "Player.h"

class Computer : public Player{
public:
	Computer();
	~Computer();
	void legalPlays(Card*);
	void discardCard(Card&, Card*);
private:
};