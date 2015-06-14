#include "Player.h"

class Human : public Player{
public:
	Human();
	~Human();
	void action();
	Card* legalPlays(Card*);
private:

};