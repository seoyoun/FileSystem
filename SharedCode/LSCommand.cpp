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
	try{
		if (filename != "-m") {
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
		else {
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
		return 1;
	}
	return 0;
}