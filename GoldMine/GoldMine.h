#ifndef GOLDMINE_H
#define GOLDMINE_H
#include "Box.h"
#include <cstdlib>
#include <iostream>
using namespace std;
class GoldMine{
	public:
		GoldMine();
		void randomRowCol(int row, int column);
		void setMyBox(char c);
		void setRainbow();
		void setGold();
		void setCoal();
		string rainbowMessage();
		void revealSelection(int row, int column);
		void printGoldMine();
		int getGold();
		void setGold(int gold);
		void setChar(int x, int y);
		void printCheat();	
	private:
		Box gm[6][6];
		char ch[6][6];
		int gold;
		int g1;
		int g2;
		int c1;
		int c2;
		int r1;
		int r2;
};
#endif
