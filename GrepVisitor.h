#pragma once
// declaration of BasicDisplayVisitor here
#include "TextFile.h"
#include "AbstractFileVisitor.h"
class GrepVisitor : public AbstractFileVisitor {

public:
	GrepVisitor(string);
	bool visit_TextFile(TextFile*);
private:
	string query;
};

