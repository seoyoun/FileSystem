#pragma once
// declaration of BasicDisplayVisitor here
#include "ImageFile.h"
#include "TextFile.h"
#include "AbstractFileVisitor.h"
class BasicDisplayVisitor : public AbstractFileVisitor{
public:
	void visit_TextFile(TextFile*);
	void visit_ImageFile(ImageFile*);
};

