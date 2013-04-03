// dungeon.h
// ross spicer
//
// ver 1: contains the declerations of stuff that will likely be needed for the 
// dungeon class
#ifndef DUNGEON_HEADER_FILE
#define DUNGEON_HEADER_FILE

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
using namespace std;
using namespace ci;

#include "Monster.h"



struct	Room{
// room 

	Room* doorF;
	Room* doorB;
	Room* doorL;
	Room* doorR;
	

};




class Dungeon{
	public:
		enum moveDir{FOWARD,BACK,LEFT,RIGHT,BOSS};
	
		Dungeon(); // build the rooms
		
		void 	ChangeRoom();// change the currRoom, and currMonster
		void	killMonster();
		
		void 	draw(); // draw the room and monster if any
		void 	update();
		
	private:
		
		Monster* _currMonster;
		Room* _currRoom;
		
	
};



#endif