// John Cheshire / Group B
// Date: 03/31/2013
//
// The code in this file implements the Messenger class.

#include "Messenger.h"

void Messenger::newMessage(string newMsg)
{
	_row4 = _row3;
	_time4 = _time3;
	_row3 = _row2;
	_time3 = _time2;
	_row2 = _row1;
	_time2 = _time1;
	_row1 = newMsg;
	_time1 = static_cast<int>(getElapsedSeconds());
}

// This function draws the messages to screen.
void Messenger::draw() const
{
	// msgBox and msgTexture are created here
	// because they must be created after GDI+
	// is started as so cannot be member variables.
	TextLayout msgBox;
	gl::Texture msgTexture;

	msgBox.clear(ColorA(0.0f,0.0f,0.0f,0.0f));
	msgBox.setColor(Color(_red,_green,_blue)); 
	msgBox.setFont(Font("Courier New",getWindowHeight()*_size));

	if ((getElapsedSeconds() - _time1) < MESSAGE_FADE_TIME)
	{
		msgBox.addLine(_row1);
		if ((getElapsedSeconds() - _time2) < MESSAGE_FADE_TIME)	
		{
			msgBox.addLine(_row2);
			if ((getElapsedSeconds() - _time3) < MESSAGE_FADE_TIME)	
			{
				msgBox.addLine(_row3);
				if ((getElapsedSeconds() - _time4) < MESSAGE_FADE_TIME)	
					msgBox.addLine(_row4);
			}
		}

		msgTexture = msgBox.render(true,false);

		// Have to turn alpha blending on and off to get it
		// to work right. It might be better to do this in the main
		// application setup function.
		gl::enableAlphaBlending();
		gl::draw(msgTexture,Vec2f(getWindowWidth()*_x, getWindowHeight()*_y));
		gl::disableAlphaBlending();
	}

}