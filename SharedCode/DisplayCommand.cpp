
#include "DisplayCommand.h"
#include "CatCommand.h"
#include <iostream>
#include <iomanip>
#include <exception>
#include "MetadataDisplayVisitor.h"
#include "BasicDisplayVisitor.h"

using namespace std;


DisplayCommand::DisplayCommand(AbstractFileSystem* system) :fileSystem(system) {}

void DisplayCommand::displayInfo() {
	cout << "invoke ds to display file, add -d if the file is to be shown without formatting" << endl;
}

int DisplayCommand::execute(string filename) {
	try {
		BasicDisplayVisitor* displayVisitor = new BasicDisplayVisitor;
		if (filename.substr(filename.find_first_of(" \t") + 1) == "-d") {
			string::size_type pos = filename.find(' ');
			filename = filename.substr(0, pos);
			AbstractFile* file = fileSystem->openFile(filename);
			if (file == nullptr) {
				cout << "\"" << filename << "\"" << " not found in the file system ";
				return wrongFileName;
			}
			vector<char> content = file->read();
			for (char c : content) {
				cout << c;
			}
			fileSystem->closeFile(file);
		}
		else {
			string::size_type pos = filename.find(' ');
			filename = filename.substr(0, pos);
			AbstractFile* file = fileSystem->openFile(filename);
			if (file == nullptr) {
				cout << "\"" << filename << "\"" << " not found in the file system ";
				return wrongFileName;
			}
			file->accept(displayVisitor);
			fileSystem->closeFile(file);
		}

	}
	catch (...) {
		return unexpectedException;
	}
	return success;
}