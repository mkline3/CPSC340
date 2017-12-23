//Matt Kline
//Girl.h file
//12-4
#ifndef GIRL_H
#define GIRL_H
#include "Room.h"
class Girl{
	public:
		Girl();
		int getRoomCount();
		int getElfRoomCount();
		int getWizRoomCount();
		int getGold(){return gold;}
		int getMonRoomCount();
		void Reward(int g);
		void girlStatus();
		bool GameOver();
		void nextMove(string dir, Room room);
	private:
		int roomCount;
		int elfCount;
		int wizCount;
		int monCount;
		int gold;
};
#endif
