#include "MacroCommand.h"
#include <iostream>
using namespace std;

MacroCommand::MacroCommand(AbstractFileSystem* system) :fileSystem(system) {}


void MacroCommand::displayInfo() {
	cout << "macro executes each of the commands it is composed of in order" << endl;
}


int MacroCommand::execute(string cmdInputs) {
	vector<string> inputs = strategy->parse(cmdInputs);
	for (size_t i = 0; i < cmds.size(); ++i) {
		int state = cmds[i].execute(inputs[i]);
		if (state != 0) {
			return cmd_failed;
		}
	}
	return success;
}

void MacroCommand::addCommand(AbstractCommand* cmd) {
	cmds.push_back(*cmd);
}


void MacroCommand::setParseStrategy(AbstractParsingStrategy* new_strategy) {
	strategy = new_strategy;
}