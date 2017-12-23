//Matt Kline
//File for girl class with methods
#include<iostream>
using namespace std;
#include "Girl.h"
#include "Room.h"
#include "tree.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
Girl::Girl(){
	gold =0;
	roomCount =0;
	elfCount =0;
	monCount = 0 ;
	wizCount =0;
	return;
} 
int Girl:: getRoomCount(){
	return roomCount;
}
int Girl:: getElfRoomCount(){
	return elfCount;
}
int Girl:: getMonRoomCount(){
	return monCount;
}
int Girl:: getWizRoomCount(){
	return wizCount;
}
void Girl:: Reward(int g){
	gold += g;
}
void Girl:: girlStatus(){
	cout<< "You have visited " << roomCount << " rooms."<< endl;
	cout<< "You have " << gold << " gold." << endl;
}
bool Girl:: GameOver(){
	if(gold <= 0 ){
		cout<< "You ran out of Gold\n";
		return true;	
	}
	else if(wizCount >= 1){
		cout<< "You won! \n";
		return true;
	}
	else{
		return false;
	}
}
void Girl:: nextMove(string dir, Room room){
/*	cout << "You chose to go " << dir << " and went through the door." << endl;
	if(dir == "l"){
		room.getFirstName().moveCurrentLeft();
	}
	else if(dir == "r"){
		room.getFirstName().moveCurrentRight();
	}
*/	if(room.getLastName() == "elf"){
		++roomCount;
		elfCount++;
		cout<< "You've encounterd " << room.getFirstName()<< " " << room.getLastName() << " he rewards you with " << room.getReward() << " Gold." << endl;
		gold = gold + room.getReward();
	}
	else if(room.getLastName() == "monster"){
		++roomCount;
		monCount++;
		cout<< "You've encounterd " << room.getFirstName() << " " << room.getLastName() << " he beats you up and takes " << room.getReward() << " Gold." << endl;
                gold = gold - room.getReward();
	}
	else{
		srand(time(NULL));
		++roomCount;
		wizCount++;
		int mul = rand() %5 +1;
		cout<< "You've encounterd " << room.getFirstName()<<" " << room.getLastName() << " he rewards you by multiplying your gold by "<< mul<< " plusa reward of " << room.getReward() << " Gold." << endl;
                gold = (mul*gold) + room.getReward();
	}
	
}


