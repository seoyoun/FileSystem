/* File: RenameParsingStrategy.cpp
   Authors: Yanpeng Yuan (yanpeng@wustl.edu), Ziwen Wang (ziwen.wang@wustl.edu), Sally Lee (sallylee@wustl.edu)
   Summary: definition of the RenameParsingStrategy class's parse() function
			RenameParsingStrategy takes the singular input to the rename command
			and separates the different inputs that should be passed to the copy and remove command the rename command is composed of.
*/
#include "RenameParsingStrategy.h"
#include <sstream>
using namespace std;

vector<string> RenameParsingStrategy::parse(string input) {
	istringstream iss(input);
	string existing_file, new_name;
	iss >> existing_file >> new_name;
	vector<string> parsed;
	parsed.push_back(input);
	parsed.push_back(existing_file);
	return parsed;

}