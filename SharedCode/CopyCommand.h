/* File: CopyCommand.h
   Authors: Yanpeng Yuan (yanpeng@wustl.edu), Ziwen Wang (ziwen.wang@wustl.edu), Sally Lee (sallylee@wustl.edu)
   Summary: declaration of the CopyCommand class 
			CopyCommand copies a file that exists in the file system and adds the copy to the file system with a different name.
*/
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"


class CopyCommand : public AbstractCommand {
private:
	AbstractFileSystem* fileSystem;
public:
	CopyCommand(AbstractFileSystem*);
	virtual void displayInfo();
	virtual int execute(std::string);

};

