/*
Matt Kline
11/4/17
This file contains all funtions that can be preformed on the deck of cards.
*/
#include <iostream>
#include <algorithm> 
#include <cstdlib>
using namespace std;
#include "Deck.h"
Deck::Deck(){
	MAX_CARDS = 60;
	drawPileIndex = 0;
	discardPileIndex = 0;
	discardPile[40];
	drawPile[MAX_CARDS];
	int x = 0;
	for(int i = 1 ; i< MAX_CARDS +1; i++){
		drawPile[x] = i;
		x++;
	}
	return;
}
//This will shuffle either the discard pile back into the pile or the just shuffle the draw pile depending on if its the start of the game
void Deck:: shuffle(){
	srand(time(0));
	if(drawPileIndex == (MAX_CARDS - 1)){
		random_shuffle(&discardPile[0],&discardPile[40]);
		int x = 20;
		for(int i = 0; i < 40; i++){
			drawPile[x] = discardPile[i];
			x++;
		}
		discardPile[0] = drawPile[20];
		discardPileIndex = 1;
		drawPileIndex = 21;
	}
	else{
		random_shuffle(&drawPile[0],&drawPile[MAX_CARDS]);
	}
}
//this will print the discarded card for the next player to pick from 
void Deck:: display(){
	cout<<"The card discared was : " <<  discardPile[discardPileIndex] << endl;
}
int Deck :: peekDiscard(){
	return discardPile[discardPileIndex];
}
//this is used when the player chooses to take the discarded card
int Deck:: getDiscard(){
	int x = discardPile[discardPileIndex];
	discardPileIndex++;
	return x;
}
//this is used to deal the cards and for the player to take the card from the normal pile
int Deck :: dealCard(){
	if(drawPileIndex == 59){
		shuffle();
	}
	int x = drawPile[drawPileIndex];
	drawPileIndex++;
	return x;
}
//This takes the card that the current player is discarding and puts it as the top of the discard pile
void Deck :: addCardToDiscard(int currentCard){
	discardPileIndex += 1;
	discardPile[discardPileIndex] = currentCard;
}
