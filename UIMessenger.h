#ifndef UIMESSENGER_H
#define UIMESSENGER_H

#include "MessageBase.h"
#include "Player.h"
#include <sstream>

class UIMessenger : public MessageBase
{
private:
	// UIMessenger has two rows in two texlayout objects
	// This was done because a long row did not render properly
	string _row11;
	string _row21;
	string _row12;
	string _row22;
	// Another set of coordinates for second textlayout object
	float _x2;
	float _y2;
	Player *_player;
public:
	// This default constructor is required for UIMessenger object to
	// be a member variable in other class.
	UIMessenger()
	{}
	UIMessenger(Player&);
	void draw() const;
	void update();
};

#endif