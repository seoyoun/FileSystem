/* File: LSCommand.h
   Authors: Yanpeng Yuan (yanpeng@wustl.edu), Ziwen Wang (ziwen.wang@wustl.edu), Sally Lee (sallylee@wustl.edu)
   Summary: declaration of the LSCommand class
			LSCommand ouputs to the terminal the names of all files currently in the file system.
*/
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"


class LSCommand :public AbstractCommand {
private:
	AbstractFileSystem* fileSystem;
public:
	LSCommand(AbstractFileSystem*);
	virtual void displayInfo();
	virtual int execute(std::string);
};