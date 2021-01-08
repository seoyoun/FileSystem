/* File: CopyCommand.cpp
   Authors: Yanpeng Yuan (yanpeng@wustl.edu), Ziwen Wang (ziwen.wang@wustl.edu), Sally Lee (sallylee@wustl.edu)
   Summary: definitions of CopyCommand class member functions
			CopyCommand copies a file that exists in the file system and adds the copy to the file system with a different name.

*/
#include "CopyCommand.h"
#include <iostream>
#include <sstream>
using namespace std;

CopyCommand::CopyCommand(AbstractFileSystem* system) :fileSystem(system) {}

void CopyCommand::displayInfo() {
	cout << "The copy command copies a file that exists in the file system and adds the copy to the file system with a different name" << endl;
	cout << "It is invoked with the following:" << endl;
	cout << "cp <file_to_copy> <new_name_with_no_extension>" << endl;
}


int CopyCommand::execute(string original_newName) {
	istringstream iss(original_newName);
	string original;
	string newName;
	iss >> original >> newName;


	AbstractFile* file = fileSystem->openFile(original);
	if (file == 0) {
		cout << "original file cannot be opened" << endl;
		return cannot_open_file;
	}

	AbstractFile* cloned = file->clone(newName);
	if (cloned == 0) {
		cout << "file cannot be copied" << endl; 
		fileSystem->closeFile(file);
		return cannot_copy_file;
	}

	int state = fileSystem->addFile(cloned->getName(), cloned);
	if (state == 0) {
		fileSystem->closeFile(file);
		return success;
	}

	cout << "copied file cannot be added to the file system" << endl;
	delete cloned;
	fileSystem->closeFile(file);
	return cannot_add_file;




}