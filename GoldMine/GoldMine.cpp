#include <iostream>
#include <cstdlib>
using namespace std;
#include "GoldMine.h"
#include "Box.h"
GoldMine:: GoldMine(){
	return;
}
void GoldMine:: randomRowCol(int row, int column){
	setChar(6,6);
	
	for(int i=0; i<6;i++){
        	for(int j = 0; j<6;j++){
                	gm[i][j].setVisited(false);
                        gm[i][j].setGoldLost((rand()%(100-10 + 1) + 10));
                        gm[i][j].setCharacter('N');
                }
        }
         c1 = ((rand()%5));
         c2 = ((rand()%5));
         g1 = ((rand()%5));
	 g2 = ((rand()%5));
	while(g1 == c1 && g2 == c2){
		 g1 = ((rand()%5));
         	 g2 = ((rand()%5));
	}
          r1 = g2;
          r2 = g1;
         gm[c1][c2].setCharacter('C');
         gm[g1][g2].setCharacter('G');
         gm[r1][r2].setCharacter('R');
	return;
}
void GoldMine:: setMyBox(char c){
	
	return;
}
void GoldMine:: setRainbow(){
	setMyBox('R');
	return;
}
void GoldMine:: setGold(){
	setMyBox('G');
	return;
}
void GoldMine:: setCoal(){
	setMyBox('C');
	return;
}
string GoldMine:: rainbowMessage(){
	return "The gold can be found in the opposite quadrant as the rainbow";
}
void GoldMine:: revealSelection(int row, int col){
	 		if(gm[row][col].getVisited() == true){
                                cout<<"That point has already been revealed.\n";
                        }
                        else{
				cout<<endl<<"-----------------------"<<endl;
                                if(gm[row][col].getCharacter() != 'N'){
                                        if(gm[row][col].getCharacter() == 'C'){
                                                cout<< "You hit the coal!\n";
                                                gold = 0;
                                        }
                                        else if(gm[row][col].getCharacter() == 'R'){
                                                cout<< rainbowMessage() << endl;
                                                gold =gold -  gm[row][col].getGoldLost();
                                        }
                                        else{
                                                cout<< "You Struck gold, you win!!!\n";
                                                gold = gold + 1000000;
                                        }
                                }
                                else{
                                        gold = gold -  gm[row][col].getGoldLost();
                                        cout<< "You hit a normal box\n";
                                }
                                cout<< "You now have " << gold << " gold.\n";
                                if(gold <= 0 ){
                                        cout<< "You Lost =(\n";
                                }
			gm[row][col].setVisited(true);
                       	char norm = '-'; 
			if(gm[row][col].getCharacter() == 'R' || gm[row][col].getCharacter() == 'G' || gm[row][col].getCharacter() == 'C'){
				ch[row][col] = gm[row][col].getCharacter();
			}
			else{
				ch[row][col] = norm;
			}
			printGoldMine();
	}
	return;
}
void GoldMine:: printGoldMine(){
	cout<< "  0 1 2 3 4 5" << endl;
	for(int i = 0; i<6;i++){
		cout<< i;
		for(int j = 0; j<6; j++){
			cout<<" " << ch[i][j] ;
		}
		cout<< endl;
	}
		
	return;
}
int GoldMine:: getGold(){
	return gold;
}
void GoldMine:: setGold(int g){
	gold = g;
}
void GoldMine:: setChar(int x, int y){
	for(int i = 0; i<x ; i++){
		for(int j = 0; j<y; j++){
			ch[i][j] = '*';
		}
	}
	return;
}
void GoldMine:: printCheat(){
	cout<< "The gold is located at: " << g1 << ", " << g2 << endl;
	cout<< "The coal is located at: " << c1 << ", " << c2 << endl;
	cout<< "The rainbow is located at: " << r1 << ", " << r2 << endl;
	return;
}
