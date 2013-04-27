// dungeon.h
// ross spicer
// 2013/04/11
//
// ver 1: contains the declerations of stuff that will likely be needed 
// for the dungeon class
//
// ver 2: got rid of the room class and intergrated it into the Dungeon 
// class
#ifndef DUNGEON_HEADER_FILE
#define DUNGEON_HEADER_FILE

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"

#include "Resources.h"
#include "Monster.h"

using namespace std;
using namespace ci;

// #include "Monster.h"





class Dungeon{
	public:
		enum moveDir{FOWARD,BACK,LEFT,RIGHT,BOSS};
		
		//Dungeon();// construct stuff
		
		void 	ChangeRoom(char	dir );// change the currRoom
									  // and currMonster
		void	killMonster()
				{_monsterAlive = false;}

		bool	occupied()
				{return _monsterAlive;}
		
		// void	Dungeon::draw() 
		// 		the draw functon for the dungeon 
		void 	draw(); 
		void 	update();
		

		~Dungeon(); 
	

	private:
		bool		_doorF;
		bool		_doorL;
		bool		_doorR;

		gl::Texture _DungeonBG;
		gl::Texture _DungeonMonster;
		Monster * _currMonster;
		bool	_monsterAlive; 
};



#endif
