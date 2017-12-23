/* Matt Kline
10-16-2017
Evil hangman
*/
//This file is the class definition for the hangman game
#ifndef HANGMAN_H
#define HANGMAN_H
class Hangman{
	public:
		Hangman(int numOfLetter, int numOfGuess, string dictionary[]);
		bool play(char guess);
		int getEvilWeighting(string *words, int size);
		int getNumOfGuess();
		bool gameOver();
		string showCurrentBoard();
		void addWordChoice(string word, string *wordChoiceList);
		int wordListSize();
		bool playerWon();
		string printGuessedChar();
		string getFinalAnswer();
		void printList();
	private:
		int numOfLetter;
		int numOfGuess;
		string *wordList;
		string *wordChoices;
		int sizeWordChoice;
		int sizeWordList;
		string output;
		string finalAnswer;
		string *guessed;
		int guessNum;
		int wasGuess;	
};
#endif
