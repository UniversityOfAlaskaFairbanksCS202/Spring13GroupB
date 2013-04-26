#include "Messenger.h"
#include "UIMessenger.h"
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
};

void cs_202ProjectApp::setup()
{
	_player = Player(_msgEngine);
	_theDungeon.ChangeRoom('n');
	_uiMsg = UIMessenger(_player);
}

void cs_202ProjectApp::keyDown( KeyEvent event )
{
	_theDungeon.ChangeRoom(event.getChar()); 
	_theUI.keyDown(event.getChar() , _theDungeon);
}

void cs_202ProjectApp::update()
{
	_uiMsg.update();
}

void cs_202ProjectApp::draw()
{
	// clear out the window with black
	//gl::clear( Color( 0, 0, 0 ) );
	_theDungeon.draw();
	_msgEngine.draw();
	_uiMsg.draw();
}

CINDER_APP_BASIC( cs_202ProjectApp, RendererGl )