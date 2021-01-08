/* File: MacroCommand.h
   Authors: Yanpeng Yuan (yanpeng@wustl.edu), Ziwen Wang (ziwen.wang@wustl.edu), Sally Lee (sallylee@wustl.edu)
   Summary: declaration of the MacroCommand class 
			MacroCommand is a composition of other types of commands.
			It executes each of the commands it is composed of in order.
*/
#pragma once
#include "AbstractCommand.h"
#include "AbstractParsingStrategy.h"
#include "AbstractFileSystem.h"
#include <vector>


class MacroCommand :public AbstractCommand {
private:
	std::vector<AbstractCommand*> cmds;
	AbstractParsingStrategy* strategy;
	AbstractFileSystem* fileSystem;

public:
	MacroCommand(AbstractFileSystem*);
	virtual int execute(std::string);
	virtual void displayInfo();
	void addCommand(AbstractCommand*);
	void setParseStrategy(AbstractParsingStrategy*);
};


