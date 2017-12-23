/* Matthew Kline
	EvilHangman main
	10/20/17
*/

#include <iostream>
#include <fstream>
#include <string>
#include <array>
using namespace std;
#include "Hangman.h"

//this is the main part of the program that will read in the file and interact with what the user wants to do
int main(){
	bool nums[100];
	for(int i = 0 ; i< 100 ; i++){
		nums[i] = false;
	}
	string library[127142];
	ifstream file;
	file.open("dictionary.txt");
	if(!file.is_open()){
		cout << "Could not open file dictionary.txt." << endl;
      		return 1;
	}
	string word;
	int lib = 0;
	while(file >> word){
		library[lib] = word;
		nums[word.size()] = true;
		lib++;
		//cout << word << endl;
	}
//	file.close();
	bool playing = true;
	while(playing){
		int wordLength;
		int amount;
		cout<< "Enter length of word to guess: " << endl;
		cin >> wordLength;
		while(nums[wordLength] == false){
			cout << "You entered a wrong word length, try again : " << endl;
			cin>> wordLength;
		}
		cout<< "The word will have " << wordLength << " characters. " << endl;
		cout<< "Enter the amount of guesses you would like: " << endl;
		cin >> amount;
		while(amount <= 0){
			cout<< "You entered a number below 1, that means you can not guess any times, pick another amount: " << endl;
			cin>> amount;
		}
		bool testing = false;
		cin.ignore();
		string yes;
		cout<< "Would you like a running total of words left in the game?(y/n)"<< endl;
		getline(cin,yes);
		if(yes =="y")
			testing = true;
		Hangman hangman(wordLength, amount, library);
		bool first = true;
		char guesses[26];
		char curGuess {0};
		string Char;
		int count = 0;
		while(!hangman.gameOver()){
			if(testing){
				hangman.printList();
				cout << "The number of words that could be the answer at this time is " << hangman.wordListSize() << endl;
			}
			cout<< "You have " << hangman.getNumOfGuess() << " guesses left." << endl;
		//	if(!first){
				cout<< "You have guessed: " << hangman.printGuessedChar() << endl;
		//	}
		//	first = false;
			cout << "Your board looks like : " << hangman.showCurrentBoard() << endl;
			bool newG = true;
			cout<< "Enter a char guess: " << endl;
			getline(cin,Char);
			while(Char.length() > 1){
				cout<< "Invalid guess try again: " << endl;
				getline(cin,Char);
			}
			curGuess = Char[0];
			for(int c = 0; c< 26 ; c++){
				if(guesses[c] == curGuess){
					newG = false;
				}
			}
			while(!newG){
				newG = true;
				cout<< "You've already guessed that char. Enter a char guess: " << endl;
                       		 getline(cin,Char);
                       		 while(Char.length() > 1){
                        	        cout<< "Invalid guess try again: " << endl;
                        	        getline(cin,Char);
                       		 }
                        	curGuess = Char[0];
                  	      for(int c = 0; c< 26 ; c++){
                         	       if(guesses[c] == curGuess){
                                	        newG = false;
                         	       }
            			}
			
			}
			guesses[count] = curGuess;
			count++;
			hangman.play(curGuess);	
		}
		if(hangman.playerWon()){
			cout << "You win!" << endl<< hangman.showCurrentBoard()<< endl;
		}else{
			cout<< "You lost, \nthe word was : " << hangman.getFinalAnswer() << endl;
		}
		
		cout<< "Would you like to play again?(y/n)" << endl;
		getline(cin,yes);
		if(yes == "n")
			playing = false;
		for(int g = 0 ;  g< 26; g++){
			guesses[g] = ' ';
		}
	}
	file.close();
	return 0;
}
