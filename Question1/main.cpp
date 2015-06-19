#include "Deck.h"
#include "Card.h"
#include "Command.h"
#include "Player.h"
#include "Human.h"
#include "Computer.h"
#include "Table.h"
#include "Game.h"
#include <vector>
#include <iostream>
#include <cstdlib> 
using namespace std;
int main(int argc, char *argv[]){
	vector <char> inputs;
	Table table;
	int seed=0;
	int playerTurn;
	if (argc > 1){
		seed = atoi(argv[1]);
	}
	for (int i = 0; i < 4; i++){
		cout << "Is player " << (i+1) << " a human(h) or a computer(c)?" << endl;
		char temp;
		std::cout << ">";
		cin >> temp;
		inputs.push_back(temp);
	}
	
	Game game(inputs, seed);
	
	while (!game.winnerExists() && !game.hasQuit()){ 
		game.newRound();
		for (int i = 0; i < 13 && !game.hasQuit(); i++){
			game.nextTurn();
		}
		if (!game.hasQuit()){
			game.endRound();
		}
	}
	if (!game.hasQuit()){
		game.outputWinners();
	}
}