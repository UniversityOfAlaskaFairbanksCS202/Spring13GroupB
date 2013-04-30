#include "ImportantMessage.h"

ImportantMessage::ImportantMessage()
{
	_x = 40.0f/640;
	_y = 200.0f/480;
	_red = 1.0f;
	_green = 1.0f;
	_blue = 0.0f;
	_size = 40.0f/480;
	_msg = "";
}

void ImportantMessage::splashMessage(string msg, int waitTime, bool quitGame)
{
	_msg = msg;
	_waitTime = waitTime;
	_quitGame = quitGame;
	_startTime = static_cast<int>(getElapsedSeconds());
}

void ImportantMessage::draw()
{
	if (_msg != "")
	{	
		TextLayout msgBox;
		gl::Texture msgTexture;
		

		msgBox.clear(ColorA(0.0f,0.0f,0.0f,0.0f));
		msgBox.setColor(Color(_red,_green,_blue)); 
		msgBox.setFont(Font("Courier New",getWindowHeight()*_size));

		msgBox.addLine(_msg);

		msgTexture = msgBox.render(true,false);

		gl::draw(msgTexture,Vec2f(getWindowWidth()*_x, getWindowHeight()*_y));

		if ((static_cast<int>(getElapsedSeconds()) - _startTime) > _waitTime)
		{
			_msg = "";
			if (_quitGame)
				exit(0);
		}
	}
}