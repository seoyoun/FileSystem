/* File: LSCommand.h
   Authors: Yanpeng Yuan (yanpeng@wustl.edu), Ziwen Wang (ziwen.wang@wustl.edu), Sally Lee (sallylee@wustl.edu)
   Summary: defintions of the LSCommand class member functions
			LSCommand ouputs to the terminal the names of all files currently in the file system.
*/
#include "LSCommand.h"
#include <iostream>
#include <iomanip>
#include <exception>
#include "MetadataDisplayVisitor.h"
using namespace std;


LSCommand::LSCommand(AbstractFileSystem* system) :fileSystem(system) {}

void LSCommand::displayInfo() {
	cout << "ls displays the names of all files, ls can be invoked with the command: ls" << endl;
}

int LSCommand::execute(string filename) {
	set<string> s = fileSystem->getFileNames();
	if (filename != "" && filename != "-m") {
		return unexpectedException;
	}
	try{
		if (filename == "") {
			set<string>::iterator iter = s.begin();
			while (iter != s.end())
			{
				cout << left << setw(20) << *iter << flush;
				iter++;
				if (iter != s.end()) {
					cout << left << setw(20) << *iter << endl;
				}
				else {
					cout << endl;
					break;
				}
				++iter;
			}
		}
		else if(filename == "-m"){
			set<string>::iterator iter = s.begin();
			while (iter != s.end())
			{
				AbstractFile* tem = fileSystem->openFile(*iter);
				MetadataDisplayVisitor* visitor = new MetadataDisplayVisitor;
				tem->accept(visitor);
				++iter;
				fileSystem->closeFile(tem);
			}
			
		}	
		
}
	catch (...) {
		return  unexpectedException;
	}
	return success;
}