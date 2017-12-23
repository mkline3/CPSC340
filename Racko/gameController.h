/* Matt Kline
   11/1/17
   This is the .h file for the gameController class of the Racko game
*/
#include "linked_list.h"
#include "Deck.h"
#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
class gameController{
	public:
		gameController();
		void displayMenu();
		void playGame();
		void AITurn();
		bool check_racko(linked_list<int> Rack);
		void deal_initial_hands();
		void print_top_to_bottom(linked_list<int> Rack);
		bool findAndReplace(int newCard, int cardToReplace, linked_list<int> Rack);
		linked_list<int> getHumanRack();
	private:
		linked_list<int> humanRack;
		linked_list<int> AIRack;
		bool playing;
		int AI[10];
		Deck gameDeck;
};





#endif
