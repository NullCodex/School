#include "Player.h"

class Human : public Player{
public:
	Human();
	~Human();
	void action();
	void legalPlays(Card*);
private:

};