#include <iostream>
using namespace std;
#include "Box.h"
Box::Box(){
	return;
}
void Box:: setVisited(bool visited){
	selected = visited;
	return;
}
void Box:: setGoldLost(int amount){
	goldLost = amount;
	return;
}
void Box:: setCharacter(char special){
	character = special;
	return;
}
bool Box:: getVisited()const{
	return selected;
}
int Box:: getGoldLost()const{
	return goldLost;
}
char Box:: getCharacter()const{
	return character;
}

