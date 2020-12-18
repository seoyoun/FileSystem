#include "TouchCommand.h"
#include <iostream>
using namespace std;


TouchCommand::TouchCommand(AbstractFileSystem* system, AbstractFileFactory* factory):fileSystem(system),fileFactory(factory){}

void TouchCommand::displayInfo() {
	cout << "touch creates a file, touch can be invoked with the command: touch <filename>" << endl;
}

int TouchCommand::execute(string filename) {
	AbstractFile * file = fileFactory->createFile(filename);
	if (file == 0) {
		return 1;
	}
	int state = fileSystem->addFile(filename, file);
	if (state != 0) {
		delete file;
		return 2;
	}
	return 0;

}