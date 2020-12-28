#include "CatCommand.h"
#include <iostream>
#include <iomanip>
#include <exception>
#include "MetadataDisplayVisitor.h"
#include "BasicDisplayVisitor.h"
using namespace std;


CatCommand::CatCommand(AbstractFileSystem* system) :fileSystem(system) {}

void CatCommand::displayInfo() {
	cout << "cat appends, or overwrites a file. use with -a for appending, no argument otherwise" << endl;
}

int CatCommand::execute(string filename) {
	try {
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
			input.push_back('\n');
			while (1 == 1) {
				string line;
				getline(cin, line);
				if (line == ":q") {
					fileSystem->closeFile(file);
					return success;
				}
				else if (line == ":wq") {
					file->append(input);
					//cout << "-------" << endl;
					//file->accept(displayVisitor);
					//cout << "-------" << endl;
					fileSystem->closeFile(file);
					return success;
				}
				std::copy(line.begin(), line.end(), std::back_inserter(input));
				input.push_back('\n');
			}
		}
		else {
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
					file->write(input);
					//cout << "-------" << endl;
					//file->accept(displayVisitor);
					//cout << "-------" << endl;
					fileSystem->closeFile(file);
					return success;
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