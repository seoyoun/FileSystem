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