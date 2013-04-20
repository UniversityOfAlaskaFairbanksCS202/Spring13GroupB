// John Cheshire / Group B
// Date: 03/31/2013
//
// The code in this file implements the Messenger class.

#include "Messenger.h"

Messenger::Messenger()
{
	// These lines start GDI+, which must be done
	// before a TextLayout object can be created.
	Gdiplus::GdiplusStartupInput _gdiplusStartupInput;
	ULONG_PTR _GdiplusToken;
	Gdiplus::GdiplusStartup( &_GdiplusToken, &_gdiplusStartupInput, NULL );

	_row1 = " ";
	_row2 = " ";
	_row3 = " ";
	_row4 = " ";
	_x = 0.0f;
	_y = 0.0f;
	// Default colors provide yellow text
	_red = 1.0f;
	_green = 1.0f;
	_blue = 0.2f;
	_size = 16.0f/480;
}

// This function draws the messages to screen.
void Messenger::draw()
{
	// msgBox and msgTexture are created here
	// because they must be created after GDI+
	// is started as so cannot be member variables.
	TextLayout msgBox;
	gl::Texture msgTexture;

	msgBox.clear(ColorA(0.0f,0.0f,0.0f,0.0f));
	msgBox.setColor(Color(_red,_green,_blue)); 
	msgBox.setFont(Font("Courier New",getWindowHeight()*_size));
	msgBox.addLine(_row1);
	msgBox.addLine(_row2);
	msgBox.addLine(_row3);
	msgBox.addLine(_row4);

	msgTexture = msgBox.render(true,false);

	// Have to turn alpha blending on and off to get it
	// to work right. It might be better to do this in the main
	// application setup function.
	gl::enableAlphaBlending();
	gl::draw(msgTexture,Vec2f(getWindowWidth()*_x, getWindowHeight()*_y));
	gl::disableAlphaBlending();
}

void Messenger::newMessage(string newMsg)
{
	_row4 = _row3;
	_row3 = _row2;
	_row2 = _row1;
	_row1 = newMsg;
}