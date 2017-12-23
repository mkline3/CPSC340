/* Matt Kline
   11/1/17
   This is the .h file for the Deck class of the Racko game
*/
#include "linked_list.h"
#ifndef DECK_H
#define DECK_H
class Deck{
	public:
		Deck();
		void shuffle();
		void display();
		int getDiscard();
		int dealCard();
		int peekDiscard();
		void addCardToDiscard(int currentCard);
	private:
		int MAX_CARDS;
		int drawPile[];
		int drawPileIndex;
		int discardPile[];
		int discardPileIndex;

};
#endif
