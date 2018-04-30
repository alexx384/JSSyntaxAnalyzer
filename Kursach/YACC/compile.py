import os
import sys
import shutil

if __name__ == "__main__":

	# argv[1] - current working directory
	if len(sys.argv) != 2:
		exit(11)

	#compile lex and yacc files
	os.chdir(sys.argv[1])
	shutil.copy('..\\lexic.l', 'lexic.l')
	os.system('bison -d -o parse.cpp parse.y')
	os.system('flex lexic.l')
	
	#replace deprecated function
	file = open('lexic.cpp', 'r')
	s = file.read()
	s = s.replace('isatty', '_isatty')
	s = s.replace('fileno', '_fileno')
	s = s.replace('#include <unistd.h>', '')
	file.close()
	
	file = open('lexic.cpp', 'w')
	file.write(s)
	file.close()
	
	# move compiled files to upper level
	shutil.move('lexic.cpp', '..\\lexic.cpp')
	shutil.move('parse.cpp', '..\\parse.cpp')
	shutil.move('parse.cpp.h', '..\\parse.cpp.h')