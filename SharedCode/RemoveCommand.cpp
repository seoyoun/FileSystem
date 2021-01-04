#include "RemoveCommand.h"
#include <iostream>
using namespace std;


RemoveCommand::RemoveCommand(AbstractFileSystem* system) :fileSystem(system) {}

void RemoveCommand::displayInfo() {
	cout << "rm deletes a file, rm can be invoked with the command: rm <filename>" << endl;
}

int RemoveCommand::execute(string filename) {
	//cout << fileSystem->deleteFile(filename)<<endl;
	return fileSystem->deleteFile(filename);

}