// dungeon.h
// ross spicer
// 2013/05/1
//
// the dungeon class draws the dungeon and keeps triack is the 
// room has a monster or not
//
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
		
		//Dungeon::Dungeon()
		//  ctor that makes an empty room for the direction to be displayed
		Dungeon();
		
		// void	Dungeon::ChangeRoom(char	dir = 'n' ,int lvl)
		// 		this funcion cahnges the room to a random type of room
		//			with a random chance of monster
		//
		// pramaters:
		//			dir -- the room direction that is requested 
		//			lvl -- the players level
		bool 	ChangeRoom(char	dir ,int lvl);

		// killMonster()
		//	kill the monster
		void	killMonster()
				{_monsterAlive = false;}

		// occupied()
		//	is the room occupied
		bool	occupied()
				{return _monsterAlive;}
		
		// Monster& getMonster()
		// get the current monster as a monster reference
		Monster& getMonster()
				{
				return *_currMonster;		
				}

		// void	Dungeon::draw() 
		// 		the draw functon for the dungeon 
		void 	draw(); 

		
		// destructor
		~Dungeon(); 
	

	private:
		// doors
		bool		_doorF;
		bool		_doorL;
		bool		_doorR;

		// images
		gl::Texture _DungeonBG;
		gl::Texture _DungeonMonster;

		// monster
		Monster * _currMonster;
		bool	_monsterAlive; 
};



#endif
