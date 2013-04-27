#ifndef MESSAGE_BASE_H
#define MESSAGE_BASE_H

// The following five lines are required to start GDI+
// which is needed to create a TextLayout.

#ifdef _WIN32 // for mac compatibility
#include <windows.h>
#include <objidl.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#include <GdiPlus.h>
#endif

#include <string>
#include "cinder/Text.h"
#include "cinder/gl/Texture.h"
#include "cinder/app/AppBasic.h"


using namespace ci;
using namespace ci::app;
using std::string;

class MessageBase
{
protected:
	float _x;
	float _y;
	float _red;
	float _green;
	float _blue;
	float _size;

public:
	MessageBase();
	virtual void draw() const = 0;
};

#endif