#pragma once
#pragma warning (disable:4273)
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>

class YYSTATPOS
{
public:
	YYSTATPOS() : col(0), line(0) {}
	~YYSTATPOS() {};

	void incLinePos(size_t val) {
		col += val;
	}
	void nextLine() {
		++line;
		col = 0;
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