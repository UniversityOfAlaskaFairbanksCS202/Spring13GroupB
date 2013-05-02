// dungeon.cpp
// ross spicer
// 2013/05/1
//
// the dungeon class draws the dungeon and keeps triack is the 
// room has a monster or not
//
#include "dungeon.h"
#include "cinder/Rand.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"


#include "cinder/app/AppBasic.h"
#include "Resources.h"

using namespace ci;
using namespace ci::app;
using namespace std;



//Dungeon::Dungeon()
//  ctor that makes an empty room for the direction to be displayed
Dungeon::Dungeon()
{
	// foward door
	_doorF = true;
	_doorL = false;
	_doorR = false;

	
	_DungeonBG = gl::Texture( loadImage(
						loadResource(  ROOM_F__ ) ) );
	// load a moster image just cause it might need an inital value
	_DungeonMonster = gl::Texture( loadImage(
						loadResource(  MONS___1 ) ) );
	//no monster
	_monsterAlive = false;
	_currMonster = NULL;
}//Dungeon::Dungeon()



// void	Dungeon::ChangeRoom(char	dir = 'n' ,int lvl)
// 		this funcion cahnges the room to a random type of room
//			with a random chance of monster
//
// pramaters:
//			dir -- the room direction that is requested 
//			lvl -- the players level
bool	Dungeon::ChangeRoom(char	dir = 'n',int lvl = 1 )
{

	// test to see if the door is avaible 
	if ((('w' == dir) && !_doorF) || (('a' == dir) && !_doorL) 
								  || (('d' == dir) && !_doorR))
			{
			// if not return
			return false;
			}
	
		// make sure all doors are not closed 
		do
			{
			// assign random doors
			_doorF = Rand::randBool(); // random if door or not
			_doorL = Rand::randBool(); // ""
			_doorR = Rand::randBool(); // ""
			}	while (!_doorF && !_doorL && !_doorR);

	// make sure the monster is dead
	killMonster();

	// delete old monster
	if (!_currMonster)
		{
			delete _currMonster;
		}
	
	// is there amonster
	if(Rand::randBool())
		{
			// make a monster up to players level
			_currMonster = new Monster(lvl - Rand::randInt(lvl-1)); 
			_DungeonMonster = _currMonster->getImage();
			_monsterAlive = true;
		}	

	// choose the proper room image
	if (_doorF && _doorL && _doorR) // all doors
		{
			_DungeonBG = gl::Texture( loadImage( 
							loadResource(  ROOM_FLR ) ) );
		}
	else if (_doorF && _doorL) // front and left door
		{
			_DungeonBG = gl::Texture( loadImage( 
							loadResource(  ROOM_FL_ ) ) );
		}
	else if (_doorF && _doorR) // front and right door
		{
			_DungeonBG = gl::Texture( loadImage( 
							loadResource(  ROOM_F_R ) ) );
		}
	else if (_doorL && _doorR) // left and right door
		{
			_DungeonBG = gl::Texture( loadImage( 
							loadResource(  ROOM__LR ) ) );
		}
	else if (_doorF) // front door
		{
			_DungeonBG = gl::Texture( loadImage( 
							loadResource(  ROOM_F__ ) ) );
		}
	else if (_doorL) // left door
		{
			_DungeonBG = gl::Texture( loadImage( 
							loadResource(  ROOM__L_ ) ) );
		}
	else if (_doorR) // right door
		{
			_DungeonBG = gl::Texture( loadImage( 
							loadResource(  ROOM___R ) ) );
		}

	return true;
	
}// end change room



// void	Dungeon::draw() 
// 		the draw functon for the dungeon 
void	Dungeon::draw() 
{
	gl::draw(_DungeonBG, getWindowBounds() );
	
	if (_monsterAlive)
	{
	gl::enableAlphaBlending();
	gl::draw(_DungeonMonster, getWindowBounds() );
	gl::disableAlphaBlending();
	}
} // end Dungeon::draw()



Dungeon::~Dungeon()
{
	if (!_currMonster)
		{
			delete _currMonster;
		}

}



