#include "dungeon.h"
#include "cinder/Rand.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"


#include "cinder/app/AppBasic.h"
#include "Resources.h"

using namespace ci;
using namespace ci::app;
using namespace std;



/*
Dungeon::Dungeon()
{
	_doorF = Rand::randBool(); // random if door or not
	_doorL = Rand::randBool();// ""
	_doorR = Rand::randBool();// ""

	_DungeonBG = gl::Texture( loadImage( loadResource(  ROOM_FLR ) ) );
	

	//_currMonster = new Monster;
}
*/



// void	Dungeon::ChangeRoom(char	dir = 'n' )
// 		this funcion cahnges the room to a random type of room
//
// pramaters:
//			dir -- the room direction that is requested 
void	Dungeon::ChangeRoom(char	dir = 'n' )
{

	// test to see if the door is avaible 
	if ((('w' == dir) && !_doorF) || (('a' == dir) && !_doorL) 
								  || (('d' == dir) && !_doorR))
			{
			// if not return
			return;
			}
	
			
		
		// assign random doors
		_doorF = Rand::randBool(); // random if door or not
		_doorL = Rand::randBool(); // ""
		_doorR = Rand::randBool(); // ""
	

	
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

	
}// end change room



// void	Dungeon::draw() 
// 		the draw functon for the dungeon 
void	Dungeon::draw() 
{
	gl::draw(_DungeonBG, getWindowBounds() );
} // end Dungeon::draw()



Dungeon::~Dungeon()
{
	

}



