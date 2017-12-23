/*
Matt Kline
12/5
This is the main file that will run the game 
*/
#include <iostream>
using namespace std;
#include "Girl.h"
#include "Room.h"
#include "tree.h"
#include <fstream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <vector>
int main ( int argc, char *argv[] ){
/*	if ( argc != 2 ) 
		cout<<"usage: "<< argv[0] <<" <filename>\n";
	else {
		ifstream the_file ( argv[1] );
		if ( !the_file.is_open() )
      			cout<<"Could not open file\n";
		else{
			char x;
			while(the_file.get(x))
				cout<<x;
		}
	}
*/	bool play = true;
	bool first = true;
	string fileA;
	string READ;
	string s1;
	string s2;
	while(play){
		Girl myGirl;
		vector <Room> rooms;
		TreeType<string> r;
		srand(time(NULL));
		if(!first){
			cout<< "Enter a file name : " << endl;
			getline(cin,fileA);
			ifstream file(fileA.c_str());
			//file.open(fileA);
			if(!file.is_open()){
         		       cout << "Could not open file dictionary.txt." << endl;
                		return 1;
        		}
			int x = 0;
			//TreeType<string> r;
			while(file >> s1 >> s2){
			//	srand(time(NULL));
				Room room;
				if(x == 0){
					
					room.setFirstName(s1);
					myGirl.Reward(atoi(s2.c_str()));
					room.setReward(0);
				}
				else{
					room.setFirstName(s1);
        				room.setLastName(s2);
					//TreeType<Room> r;
        
                			room.setReward((rand() %25 +1));
        
				}
				r.Insert(s1);
				rooms.push_back(room);
				x++;

			}
		}

		else{
			ifstream the_file;
			the_file.open( argv[1] );
                	if ( !the_file.is_open() )
                        	cout<<"Could not open file\n";
			int x = 0;
                        //TreeType<string> r;
                        while(the_file >> s1 >> s2){
                                //srand(time(NULL));
                                Room room;
                                if(x == 0){
                                        
                                        room.setFirstName(s1);
                                        myGirl.Reward(atoi(s2.c_str()) );
                                        room.setReward(0);
                                }
                                else{
                                        
                                        room.setFirstName(s1);
                                        room.setLastName(s2);
                                        //TreeType<Room> r;

                                        room.setReward((rand() %25 +1));
				}
                                r.Insert(s1);
				rooms.push_back(room);
                                x++;

                        }			
		}
		string cur = "";
		string dir ="";
		Room current;
		r.setCurrentToRoot();
		cout<< "You are at the start of the maze\n Your goal is to reach a wizard\n If you hit to many monsters you will run out of gold \n ";
		while(!myGirl.GameOver()){
			myGirl.girlStatus();
			//cur = r.getCurrentData();
			cout<< "You have a door to your left and right.\n Which door do you want to take?(l/r)\n";
			getline(cin,dir);
			cout << "You chose to go " << dir << " and went through the door." << endl;
        		if(dir == "l"){
               		 	r.moveCurrentLeft();
       			}
        		else if(dir == "r"){
                		r.moveCurrentRight();
        		}
			cur = r.getCurrentData();
			for(int i = 0; i< rooms.size(); i++){
				if(rooms.at(i).getFirstName() == cur){
					current = rooms.at(i);
				}
			}
			myGirl.nextMove(dir, current);
			
		
		}
		cout<< "Ending stats: \n total rooms: "<< myGirl.getRoomCount() << "\n elf rooms: " << myGirl.getElfRoomCount() << "\n monster rooms: " << myGirl.getMonRoomCount() << "\n wizard rooms: " << myGirl.getWizRoomCount() << "\n Gold: " << myGirl.getGold() << endl; 
		string c= "";
		cout<< "Do you want to play again?(y/n) \n";
		getline(cin, c);
		if(c == "n"){
			play = false;
		} 
		else{
			first = false;
		}
	}		
	cout<< "GoodBye!";

	return 0;
}

