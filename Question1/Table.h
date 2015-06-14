#include "Card.h"
#include <vector>

class Table{
public:
	void placeCard(Card*); //add card to table
	Card* lastCardPlayed();
private:
	std::vector <Card*> cardsOnTable_;
};