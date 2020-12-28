// definitions of basic display visitor here
#include "GrepVisitor.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
GrepVisitor::GrepVisitor(string q) :query(q) {}

bool GrepVisitor::visit_TextFile(TextFile* file) {

	vector<char> chars = file->read();
	string content(chars.begin(), chars.end());
	if (content.find(query) != std::string::npos) {
		return true;
	}
	return false;


}

