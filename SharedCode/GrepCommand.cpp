#include "CatCommand.h"
#include <iostream>
#include <iomanip>
#include <exception>
#include "MetadataDisplayVisitor.h"
#include "BasicDisplayVisitor.h"
#include "GrepVisitor.h"
#include "GrepCommand.h"
using namespace std;

GrepCommand::GrepCommand(AbstractFileSystem* system) :fileSystem(system) {}

void GrepCommand::displayInfo() {
	cout << "cat appends, or overwrites a file. use with -a for appending, no argument otherwise" << endl;
}

int GrepCommand::execute(string query) {
	try {
		int fileCount = 0;
		set<string> nameSet = fileSystem->​getFileNames​();
		MetadataDisplayVisitor* metadataVisitor = new MetadataDisplayVisitor();
		cout << "started searching, information of found files are listed below" << endl;
		cout << "-----------------------------" << endl;
		for (string fileName : nameSet) {
			GrepVisitor* grepVisitor = new GrepVisitor(query);
			AbstractFile* file = fileSystem->openFile(fileName);
			file->accept(grepVisitor);
			if (grepVisitor->isInFile()) {
				file->accept(metadataVisitor);
				++fileCount;
			}
			fileSystem->closeFile(file);
		}
		if (fileCount == 0) {
			cout << "no files found" << endl;
		}
		cout << "-----------------------------" << endl;
		cout << "done searching, found " << fileCount << " files" << endl;
		return 0;
	
	}
	catch (...) {
		return unexpectedException;
	}
	return success;
}