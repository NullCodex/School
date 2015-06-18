#ifndef _HUMAN_
#define _HUMAN_
#include "Player.h"
#include <unordered_set>

class Human : public Player{
public:
	class InvalidCardException{
	public:
		InvalidCardException(Card* card) : card_(*card){}
		Card card() const{ return card_; }
	private:
		Card card_;
	};
	class CanPlayCardException{
	public:
		CanPlayCardException(Card* card) : card_(*card){}
		Card card() const{ return card_; }
	private:
		Card card_;
	};
	Human();
	~Human();
	void legalPlays(std::unordered_set <Card*>);
	void discardCard(Card*, std::unordered_set<Card*>);
	void playCard(Card*, std::unordered_set<Card*>);
private:

};

#endif