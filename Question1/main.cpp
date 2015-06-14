#include "Deck.h"
#include "Card.h"
#include "Command.h"
#include "Player.h"
#include "Human.h"
#include "Computer.h"
#include "Table.h"
#include <vector>
#include <iostream>
using namespace std;
int main(int argc, char* argv){
	vector <Player> players;
	vector <char> inputs;
	Table table;
	int seed;
	int playerTurn;
	if (argc > 0){
		seed = argv[1];
	}
	Deck deck(seed);
	for (int i = 0; i < 4; i++){
		cout << "Is player " << (i+1) << " a human (h) or a computer (c)?" << endl;
		char temp;
		cin >> temp;
		inputs.push_back(temp);
	}
	for (int i = 0; i < inputs.size(); i++){
		if (inputs[i] == 'h'){
			players.push_back(Human(i, deck));
		}
		else{
			players.push_back(Computer(i, deck));
		}
	}
	for (int i = 0; i < players.size(); i++){
		if (players[i].contains(SPADE, SEVEN)){
			playerTurn = i;
			break;
		}
	}
	while (true){
		if (inputs[playerTurn] == 'h'){
			cout << "Cards on the table:\n";
			cout << "Clubs: " << /*cards on table*/ "\n";
			cout << "Diamonds: " << /*cards on table*/ "\n";
			cout << "Hearts: " << /*cards on table*/ "\n";
			cout << "Spades: " << /*cards on table*/ "\n";
			cout << "Your hand: " << players[playerTurn] << endl;
			cout << "Legal plays: ";
			players[playerTurn].legalPlays(table.lastCardPlayed());
			cout << "\n";
		}
		else{
			//Computer does its stuff
		}
	}
}