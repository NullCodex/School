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
using namespace std;
int main(int argc, char* argv){
	vector <char> inputs;
	Table table;
	int seed;
	int playerTurn;
	if (argc > 0){
		seed = argv[1];
	}
	for (int i = 0; i < 4; i++){
		cout << "Is player " << (i+1) << " a human (h) or a computer (c)?" << endl;
		char temp;
		cin >> temp;
		inputs.push_back(temp);
	}
	
	Game game(inputs, seed);
	
	while (true){ //GAME NOT DONE (call function that checks if a players score has reached 80 and hasn't quit
		game.newRound();
		//NEED TO DEAL WITH PLAYER QUITTING
		while (true){ //ROUND NOT DONE (do for loop 13 times? do for loop HAND_SIZE times? (using a constant var)) 
			game.nextTurn();
		}
		//update scores if player hasnt quit

	}
}