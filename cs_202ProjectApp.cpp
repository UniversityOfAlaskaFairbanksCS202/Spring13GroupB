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

class cs_202ProjectApp : public AppBasic {
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

void cs_202ProjectApp::setup()
{
	Rand::randomize();
	_player = Player(_msgEngine);
	_theDungeon.ChangeRoom('n', 1);
	_uiMsg = UIMessenger(_player);
	_firstRun = true;
}

void cs_202ProjectApp::keyDown( KeyEvent event )
{
	
	_theUI.keyDown(event.getChar() , _theDungeon, _player, _splashScreen);
}

void cs_202ProjectApp::update()
{
	if(_firstRun)
	{
		_splashScreen.splashMessage("Welcome to the game!", 5, false);
		_firstRun = false;
	}
	_uiMsg.update();
}

void cs_202ProjectApp::draw()
{
	// clear out the window with black
	//gl::clear( Color( 0, 0, 0 ) );
	_theDungeon.draw();
	_msgEngine.draw();
	_uiMsg.draw();
	_splashScreen.draw();
}

CINDER_APP_BASIC( cs_202ProjectApp, RendererGl )