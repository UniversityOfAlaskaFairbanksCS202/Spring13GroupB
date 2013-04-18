#include "Messenger.h"
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
};

void cs_202ProjectApp::setup()
{
	_theDungeon.ChangeRoom('n');
}

void cs_202ProjectApp::keyDown( KeyEvent event )
{
	//_theDungeon.ChangeRoom(event.getChar()); 
	_theUI.keyDown(event.getChar() , _theDungeon);
}

void cs_202ProjectApp::update()
{
}

void cs_202ProjectApp::draw()
{
	// clear out the window with black
	//gl::clear( Color( 0, 0, 0 ) );
	_theDungeon.draw();
	_msgEngine.draw();
}

CINDER_APP_BASIC( cs_202ProjectApp, RendererGl )
