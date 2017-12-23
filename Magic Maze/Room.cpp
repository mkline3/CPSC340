//Matt Kline
//Room.h methods built
#include<iostream>
using namespace std;
#include "Room.h"
Room::Room(){
	return;
}
void Room:: setReward(int x){
	Reward = x;
}
int Room:: getReward(){
	return Reward;
}
void Room:: setFirstName(string f){
	firstName = f;
}
string Room:: getFirstName(){
	return firstName;
}
void Room:: setLastName(string l){
	lastName = l;
}
string Room:: getLastName(){
	return lastName;
}
