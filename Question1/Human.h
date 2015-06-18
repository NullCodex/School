#ifndef _HUMAN_
#define _HUMAN_
#include "Player.h"

class Human : public Player{
public:
	class InvalidCardException{
	public:
		InvalidCardException(Card card) : card_(card){}
		Card card() const{ return card_; }
	private:
		Card card_;
	};
	class CanPlayCardException{
	public:
		CanPlayCardException(Card card) : card_(card){}
		Card card() const{ return card_; }
	private:
		Card card_;
	};
	Human();
	~Human();
	void action();
	void legalPlays(Card*);
	void discardCard(Card&, Card*);
	void playCard(Card, Card*);
private:

};

#endif