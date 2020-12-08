#pragma once
// declaration of MetadataDisplayVisitor here
#include "ImageFile.h"
#include "TextFile.h"
#include "AbstractFileVisitor.h"
class MetadataDisplayVisitor : public AbstractFileVisitor{
public:
	void visit_TextFile(TextFile*);
	void visit_ImageFile(ImageFile*);
};
