/* File: AbstractFileVisitor.h
   Authors: Yanpeng Yuan (yanpeng@wustl.edu), Ziwen Wang (ziwen.wang@wustl.edu), Sally Lee (sallylee@wustl.edu)
   Summary: declaration of the AbstractFileVisitor base class
			AbstractFileVisitor is the interface each concrete file visitor will define.
*/
#pragma once
#include <vector>
#include <string>
#include "AbstractFile.h"
#include "TextFile.h"
#include "ImageFile.h"

class AbstractFileVisitor {
public:
	virtual void visit_TextFile(TextFile*) = 0;
	virtual void visit_ImageFile(ImageFile*) = 0;
};