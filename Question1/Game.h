#ifndef _GAME_
#define _GAME_

#include <vector>
#include <unordered_set>
#include "Card.h"
#include "Deck.h"
#include "Computer.h"
#include "Human.h"
#include "Table.h"
#include "Command.h"

class Game{
public:
	Game(std::vector<char>, int);
	~Game();
	void newRound();
	void nextTurn();
	void outputCurrentTable() const;
	void currentScore() const;
	bool winnerExists() const;
	bool hasQuit() const;
	void endRound();
	void outputWinners() const;
	void updatePossiblePlays();
private:
	void determineFirstPlayer();
	int firstPlayer_;
	Deck deck_;
	std::vector <Player*> players_;
	std::vector <char> playerTypes_;
	std::unordered_set<Card *> possiblePlays_;
	Table table_;
	bool quit_;
};


#endif