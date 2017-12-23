/*
Matt Kline
11/06/17
This is the main file that will run the game 
*/
#include <iostream>
using namespace std;
#include "linked_list.h"
#include "Deck.h"
#include "gameController.h"
#include "single_node.h"
int main(){
	string q;
	bool play = true;
	while(play){
		gameController g;
		g.playGame();
/*		Deck d = new Deck();
		d.shuffle();
		gameController g = new gameController(d);
		g.displayMenu();
		g.deal_initial_hands();
		//gameController g = new gameController(&d);
		string card;
		string choice;
		int x;
		int y;
		int dis;
		bool turn;
		while(!g.playGame()){
			turn = false;
			cout<< "The last carded discarded: \n";
			d.display();
			while(!turn){
				cout<< "To take the discard enter d, to take a card form the deck type n: \n";
				getline(cin, card);
				if(card == "n"){
					x = d.dealCard();
					turn = true;
				}
				else if(card == "d"){
					x = d.getDiscard();
					turn = true;
				}
				else{
					cout<< "That was not a valid choice."<< endl;
				}
			}
			//ListNode<NODETYPE> *temp1 = new ListNode<NODETYPE>;
			//ListNode<NODETYPE> *temp2 = new ListNode<NODETYPE>;
			//temp1->data = x;
			turn = false;
			int time = 0;
			while(!turn){
				if(card == "n"){
					cout<< "Would you like to discard the card you drew? (y/n)\n";
					getline(cin, choice);
				}
				if(time> 0)
					cout<< "You gave an invalid card from your hand.\n";
				if(choice == "n"){
					cout<< "Which card would you like to replace? \n";
					cin>> y;
					turn = g.findAndReplace(x,y, g.getHumanRack());
					dis = y;
				}
				else{
					dis = x;
				}
				time++;
			}
			d.addCardToDiscard(dis);
			g.AITurn();
		}*/

		cout<< "Do you want to play again?(y/n)" << endl;
		getline(cin, q);
		if(q == "y"){
			play = true;
		}
		else{
			play = false;
		}
	}
	cout<< "Good Bye!" << endl;
	return 0;
}
