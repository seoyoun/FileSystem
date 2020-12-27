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

