#include "TouchCommand.h"
#include "PassWordProxy.h"
#include <iostream>
using namespace std;


TouchCommand::TouchCommand(AbstractFileSystem* system, AbstractFileFactory* factory):fileSystem(system),fileFactory(factory){}

void TouchCommand::displayInfo() {
	cout << "touch creates a file, touch can be invoked with the command: touch <filename>. touch <filename> -p creates a password protected file." << endl;
}

int TouchCommand::execute(string filename) {
	if (filename.substr(filename.find_first_of(" \t") + 1) == "-p") {
		string::size_type pos = filename.find(' ');
		filename = filename.substr(0, pos);
		cout << "What is the password? " << endl;
		string pw;
		getline(cin, pw);
		AbstractFile* file = fileFactory->createFile(filename);
		PasswordProxy tem(file, pw);
		int state = fileSystem->addFile(filename,&tem);
		if (state != 0) {
			delete file;
			return 2;
		}
		return 0;
	}
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