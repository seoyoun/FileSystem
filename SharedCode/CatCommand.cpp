// Authors: Yanpeng Yuan (yanpeng@wustl.edu), Ziwen Wang (ziwen.wang@wustl.edu), Sally Lee (sallylee@wustl.edu)
// definition of the cat command is here
#include "CatCommand.h"
#include <iostream>
#include <iomanip>
#include <exception>
#include "MetadataDisplayVisitor.h"
#include "BasicDisplayVisitor.h"
#include "AbstractCommand.h"
using namespace std;


CatCommand::CatCommand(AbstractFileSystem* system) :fileSystem(system) {}

void CatCommand::displayInfo() {
	cout << "cat appends, or overwrites a file. use with -a for appending, no argument otherwise" << endl;
}

int CatCommand::execute(string filename) {
	try {
		// if the augment -a is given
		vector<char> input;
		BasicDisplayVisitor* displayVisitor = new BasicDisplayVisitor;
		if (filename.substr(filename.find_first_of(" \t") + 1) == "-a") {
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
			cout << endl;
			// continously get user input while :wq or :w is not typed
			while (1 == 1) {
				string line;
				getline(cin, line);
				if (line == ":q") {
					fileSystem->closeFile(file);
					return success;
				}
				else if (line == ":wq") {
					input.pop_back();
					int appendStatus = file->append(input);
					fileSystem->closeFile(file);
					if (appendStatus == 0) {
						return success;
					}
					return wrong_file_type;
				}
				std::copy(line.begin(), line.end(), std::back_inserter(input));
				input.push_back('\n');
				
			}
		}
		else {
			// if no augment is given
			string::size_type pos = filename.find(' ');
			filename = filename.substr(0, pos);
			AbstractFile* file = fileSystem->openFile(filename);
			if (file == nullptr) {
				cout << "\"" << filename << "\"" << " not found in the file system ";
				return wrongFileName;
			}
			while (1 == 1) {
				string line;
				getline(cin, line);
				if (line == ":q") {
					fileSystem->closeFile(file);
					return success;
				}
				else if(line == ":wq") {
					input.pop_back();
					int writeStatus = file->write(input);
					fileSystem->closeFile(file);
					if (writeStatus == 0) {
						return success;
					}
					return unexpectedException;
				}
				std::copy(line.begin(), line.end(), std::back_inserter(input));
				input.push_back('\n');
			}
		}

	}
	catch (...) {
		return unexpectedException;
	}
	return success;
}