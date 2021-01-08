/* File: TouchCommand.cpp
   Authors: Yanpeng Yuan (yanpeng@wustl.edu), Ziwen Wang (ziwen.wang@wustl.edu), Sally Lee (sallylee@wustl.edu)
   Summary: definitions of the TouchCommand class member functions
			TouchCommand uses the file factory to create files and then adds them to the file system.
*/
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
		cout << "What is the password?" << endl;
		string pw;
		getline(cin, pw);
		AbstractFile* file = fileFactory->createFile(filename);
		PasswordProxy* tem = new PasswordProxy(file, pw);
		int state = fileSystem->addFile(filename,tem);
		if (state != success) {
			delete file;
			return cannot_add_file; 
		}
		return success;
	}
	AbstractFile * file = fileFactory->createFile(filename);
	if (file == 0) {
		return cannot_create_file;
	}
	int state = fileSystem->addFile(filename, file);
	if (state != success) {
		delete file;
		return cannot_add_file;
	}
	return success;

}