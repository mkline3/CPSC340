/*
Matt Kline 
11/5/17
This file contains all functions for the controlls that can occur in a game
*/
#include <iostream>
using namespace std;
#include "gameController.h"
#include "Deck.h"
#include "linked_list.h"
gameController:: gameController(){
	return;
}
//displays the rules of the game
void gameController:: displayMenu(){
	string rules = "Welcome to the game of Racko. \nYou and your opponnent are each dealt 10 cards that are stuck in that order. \nYour goal is to get your cards in order from smallest to the largest. \nYou have the choice to pick a card from a pile that you can't seeor you can take the card at the top of the discard pile that everyone sees. \nYou use the card you picked to insert in place of one of the cards that you already have in your hand to make it better. \nYou also have the choice to discard the card you picked up. \nThe deck consists of cards from 1 - 60 \nGood luck!\n";
	cout << rules << endl;
}
//This will check to see if a hand is won or not
bool gameController:: check_racko(linked_list<int> Rack){
	return Rack.isListSorted();
}
//this will deal the hands to both players
void gameController:: deal_initial_hands(){
	int i = 0;
	int x = 0;
	while(i<20){
		humanRack.InsertLast(gameDeck.dealCard());
		AI[x] = gameDeck.dealCard();
		AIRack.InsertFirst(AI[x]);
		i = i+2;
		x++;
	}
	gameDeck.addCardToDiscard(gameDeck.dealCard());
}
//this will print the order of the hand
void gameController:: print_top_to_bottom(linked_list<int> Rack){
	cout<< "The rack looks like : \n";
	Rack.printReverse();
}
//this will replace the cards the player wants
bool gameController:: findAndReplace(int newCard, int cardToReplace, linked_list<int> Rack){
	bool x = Rack.replace(cardToReplace,newCard);
	if(x){
		gameDeck.addCardToDiscard(cardToReplace);
	}
	return x;
}
//This is how the CPU will play the game
void gameController:: AITurn(){
	bool turn = false;
	int discard = gameDeck.getDiscard();
/*	cout<< ">55 : " << (discard > 50) << endl;
	cout << "55-50: " << (discard < 56 && discard > 50) << endl;
	cout << "50-45: " << (discard < 51 && discard > 45)<< endl;
	cout << "45-40: " << (discard < 46 && discard > 40) << endl;
        cout << "40-35: " << (discard < 41 && discard > 35)<< endl;
	cout << "35-30: " << (discard < 36 && discard > 30) << endl;
        cout << "30-25: " << (discard < 31 && discard > 25)<< endl;
	cout<< "test: " << (!(AI[3] < 31) && !(AI[3] >25)) << endl;
	for(int i = 0; i < 10 ; i++){
		cout<< i+1<< " : " <<AI[i] << endl;
	}*/
//	cout<< !(AI[9]<55)<< endl;
		if(discard > 55){
			if(!(AI[9] > 55)){
				AIRack.replace(AI[9], discard);
                                turn = true;
                                gameDeck.addCardToDiscard(AI[9]);
                                AI[9] = discard;
			}
		}
		if(discard < 56 && discard > 50){
			if(!(AI[8] < 56) || !(AI[8] >50)){
				AIRack.replace(AI[8], discard);
                                turn = true;
                                gameDeck.addCardToDiscard(AI[8]);
                                AI[8] = discard;
                                
			}
		}
		if(discard > 45 && discard < 51){
                        if(!(AI[7] < 51) || !(AI[7] >45)){
                                AIRack.replace(AI[7], discard);
                                turn = true;
                                gameDeck.addCardToDiscard(AI[7]);
                                AI[7] = discard;
                                
                        }
		}
		 if(discard > 40 && discard < 46){
                        if(!(AI[6] < 46) || !(AI[6] >40)){
                                AIRack.replace(AI[6], discard);
                                turn = true;
                                gameDeck.addCardToDiscard(AI[6]);
                                AI[6] = discard;
                     //           break;
                        }
		}
		if(discard > 35 && discard < 41){
                        if(!(AI[5] < 41) || !(AI[5] >35)){
                                AIRack.replace(AI[5], discard);
                                turn = true;
                                gameDeck.addCardToDiscard(AI[5]);
                                AI[5] = discard;
                //                break;
                        }
 		}
		if(discard > 30 && discard < 36){
                        if(!(AI[4] < 36) || !(AI[4] >30)){
                                AIRack.replace(AI[4], discard);
                                turn = true;
                                gameDeck.addCardToDiscard(AI[4]);
                                AI[4] = discard;
                //                break;
                        }
		}
		if(discard > 25 && discard < 31){
                        if(!(AI[3] < 31) || !(AI[3] >25)){
                                AIRack.replace(AI[3], discard);
                                turn = true;
                                gameDeck.addCardToDiscard(AI[3]);
                                AI[3] = discard;
                 //               break;
                        }
		}
		if(discard > 20 && discard <26){
                        if(!(AI[2] < 26) || !(AI[2] >20)){
                                AIRack.replace(AI[2], discard);
                                turn = true;
                                gameDeck.addCardToDiscard(AI[2]);
                                AI[2] = discard;
                //                break;
                        }
		}
		if(discard > 10 && discard < 21){
                        if(!(AI[1] < 21) || !(AI[1] >10) ){
                                AIRack.replace(AI[1], discard);
                                turn = true;
                                gameDeck.addCardToDiscard(AI[1]);
                                AI[1] = discard;
                //                break;
                        }
		}
		if(discard < 11 ){
			if(!(AI[0] < 11) || !(AI[0] >0) ){
                                AIRack.replace(AI[0], discard);
                                turn = true;
                                gameDeck.addCardToDiscard(AI[0]);
                                AI[0] = discard;
                //                break;
                        }
		}
         
	if(!turn){
		 discard = gameDeck.dealCard();
		
            	if(discard > 55){
                        if(!(AI[9] > 55)){
                                AIRack.replace(AI[9], discard);
                                turn = true;
                                gameDeck.addCardToDiscard(AI[9]);
                                AI[9] = discard;
                  //              break;
                        }
                }
		if(discard > 50 && discard < 56){
                        if(!(AI[8] < 56) || !(AI[8] >50)){
                                AIRack.replace(AI[8], discard);
                                turn = true;
                                gameDeck.addCardToDiscard(AI[8]);
                                AI[8] = discard;
                //                break;
                        }
                }
		if(discard > 45 && discard < 51){
                        if(!(AI[7] < 51) || !(AI[7] >45)){
                                AIRack.replace(AI[7], discard);
                                turn = true;
                                gameDeck.addCardToDiscard(AI[7]);
                                AI[7] = discard;
                //                break;
                        }
                }
		if(discard > 40 && discard < 46){
                        if(!(AI[6] < 46) || !(AI[6] >40)){
                                AIRack.replace(AI[6], discard);
                                turn = true;
                                gameDeck.addCardToDiscard(AI[6]);
                                AI[6] = discard;
                //                break;
                        }
		}
		if(discard > 35 && discard < 41){
                        if(!(AI[5] < 41) || !(AI[5] >35)){
                                AIRack.replace(AI[5], discard);
                                turn = true;
                                gameDeck.addCardToDiscard(AI[5]);
                                AI[5] = discard;
                 //               break;
                        }
                }
		if(discard > 30 && discard < 36 ){
                        if(!(AI[4] < 36) || !(AI[4] >30)){
                                AIRack.replace(AI[4], discard);
                                turn = true;
                                gameDeck.addCardToDiscard(AI[4]);
                                AI[4] = discard;
                //                break;
                        }
                }
		if(discard > 25 && discard < 31){
                        if(!(AI[3] < 31) || !(AI[3] >25)){
                                AIRack.replace(AI[3], discard);
                                turn = true;
                                gameDeck.addCardToDiscard(AI[3]);
                                AI[3] = discard;
                //                break;
                        }
                }
		if(discard > 20 && discard < 26){
                        if(!(AI[2] < 26) || !(AI[2] >20)){
                                AIRack.replace(AI[2], discard);
                                turn = true;
                                gameDeck.addCardToDiscard(AI[2]);
                                AI[2] = discard;
                //                break;
                        }
                }
	 	if(discard > 10 && discard < 21){
                        if(!(AI[1] < 21) || !(AI[1] >10)){
                                AIRack.replace(AI[1], discard);
                                turn = true;
                                gameDeck.addCardToDiscard(AI[1]);
                                AI[1] = discard;
                //                break;
                        }
                }
		if(discard < 11){
                        if(!(AI[0] < 11) || !(AI[0] >0)){
                                AIRack.replace(AI[0], discard);
                                turn = true;
                                gameDeck.addCardToDiscard(AI[0]);
                                AI[0] = discard;
                //                break;
                        }
                }	
	}
//	cout<< discard << endl;
	if(!turn){
		gameDeck.addCardToDiscard(discard);
	}
}
//This is how the game will determine if the game is over
void gameController :: playGame(){
//	gameDeck = new Deck();
        gameDeck.shuffle();
        displayMenu();
        deal_initial_hands();
        string card;
        string choice;
        int x;
        int y;
        int dis;
        bool turn;
        while(!(AIRack.isListSorted()) && !(humanRack.isListSorted())){
			cout<<"AI rack: \n";
			print_top_to_bottom(AIRack);
			cout<< "-----------------------------------------------------------------\n";
			cout<< "User rack: \n";
			print_top_to_bottom(humanRack);
                        turn = false;
                       // cout<< "The last carded discarded: \n";
                        gameDeck.display();
                        while(!turn){
                                cout<< "To take the discard enter d, to take a card from the deck type n: \n";
                                getline(cin, card);
				cout<< "You chose the option of: " << card << endl;
                                if(card == "n"){
                                        x = gameDeck.dealCard();
					cout << "You picked up : " << x<< endl;
                                        turn = true;
                                }
                                else if(card == "d"){
                                        x = gameDeck.getDiscard();
                                        turn = true;
                                }
                                else{
                                        cout<< "That was not a valid choice."<< endl;
                                }
                        }
                        turn = false;
                        int time = 0;
                        while(!turn){
				choice = " ";
				if(time> 0)
                                        cout<< "You gave an invalid card from your hand.\n";
                                if(card == "n"){
                                        cout<< "Would you like to discard the card you drew? (y/n)\n";
					getline(cin, choice);
                                }
                   //             if(time> 0)
                     //                   cout<< "You gave an invalid card from your hand.\n";
                                if(choice == "n"){
                                        cout<< "Which card would you like to replace? \n";
                                        cin>> y;
                                        turn = humanRack.replace(y,x);
                                        dis = y;
					cin.ignore();
					//cout << "You discarded: " << dis<< endl;
                                }
				else if(choice =="y"){
					dis = x;
					turn = true;
				}
				else if(card == "d"){
					cout<< "Which card would you like to replace? \n";
                                        cin>> y;
                                        turn = humanRack.replace(y,x);
                                        dis = y;
					cin.ignore();
					//cout << "You discarded: " << dis<< endl;
				}
                                //else{
                                  //      dis = x;
                               // }
                                time++;
                        }
			cout << "You discarded: " << dis<< endl;
                        gameDeck.addCardToDiscard(dis);
                        AITurn(); 
			cout<< "----------------------------------------------------------------\n";
	}
	if(humanRack.isListSorted() ){
		cout<< "You won\n";
	}
	else{
		cout<<"You lost \n";
	}
	return;
}
//linked_list<int> gameController :: getHumanRack(){
//	return humanRack;
//}
