/* Matt Kline
10-16-2017
Evil hangman
*/
//This class contains member funtions
#include <iostream>
#include <array>
#include <string>
using namespace std;
#include "Hangman.h"

//This function sets up the game with num of guesses and word size
Hangman:: Hangman(int letters, int guesses, string dictionary[]){
	numOfLetter = letters;
	numOfGuess = guesses;
	 int b = 0;
        for(int i = 0; i< 127142; i++){
                if(dictionary[i].size() == letters){
                        b++;
                }
        }
	wordList = new string[b];
	int a = 0;
	for(int i = 0; i< b; i++){
		if(dictionary[i].size() == letters){
			wordList[a] = dictionary[i];
			a++;
		}
	}
	output = "_";
	for(int i = 0; i< letters; i++){
		output = output + "_";
	}
	sizeWordList = a;	
	guessNum = guesses;
	wasGuess = guesses;
	guessed = new string[guesses + letters];	
}
bool Hangman:: play(char guess){
//	cout << "top\n";
/*	for(int i = 0; i < sizeWordList; i++){
		cout<< wordList[i]<< endl;
	} */
	int x = guessNum- wasGuess;
	wasGuess = wasGuess -1;
//	numOfGuess = numOfGuess-1;
	guessed[x] = guess;
	int most = 0;
	int test = 0;
	for(int i=0; i< numOfLetter; i++){
		int tester = 0;
		for(int j =0; j< sizeWordList; j++){
		//	cout<< "error in loop\n";
			if(wordList[j][i] == guess) //tests to see if the char at each spot of each word equals the guess to decide which is best choice
				tester++;
		}
		if(tester > test){
			test = tester;
			most = i;
		}
	}
	int test2 = 0; //double letters
	//int most2 = 0;
       //int tester = 0;
       for(int j =0; j< sizeWordList; j++){
                //      cout<< "error in loop\n";
                if(most != numOfLetter -1 && (wordList[j][most] == guess && wordList[j][most+1]==guess) ){ //tests to see if the char at each spot of each word equals the guess to decide which is best choice
                         test2++; // only adds words that have back to back char's
		//	cout<< j<< endl;
		}
			
       }
        
	int normal = 0;
	 for(int i=0; i< sizeWordList; i++){
                int tester = 0;
		if(wordList[i][most] == guess){
               		 for(int j =0; j< numOfLetter; j++){
                //      cout<< "error in loop\n";
                         	if(wordList[i][j] == guess) //tests to see if the char at each spot of each word equals the guess to decide which is best choice
                         		tester++;
                        
               		 }
		}
                if(tester == 1){
                       normal++;
                }
        }
//	cout<< "test: " << test << endl;
//	cout<< "Normal: " << normal << endl;
//	cout<< "test2: "<< test2 << endl;
//	for(int boy = 0 ; boy< sizeWordList; boy++){
//		cout<< wordList[boy] << endl;
//	} 
//	cout<< "error\n";
	if(test == 0 || (test2 == 0 && normal == 0)){
		numOfGuess = numOfGuess-1;
		return false;
	}
	else{
	  if(normal >= test2){
		wordChoices = new string[normal];
//		cout<< "error\n";
		int z = 0;
		for(int j =0; j< sizeWordList; j++){
			 if(wordList[j][most] == guess){
				int Extra = 0;
				for(int i = 0; i < numOfLetter; i++){
					if(wordList[j][i] == guess)
						Extra++;
					//cout<< "error in i\n";
				}
				
				if(Extra == 1){
					wordChoices[z] =wordList[j];
					//cout<< wordList[j] << endl;
 					z++;
//					cout<< "error " << z << endl;
				}
			}
			//cout<< "error in j\n";
		}
//		cout<< "error\n";
		output[most] = guess;
		sizeWordChoice = normal;
		sizeWordList = normal;
//		cout<< "error\n";
		delete [] wordList;
//		cout<< "error\n";
		wordList = new string[normal];
		for(int t = 0; t< normal; t++){
			wordList[t] = wordChoices[t];
		}
	  }
	  else{
		wordChoices = new string[test2];
        //      cout<< "error\n";
                int z = 0;
                for(int j =0; j< sizeWordList; j++){
                         if(wordList[j][most] == guess){
                              
                         	if(wordList[j][most +1] == guess){
                                	wordChoices[z] =wordList[j];
					z++;
				}
                        }
                }
                output[most] = guess;
		output[most +1] = guess;
                sizeWordChoice = test2;
                sizeWordList = test2;
                delete [] wordList;
        //      int check2 = 0;
                wordList = new string[test2];
                for(int t = 0; t< test2; t++){
                        wordList[t] = wordChoices[t];
                }

	  }
//		cout<<sizeWordChoice << endl;

		delete [] wordChoices;
//		cout<< sizeWordList << endl;
		return true;
	}
}
int Hangman:: getNumOfGuess(){
	return numOfGuess;
}
bool Hangman:: gameOver(){
	int found = 0;
	for(int i = 0; i < numOfLetter; i++){
		if(output[i] == '_'){
			found++;
		}
	}
	if(numOfGuess == 0)
		return true;
	else if(found == 0)//checks for number where element would be found (should be none for this to be true)
		return true;
	else
		return false;
}
int Hangman:: wordListSize(){
	return sizeWordList;
}
bool Hangman:: playerWon(){
	   int found = 0;
        for(int i = 0; i < numOfLetter; i++){
                if(output[i] == '_'){
                        found++;
                }
        }
	if(found == 0 && guessNum > 0 )
		return true;
	else
		return false;
}
string Hangman:: printGuessedChar(){
	int x = guessNum - numOfGuess;
	string guesses = "";
	for(int i = 0; i < x; i++){
			guesses = guesses + guessed[i] + " ";
	}
	return guesses;
}
string Hangman:: getFinalAnswer(){
	finalAnswer = wordList[0];
	   int found = 0;
        for(int i = 0; i < numOfLetter; i++){
                if(output[i] == '-'){
                        found++;
                }
        }
	if(numOfGuess == 0)
		return finalAnswer;
	else if(found == 0)
		return output;
	else
		return NULL;
}
string Hangman:: showCurrentBoard(){
	string x = "'[";
	for(int i = 0; i< numOfLetter; i++){
		if(i == numOfLetter - 1)
			x = x + output[i];
		else
			x = x + output[i] + ",";
	}
	x = x + "]'";
	return x;
}

void Hangman:: printList(){
	 for(int boy = 0 ; boy< sizeWordList; boy++){
              cout<< wordList[boy] << endl;
         }
}
