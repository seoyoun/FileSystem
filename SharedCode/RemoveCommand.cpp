/* File: RemoveCommand.cpp
   Authors: Yanpeng Yuan (yanpeng@wustl.edu), Ziwen Wang (ziwen.wang@wustl.edu), Sally Lee (sallylee@wustl.edu)
   Summary: definitions of the RemoveCommand class member functions
			RemoveCommand removes the file with the provided name from the file system.
*/
#include "RemoveCommand.h"
#include <iostream>
using namespace std;


RemoveCommand::RemoveCommand(AbstractFileSystem* system) :fileSystem(system) {}

void RemoveCommand::displayInfo() {
	cout << "rm deletes a file, rm can be invoked with the command: rm <filename>" << endl;
}

int RemoveCommand::execute(string filename) {
	
	return fileSystem->deleteFile(filename);

}