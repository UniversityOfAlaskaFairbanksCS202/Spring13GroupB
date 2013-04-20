#ifndef MESSENGER_H
#define MESSENGER_H
// John Cheshire / Group B
// Date: 03/31/2013
//
// This is the header file for the messenger class.
// The class displays four rows of messages on the upper
// right hand side of the screen.
// A Messenger object should be created as a private member variable
// in the Cinder application class.
// This object should be passed by reference to all
// other classes that need to display messages to the screen.
// New messages are added to the queue using the newMessage
// member function.
// The draw() member function should be called in the draw
// function of the app class.

// The following five lines are required to start GDI+
// which is needed to create a TextLayout.
#include <windows.h>
#include <objidl.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#include <GdiPlus.h>

#include <string>
#include "cinder\Text.h"
#include "cinder\gl\Texture.h"
#include "cinder\app\AppBasic.h"

using namespace ci;
using namespace ci::app;
using std::string;

class Messenger
{
private:
	float _x;
	float _y;
	float _red;
	float _green;
	float _blue;
	float _size;
	string _row1;
	string _row2;
	string _row3;
	string _row4;
public:
	Messenger();
	void newMessage(string);
	void draw();
};

#endif