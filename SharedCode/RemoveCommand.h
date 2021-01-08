/* File: RemoveCommand.h
   Authors: Yanpeng Yuan (yanpeng@wustl.edu), Ziwen Wang (ziwen.wang@wustl.edu), Sally Lee (sallylee@wustl.edu)
   Summary: declaration of the RemoveCommand class
			RemoveCommand removes the file with the provided name from the file system.
*/
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"


class RemoveCommand :public AbstractCommand {
private:
	AbstractFileSystem* fileSystem;
public:
	RemoveCommand(AbstractFileSystem*);
	virtual void displayInfo();
	virtual int execute(std::string);
};

