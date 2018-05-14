#pragma once
#pragma warning (disable:4273)
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>

class YYSTATPOS
{
public:
	YYSTATPOS() : col(1), line(1) {}
	~YYSTATPOS() {};

	void incLinePos(size_t val) {
		col += val;
	}
	void nextLine() {
		++line;
		col = 1;
	}

	size_t getCol() {
		return col;
	}
	size_t getLine() {
		return line;
	}

private:
	size_t col;
	size_t line;
};

void yyerror(const char* format, ...);
int yylex();

extern FILE *yyin;

#ifdef _DEBUG

#define LIGHT_GREEN				10
#define LIGHT_BLUE				11
#define LIGHT_RED				12
#define LIGHT_PURPLE			13
#define LIGHT_YELLOW			14
#define LIGTH_WHITE				15

void InitConsole();
void SetTextColor(unsigned int color);
void RevertColors();

#endif // _DEBUG