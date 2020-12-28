#include "CatCommand.h"
#include <iostream>
#include <iomanip>
#include <exception>
#include "MetadataDisplayVisitor.h"
#include "BasicDisplayVisitor.h"
#include "GrepCommand.h"
using namespace std;


GrepCommand::GrepCommand(AbstractFileSystem* system) :fileSystem(system) {}

void GrepCommand::displayInfo() {
	cout << "cat appends, or overwrites a file. use with -a for appending, no argument otherwise" << endl;
}

int GrepCommand::execute(string filename) {
	try {
	

	}
	catch (...) {
		return unexpectedException;
	}
	return success;
}