#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"


class DisplayCommand :public AbstractCommand {
private:
	AbstractFileSystem* fileSystem;
public:
	DisplayCommand(AbstractFileSystem*);
	virtual void displayInfo();
	virtual int execute(std::string);
};
