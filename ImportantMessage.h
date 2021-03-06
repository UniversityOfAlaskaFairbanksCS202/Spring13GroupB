#ifndef IMPORTANT_MESSAGE_H
#define IMPORTANT_MESSAGE_H
// By: John Cheshire
// The ImportantMessage class is used to display a splash screen like
// message. It communicates importatn information like how to play the game
// or the players death.

#include "MessageBase.h"

class ImportantMessage : public MessageBase
{
private:
	string _msg;
	bool _quitGame;
	int _waitTime;
	int _startTime;
public:
	ImportantMessage();
	void splashMessage(string, int, bool);
	void draw();
};

#endif