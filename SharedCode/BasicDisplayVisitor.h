/* File: BasicDisplayVisitor.h
   Authors: Yanpeng Yuan (yanpeng@wustl.edu), Ziwen Wang (ziwen.wang@wustl.edu), Sally Lee (sallylee@wustl.edu)
   Summary: declaration of the BasicDisplayVisitor class
			BasicDisplayVisitor displays / prints the contents of a TextFile or an ImageFile.
*/
#pragma once
#include "AbstractFileVisitor.h"
#include "ImageFile.h"
#include "TextFile.h"

class BasicDisplayVisitor : public AbstractFileVisitor{
public:
	void visit_TextFile(TextFile*);
	void visit_ImageFile(ImageFile*);
};

