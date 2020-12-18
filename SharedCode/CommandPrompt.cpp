//class CommandPrompt {
//public:
//	CommandPrompt();
//	void setFileSystem(AbstractFileSystem*);
//	void setFileFactory(AbstractFileFactory*);
//
//	int addCommand(std::string, AbstractCommand*);
//
//	int run();
//
//private:
//	std::map<std::string, AbstractCommand*> commandMap;
//
//	AbstractFileSystem* fileSystem;
//
//	AbstractFileFactory* factory;
//
//protected:
//	void listCommands();
//
//	std::string prompt();
//
//
//};
#include "CommandPrompt.h"
#include <iostream>
#include <sstream>
using namespace std;
CommandPrompt::CommandPrompt() {

}

void CommandPrompt::setFileSystem(AbstractFileSystem* fileSys) {
	fileSystem = fileSys;
}

void CommandPrompt::setFileFactory(AbstractFileFactory* fileFac) {
	factory = fileFac;
}

int CommandPrompt::addCommand(string name, AbstractCommand* command) {
	auto res = commandMap.insert({ name,command });
	return res.second;
}

void CommandPrompt::listCommands() {

	map<string, AbstractCommand*>::iterator it;

	for (it = commandMap.begin(); it != commandMap.end(); it++)
	{
		cout << it->first << endl;
	}

}

string CommandPrompt::prompt() {
	cout << "Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command."
		 << endl;
	string input;
	cout << "$ ";
	getline(cin, input);
	return input;

}

int CommandPrompt::run() {
	while (1 == 1) {
		string cmd;
		cmd = prompt();
		stringstream stream(cmd);
		if (cmd == "q") {
			return 1;
		}
		if (cmd == "help") {
			listCommands();
		}
		string realCmd;
		string extraCmd;
		int cmdNum = 0;
		stream >> realCmd;
		if (!(stream.tellp() == 0)) {
			cmdNum++;
			extraCmd = stream.str();
		}
		if (cmdNum==0) {
			auto itr = commandMap.find(realCmd);
			if (itr != commandMap.end()) {
				string exe;
				int state;
				state=itr->second->execute(exe);
				if (state != 0) {
					cout << "command failed" << endl;
				}
			}
			else {
				cout << "command does not exist" << endl;
			}
		}
		if (cmdNum == 1) {
			if (realCmd == "help") {
				stringstream helpStream(extraCmd);
				string helpCmd;
				helpStream >> helpCmd;

				auto itr = commandMap.find(helpCmd);
				if (itr != commandMap.end()) {
					itr->second->displayInfo();
				}
				else {
					cout << "command does not exist" << endl;
				}
			}
			else {
				auto itr = commandMap.find(realCmd);
				if (itr != commandMap.end()) {
					int state;
					state = itr->second->execute(extraCmd);
					if (state != 0) {
						cout << "command failed" << endl;
					}
				}
				else {
					cout << "command does not exist" << endl;
				}
			}

		}
		 
	}
}