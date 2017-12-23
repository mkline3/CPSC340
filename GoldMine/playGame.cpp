#include <iostream>
#include <cstdlib>
using namespace std;
#include "Box.h"
#include "GoldMine.h"
int main(){
	string game;
	string n = "n";
	string row = "Enter a row: ";
	string col = "Enter a column: ";
	int r;
	int c;
	cout<< "Do you want to play the game(y/n): " << endl;
	getline(cin,game);
	while(game != n){
		GoldMine goldmine;
		goldmine.setGold(rand()%(9000-1000 + 1) + 1000);
		goldmine.randomRowCol(0,0);
		string cheat;
		cout<< "Do you want the cheat sheet(y/n):"<< endl;
		getline(cin,cheat);
		if(cheat != n){
			goldmine.printCheat();
		}	
		int gold = goldmine.getGold();
		goldmine.printGoldMine();
		while(gold>0 && gold<1000000){
			cout<< row<<endl;
			cin>>r;
			cout<<col<<endl;
			cin>>c;
			goldmine.revealSelection(r,c);
			gold = goldmine.getGold();
		}
			

	cin.ignore();
	cout<<"Do you want to play again(y/n): " << endl;
	getline(cin,game);
	} 
}
