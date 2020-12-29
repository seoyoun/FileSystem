// Authors: Yanpeng Yuan (yanpeng@wustl.edu), Ziwen Wang (ziwen.wang@wustl.edu), Sally Lee (sallylee@wustl.edu)
// definitions of visitor for the grep command is here
#include "GrepVisitor.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
GrepVisitor::GrepVisitor(string q) :query(q),inFile(false) {}

void GrepVisitor::visit_TextFile(TextFile* file) {
	//convert file content and search for substring 
	vector<char> chars = file->read();
	string content(chars.begin(), chars.end());
	if (content.find(query) != std::string::npos) {
		inFile = true;
	}
	else {
		inFile = false;
	}
}

// to avoid checking image files
void GrepVisitor::visit_ImageFile(ImageFile* file) {
	inFile = false;
}

bool GrepVisitor::isInFile() {
	return inFile;
}