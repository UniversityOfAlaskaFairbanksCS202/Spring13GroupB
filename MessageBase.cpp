#include "MessageBase.h"
// By: John Cheshire
// 4/25/2013
// This is a base class for the Messenger and UIMessage
// classes.
// Its main function is to contain common member variables
// and start the GDI+ that is required in windows.


MessageBase::MessageBase()
{
	// These lines start GDI+, which must be done
	// before a TextLayout object can be created.
#ifdef _WIN32 // for mac compatibility
	Gdiplus::GdiplusStartupInput _gdiplusStartupInput;
	ULONG_PTR _GdiplusToken;
	Gdiplus::GdiplusStartup( &_GdiplusToken, &_gdiplusStartupInput, NULL );
#endif
}