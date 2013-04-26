#include "MessageBase.h"
// By: John Cheshire
// 4/25/2013
// This is a base class for the Messenger and UIMessage
// classes. It implements text output to the screen.


MessageBase::MessageBase()
{
	// These lines start GDI+, which must be done
	// before a TextLayout object can be created.
	Gdiplus::GdiplusStartupInput _gdiplusStartupInput;
	ULONG_PTR _GdiplusToken;
	Gdiplus::GdiplusStartup( &_GdiplusToken, &_gdiplusStartupInput, NULL );
}