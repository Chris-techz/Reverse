#include "Reverse.h"
#include <iostream>

/* 
		*** Reverse Exercice Test ***

	- Writen by     : Christophe GOUGIS
	- IDE			: Visual Studio 2019, 16.9.4
	- file format   : ANSI
	- Start			: 13h30 pm;
	- Difficulty	: advanced;		( Ouch, it was harder thant I thought :o )
	- Planned end	: 19h30 pm;
	- Effective end : 20h17 pm;

	- Planned programming time	 = 6 hours;
	- Effective programming time = 6 hours 47 minutes;
*/

int main(int argc, char* argv[])
{
	Reverse obj;
	if (argc == 2)
	{
		obj.OpenFile(argv[1]);
		obj.LoadFile(argv[1]);
		obj.DisplayFile();
		obj.Glossary();
		obj.Inversed();
	}
	else
	{
		//no path in argument, error
		printf("No argument provided ! End of program ... ");
	}

	system("PAUSE");
	return 0;
}