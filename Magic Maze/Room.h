//Matt Kline
// Binary Maze
//12-4
#ifndef ROOM_H
#define ROOM_H
class Room{
	public:
		Room();
		void setReward(int x);
		int getReward();
		void setFirstName(string f);
		string getFirstName();
		void setLastName(string l);
		string getLastName();
	private:
		string firstName;
		string lastName;
		int Reward;
};

#endif
