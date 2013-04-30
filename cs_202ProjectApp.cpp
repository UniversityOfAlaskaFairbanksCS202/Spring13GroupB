#include "Messenger.h"
#include "UIMessenger.h"
#include "ImportantMessage.h"
#include "Player.h"
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "dungeon.h"
#include "ui.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class DungeonOfEvil : public AppBasic {
	public:
	void setup();
	void keyDown( KeyEvent event );	
	void update();
	void draw();
	
	private:
		Dungeon _theDungeon;
		UI		_theUI;
		Messenger _msgEngine;
		UIMessenger _uiMsg;
		Player _player;
		ImportantMessage _splashScreen;
		bool _firstRun;
};

void DungeonOfEvil::setup()
{
	Rand::randomize();
	_player = Player(_msgEngine);
	_theDungeon = Dungeon();
	_uiMsg = UIMessenger(_player);
	_firstRun = true;
}

void DungeonOfEvil::keyDown( KeyEvent event )
{
	
	_theUI.keyDown(event.getChar() , _theDungeon, _player, _splashScreen);
}

void DungeonOfEvil::update()
{
	if(_firstRun)
	{
		_splashScreen.splashMessage("Welcome to the game!\n\rPress A, W, D to move.", 5, false);
		_firstRun = false;
	}
	_uiMsg.update();
}

void DungeonOfEvil::draw()
{
	// clear out the window with black
	//gl::clear( Color( 0, 0, 0 ) );
	_theDungeon.draw();
	_msgEngine.draw();
	_uiMsg.draw();
	_splashScreen.draw();
}

CINDER_APP_BASIC( DungeonOfEvil, RendererGl )