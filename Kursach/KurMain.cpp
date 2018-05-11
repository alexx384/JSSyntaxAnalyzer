#include "KurCommon.h"

#define ERROR		-1
#define NO_ERROR	0

extern int yyparse();
extern YYSTATPOS g_yypos;

int main(int argc, const char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: program.exe [file]" << std::endl;

		return ERROR;
	}

#ifdef _DEBUG
	InitConsole();
#endif // _DEBUG


	yyin = fopen(argv[1], "r");

	if (!yyin)
	{
		std::cout << "Error: The file is doesn't exist" << std::endl;
	}

	int i = yyparse();

	if (i == NO_ERROR)
	{
		std::cout << "Success" << std::endl;
	}
	else
	{
		std::cout << "Fail" << std::endl;
	}

	fclose(yyin);

	std::cout << "End position: Line " << g_yypos.getLine() << ", Column " << g_yypos.getCol() << std::endl;

	getchar();

	return NO_ERROR;
}