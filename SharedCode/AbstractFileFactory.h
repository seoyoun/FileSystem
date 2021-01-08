/* File: AbstractFileFactory.h
   Authors: Yanpeng Yuan (yanpeng@wustl.edu), Ziwen Wang (ziwen.wang@wustl.edu), Sally Lee (sallylee@wustl.edu)
   Summary: declaration of the AbstractFileFactory base class
			AbstractFileFactory is the interface each concrete file factory will define.
   Studio 18
*/
#pragma once
#include "AbstractFile.h"


class AbstractFileFactory {
public:
	virtual AbstractFile* createFile(std::string) = 0;
};
