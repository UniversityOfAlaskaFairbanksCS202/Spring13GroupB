// dungeon.h
// ross spicer
//
// ver 1: contains the declerations of stuff that will likely be needed for the 
// dungeon class
#ifndef DUNGEON_HEADER_FILE
#define DUNGEON_HEADER_FILE

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"

#include "Resources.h"

using namespace std;
using namespace ci;

// #include "Monster.h"





class Dungeon{
	public:
		enum moveDir{FOWARD,BACK,LEFT,RIGHT,BOSS};
		
		//Dungeon()// build the rooms
		
		void 	ChangeRoom(char	dir );// change the currRoom, and currMonster
		void	killMonster();
		
		void 	draw(); // draw the room and monster if any
		void 	update();
		
		bool	isFront(){return _doorF;}
		bool	isLeft(){return _doorL;}
		bool	isRight(){return _doorR;}

		~Dungeon(); 
	private:

	
		bool		_doorF;
		bool		_doorL;
		bool		_doorR;

		gl::Texture _DungeonBG;

//		Monster* _currMonster;
};



#endif