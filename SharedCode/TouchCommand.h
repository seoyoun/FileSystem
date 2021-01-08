/* File: TouchCommand.h
   Authors: Yanpeng Yuan (yanpeng@wustl.edu), Ziwen Wang (ziwen.wang@wustl.edu), Sally Lee (sallylee@wustl.edu)
   Summary: declaration of the TouchCommand class
			TouchCommand uses the file factory to create files and then adds them to the file system.
*/
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"


class TouchCommand:public AbstractCommand {
private:
	AbstractFileSystem* fileSystem;
	AbstractFileFactory* fileFactory;
public:
	TouchCommand(AbstractFileSystem*, AbstractFileFactory*);
	virtual void displayInfo();
	virtual int execute(std::string);
};