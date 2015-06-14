#include "Card.h"
#include <vector>

class Deck{
public:
	void shuffle();
	Deck(int);
	~Deck(); //delete Card pointers
	Card* getCard(int);
private:
	std::vector <Card*> cards_;
	static int seed;
};