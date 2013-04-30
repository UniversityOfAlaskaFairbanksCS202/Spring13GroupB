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

#include "MessageBase.h"

class Messenger : public MessageBase
{
private:
	const int MESSAGE_FADE_TIME;
	string _row1;
	string _row2;
	string _row3;
	string _row4;
	int _time1;
	int _time2;
	int _time3;
	int _time4;
public:
	// MESSAGE_FADE_TIME controls how long messages are displayed
	Messenger() : MESSAGE_FADE_TIME(8), MessageBase()
	{	
		_row1 = " ";
		_row2 = " ";
		_row3 = " ";
		_row4 = " ";
		_time1 = 0;
		_time2 = 0;
		_time3 = 0;
		_time4 = 0;
		_x = 0.0f;
		_y = 0.0f;
		// Default colors provide yellow text
		_red = 1.0f;
		_green = 1.0f;
		_blue = 0.2f;
		// _size is used to scale size of font depending on window size
		_size = 16.0f/480;
	}
	void newMessage(string);
	void draw();
};

#endif