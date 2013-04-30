#ifndef IMPORTANT_MESSAGE_H
#define IMPORTANT_MESSAGE_H
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