// Authors: Yanpeng Yuan (yanpeng@wustl.edu), Ziwen Wang (ziwen.wang@wustl.edu), Sally Lee (sallylee@wustl.edu)
// declearation of cat command
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"


class CatCommand :public AbstractCommand {
private:
	AbstractFileSystem* fileSystem;
public:
	CatCommand(AbstractFileSystem*);
	virtual void displayInfo();
	virtual int execute(std::string);
};

enum status { success=0, unexpectedException = 1, wrongFileName = 2, userQuit =3 };