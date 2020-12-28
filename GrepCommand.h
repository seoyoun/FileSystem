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