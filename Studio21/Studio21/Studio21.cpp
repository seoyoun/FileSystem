// Studio21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "..\..\\SharedCode\SimpleFileFactory.h"
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include "..\..\\SharedCode\TouchCommand.h"
#include "..\..\\SharedCode\CommandPrompt.h"
#include <iostream>
using namespace std;

int main()
{
	SimpleFileSystem* system = new SimpleFileSystem();
	SimpleFileFactory* factory = new SimpleFileFactory();
	TouchCommand* cmd = new TouchCommand(system,factory);
	CommandPrompt cmdprompt;
	cmdprompt.setFileSystem(system);
	cmdprompt.setFileFactory(factory);
	cmdprompt.addCommand("touch", cmd);
	cmdprompt.run();
	AbstractFile *file = system->openFile("touch");
	if (file == 0) {
		cout << "file did not open" << endl;
		return 1;
	}
	return 0;
}

