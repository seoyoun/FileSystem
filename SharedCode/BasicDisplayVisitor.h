#pragma once
// declaration of BasicDisplayVisitor here
#include "AbstractFileVisitor.h"
#include "ImageFile.h"
#include "TextFile.h"

class BasicDisplayVisitor : public AbstractFileVisitor{
public:
	void visit_TextFile(TextFile*);
	void visit_ImageFile(ImageFile*);
};

