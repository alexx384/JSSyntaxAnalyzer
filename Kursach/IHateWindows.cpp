#ifdef _DEBUG

#include "KurCommon.h"

#include <Windows.h>

static WORD wStartConsoleAttribute;
static HANDLE hConsole;

void InitConsole()
{
	CONSOLE_SCREEN_BUFFER_INFO Info;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsole, &Info);
	wStartConsoleAttribute = Info.wAttributes;
}

void SetTextColor(unsigned int color)
{
	SetConsoleTextAttribute(hConsole, color);
}

void RevertColors()
{
	SetConsoleTextAttribute(hConsole, wStartConsoleAttribute);
}

#endif // _DEBUG