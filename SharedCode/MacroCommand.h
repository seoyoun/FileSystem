#pragma once
#include "AbstractCommand.h"
#include "AbstractParsingStrategy.h"
#include "AbstractFileSystem.h"
#include <vector>


class MacroCommand :public AbstractCommand {
private:
	std::vector<AbstractCommand> cmds;
	AbstractParsingStrategy* strategy;
	AbstractFileSystem* fileSystem;

public:
	MacroCommand(AbstractFileSystem*);
	virtual int execute(std::string);
	virtual void displayInfo();
	void addCommand(AbstractCommand*);
	void setParseStrategy(AbstractParsingStrategy*);
};


