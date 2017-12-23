#ifndef BOX_H
#define BOX_H
#include <iostream>
class Box{
	public:
		Box();
		void setVisited(bool visited);
		bool getVisited() const;
		int getGoldLost() const;
		void setGoldLost(int amount);
		char getCharacter() const;
		void setCharacter(char special);
	private:
		char character;
		int goldLost;
		bool selected;
};
#endif
