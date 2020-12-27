// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "..\..\\SharedCode\SimpleFileFactory.h"
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include "..\..\\SharedCode\TouchCommand.h"
#include "..\..\\SharedCode\LSCommand.h"
#include "..\..\\SharedCode\RemoveCommand.h"
#include "..\..\\SharedCode\CommandPrompt.h"
#include <iostream>
using namespace std;

int main()
{
	SimpleFileSystem* system = new SimpleFileSystem();
	SimpleFileFactory* factory = new SimpleFileFactory();
	TouchCommand* cmd = new TouchCommand(system, factory);
	LSCommand* cmd1 = new LSCommand(system);
	RemoveCommand* cmd2 = new RemoveCommand(system);
	CommandPrompt cmdprompt;
	cmdprompt.setFileSystem(system);
	cmdprompt.setFileFactory(factory);
	cmdprompt.addCommand("touch", cmd);
	cmdprompt.addCommand("touch -p", cmd);
	cmdprompt.addCommand("ls", cmd1);
	cmdprompt.addCommand("ls -m", cmd1);
	cmdprompt.addCommand("rm", cmd2);
	cmdprompt.run();
	AbstractFile* file = system->openFile("touch");
	if (file == 0) {
		cout << "file did not open" << endl;
		return 1;
	}
	return 0;
	
}

