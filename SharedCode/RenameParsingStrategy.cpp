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