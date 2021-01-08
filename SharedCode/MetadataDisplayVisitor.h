/* File: MetadataDisplayVisitor.h
   Authors: Yanpeng Yuan (yanpeng@wustl.edu), Ziwen Wang (ziwen.wang@wustl.edu), Sally Lee (sallylee@wustl.edu)
   Summary: declaration of the MetadataDisplayVisitor class
			MetadataDisplayVisitor displays / prints the metadata of a TextFile or an ImageFile
*/
#pragma once
#include "AbstractFileVisitor.h"


class MetadataDisplayVisitor : public AbstractFileVisitor{
public:
	void visit_TextFile(TextFile*);
	void visit_ImageFile(ImageFile*);
};
