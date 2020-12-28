#pragma once
#include "..\..\\SharedCode\AbstractCommand.h"
#include "..\..\\SharedCode\AbstractFileSystem.h"
#include "..\..\\SharedCode\AbstractFileFactory.h"


class GrepCommand :public AbstractCommand {
private:
	AbstractFileSystem* fileSystem;
public:
	GrepCommand(AbstractFileSystem*);
	virtual void displayInfo();
	virtual int execute(std::string);
};

