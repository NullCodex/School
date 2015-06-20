#ifndef _TABLE_
#define _TABLE_
#include "Card.h"
#include <vector>
#include <set>

class Table{
public:
	friend std::ostream &operator<< (std::ostream &, const Table &);
	void placeCard(Card*); //add card to table
	Card* lastCardPlayed();
	void clear();
	std::vector <Card*> cardsOnTable();
private:
	std::vector <Card*> cardsOnTable_;
	std::set<int> clubs_;
	std::set<int> hearts_;
	std::set<int> spades_;
	std::set<int> diamonds_;
};

std::ostream &operator<<(std::ostream &, const Table &);

#endif