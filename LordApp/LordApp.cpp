#include <iostream>
#include<io.h>
#include<fcntl.h>
#include"landlord.h"

int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);

	userInterface theUserInterface;
	theUserInterface.interact();

}
