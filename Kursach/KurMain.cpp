#include "KurCommon.h"

#define ERROR		-1
#define NO_ERROR	0

extern int yyparse();

int main(int argc, const char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: program.exe [file]" << std::endl;

		return ERROR;
	}

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

	getchar();

	return NO_ERROR;
}