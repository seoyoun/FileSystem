#pragma once
//  Authors: Yanpeng Yuan (yanpeng@wustl.edu), Ziwen Wang (ziwen.wang@wustl.edu), Sally Lee (sallylee@wustl.edu)
// declaration of GrepVisitor is here

#include "TextFile.h"
#include "AbstractFileVisitor.h"
class GrepVisitor : public AbstractFileVisitor {

public:
	GrepVisitor(string);
	void visit_TextFile(TextFile*);
	void visit_ImageFile(ImageFile*);
	bool isInFile();
private:
	string query;
	bool inFile;
};

