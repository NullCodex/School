#include "Deck.h"
#include <vector>
#include <iostream>

class Player{
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
	Player(); // Use player's constructor to set score
	~Player();
	bool contains(Suit, Rank) const;
	//default destructor is fine, deck will take care of deleting card*
	friend std::ostream &operator<<(std::ostream &, Player&);
	virtual void legalPlays(Card*) = 0;
	void discardCard(Card&, Card*);
	void removeCard(Card&);
	void playCard(Card, Card*);
	bool isLegalPlay(Card, Card*); //Check if the card being played is a valid play given the top card on the table
	void outputDiscardList() const;
	void discardHand();
	Card* findCard(Suit, Rank);
	void newHand(int, Deck);
	int getScore() const; // Return the score
	int valueOfDiscarded() const;
	void updateScore();
protected:
	std::vector <Card*> hand_; //should only point to cards created by Deck
	int score_; // Each player should have a score variable to keep track of the current scoring
	std::vector <Card*> discarded_;
};

