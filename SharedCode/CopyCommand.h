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

