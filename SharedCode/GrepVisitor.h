#pragma once
// declaration of BasicDisplayVisitor here
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

