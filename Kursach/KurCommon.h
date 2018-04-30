#pragma once
#pragma warning (disable:4273)

#include <iostream>
#include <fstream>


void yyerror(const char* format, ...);
int yylex();

extern FILE *yyin;