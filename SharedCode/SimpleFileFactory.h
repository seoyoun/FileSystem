/* File: SimpleFileFactory.h
   Authors: Yanpeng Yuan (yanpeng@wustl.edu), Ziwen Wang (ziwen.wang@wustl.edu), Sally Lee (sallylee@wustl.edu)
   Summary: declaration of the SimpleFileFactory class.
			SimpleFileFactory creates a TextFile or an ImageFile.
   Studio 18
*/
#pragma once
#include "AbstractFileFactory.h"


class SimpleFileFactory :public AbstractFileFactory {
public:
	AbstractFile* createFile(std::string);

};