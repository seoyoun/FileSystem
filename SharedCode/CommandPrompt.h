/* File: CommandPrompt.h
   Authors: Yanpeng Yuan (yanpeng@wustl.edu), Ziwen Wang (ziwen.wang@wustl.edu), Sally Lee (sallylee@wustl.edu)
   Summary: declaration of the CommandPrompt class
			CommandPrompt is the user interface for the file system.
			It is configured with concrete commands and will invoke them when requested by the user.
*/
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