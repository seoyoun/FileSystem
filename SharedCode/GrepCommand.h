// Authors: Yanpeng Yuan (yanpeng@wustl.edu), Ziwen Wang (ziwen.wang@wustl.edu), Sally Lee (sallylee@wustl.edu)
// declearation of the grep command is given here
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"


class GrepCommand :public AbstractCommand {
private:
	AbstractFileSystem* fileSystem;
public:
	GrepCommand(AbstractFileSystem*);
	virtual void displayInfo();
	virtual int execute(std::string);
};