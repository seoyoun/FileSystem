﻿// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Authors: Yanpeng Yuan (yanpeng@wustl.edu), Ziwen Wang (ziwen.wang@wustl.edu), Sally Lee (sallylee@wustl.edu)

#include "..\..\\SharedCode\SimpleFileFactory.h"
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include "..\..\\SharedCode\TouchCommand.h"
#include "..\..\\SharedCode\LSCommand.h"
#include "..\..\\SharedCode\CatCommand.h"
#include "..\..\\SharedCode\RemoveCommand.h"
#include "..\..\\SharedCode\DisplayCommand.h"
#include "..\..\\SharedCode\CommandPrompt.h"
#include "..\..\\SharedCode\BasicDisplayVisitor.h"
#include "..\..\\SharedCode\GrepCommand.h"
#include "..\..\\SharedCode\MacroCommand.h"
#include "..\..\\SharedCode\RenameParsingStrategy.h"
#include "..\..\\SharedCode\CopyCommand.h"

#include <iostream>
using namespace std;



int main()
{
	AbstractFileSystem* system = new SimpleFileSystem();
	SimpleFileFactory* factory = new SimpleFileFactory();
	TouchCommand* cmd = new TouchCommand(system, factory);
	LSCommand* cmd1 = new LSCommand(system);
	RemoveCommand* cmd2 = new RemoveCommand(system);
	CatCommand* cmd3 = new CatCommand(system);
	DisplayCommand* cmd4 = new DisplayCommand(system);
	GrepCommand* cmd5 = new GrepCommand(system);
	CommandPrompt cmdprompt;

	set<string> s = system->getFileNames();

	//rename command
	MacroCommand* rename = new MacroCommand(system);
	RenameParsingStrategy* rename_strat = new RenameParsingStrategy;
	CopyCommand* copycmd = new CopyCommand(system);
	rename->setParseStrategy(rename_strat);
	rename->addCommand(copycmd);
	rename->addCommand(cmd2);
	


	AbstractFile* txt = factory->createFile("1.txt");
	vector<char> input = { 'X','X','\n','X' };
	txt->write(input);
	system->addFile("1.txt", txt);


	AbstractFile* txt2 = factory->createFile("2.txt");
	vector<char> input2 = { '1', '2', '2', '2', 'X', ' ', 'X',' ', 'X', '3' };
	txt2->write(input2);
	system->addFile("2.txt", txt2);


	AbstractFile* img = factory->createFile("1.img");
	std::vector<char> inputImg = { '1', '2', '2', '2', 'X', ' ', 'X',' ', 'X', '3' };
	img->write(inputImg);
	system->addFile("1.img", img);

	cmdprompt.setFileSystem(system);
	cmdprompt.setFileFactory(factory);
	cmdprompt.addCommand("touch", cmd);
	cmdprompt.addCommand("touch -p", cmd);
	cmdprompt.addCommand("ls", cmd1);
	cmdprompt.addCommand("ls -m", cmd1);
	cmdprompt.addCommand("rm", cmd3);
	cmdprompt.addCommand("cat", cmd3);
	cmdprompt.addCommand("cat -a", cmd3);
	cmdprompt.addCommand("ds", cmd4);
	cmdprompt.addCommand("ds -d", cmd4);
	cmdprompt.addCommand("grep", cmd5);

	cmdprompt.addCommand("rn", rename);

	cmdprompt.run();

	AbstractFile* file = system->openFile("touch");
	if (file == 0) {
		cout << "file did not open" << endl;
		return cannot_open_file;
	}
	system->closeFile(file);
	return success;

}
