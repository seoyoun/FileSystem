#pragma once
#include <map>
#include <string>
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
class CommandPrompt {
public:
	CommandPrompt();
	void setFileSystem(AbstractFileSystem*);
	void setFileFactory(AbstractFileFactory*);

	int addCommand(std::string, AbstractCommand*);

	int run();
	
private:
	std::map<std::string, AbstractCommand*> commandMap;

	AbstractFileSystem* fileSystem;

	AbstractFileFactory* factory;

protected:
	void listCommands();

	std::string prompt();


};