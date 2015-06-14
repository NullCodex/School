#include "Card.h"
#include <vector>

class Deck{
public:
	friend std::ostream &operator<< (std::ostream &, const Deck &);
	void shuffle();
	Deck(int);
	~Deck(); //delete Card pointers
	Card* getCard(int);
private:
	std::vector <Card*> cards_;
	static int seed;
};

std::ostream &operator<< (std::ostream &, const Deck &);