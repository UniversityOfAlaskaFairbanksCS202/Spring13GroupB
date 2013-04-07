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

void	Dungeon::ChangeRoom(char	dir = 'n' )
{


	if ((('w' == dir) && !_doorF) || (('a' == dir) && !_doorL) || (('d' == dir) && !_doorR))
			{
			return;
			}
	
			
		
	
		_doorF = Rand::randBool(); // random if door or not
		_doorL = Rand::randBool(); // ""
		_doorR = Rand::randBool(); // ""
	

	

	if (_doorF && _doorL && _doorR)
		{
			_DungeonBG = gl::Texture( loadImage( loadResource(  ROOM_FLR ) ) );
		}
	else if (_doorF && _doorL) 
		{
			_DungeonBG = gl::Texture( loadImage( loadResource(  ROOM_FL_ ) ) );
		}
	else if (_doorF && _doorR) 
		{
			_DungeonBG = gl::Texture( loadImage( loadResource(  ROOM_F_R ) ) );
		}
	else if (_doorL && _doorR) 
		{
			_DungeonBG = gl::Texture( loadImage( loadResource(  ROOM__LR ) ) );
		}
	else if (_doorF) 
		{
			_DungeonBG = gl::Texture( loadImage( loadResource(  ROOM_F__ ) ) );
		}
	else if (_doorL) 
		{
			_DungeonBG = gl::Texture( loadImage( loadResource(  ROOM__L_ ) ) );
		}
	else if (_doorR) 
		{
			_DungeonBG = gl::Texture( loadImage( loadResource(  ROOM___R ) ) );
		}

	
}

void	Dungeon::draw() 
{
	gl::draw(_DungeonBG, getWindowBounds() );
}



Dungeon::~Dungeon()
{
	

}



