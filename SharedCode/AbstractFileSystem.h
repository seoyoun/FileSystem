/* File: AbstractFileSystem.h
   Authors: Yanpeng Yuan (yanpeng@wustl.edu), Ziwen Wang (ziwen.wang@wustl.edu), Sally Lee (sallylee@wustl.edu)
   Summary: declaration of the AbstractFileSystem base class
			AbstractFileSystem is the interface each concrete file system will define.
*/
#pragma once
#include "AbstractFile.h"
#include <string>
#include <set>




class AbstractFileSystem {
public:
	virtual int addFile(std::string, AbstractFile*) = 0;
	
	virtual int deleteFile(std::string) = 0;
	virtual AbstractFile* openFile(std::string) = 0;
	virtual int closeFile(AbstractFile*) = 0;
	virtual std::set<std::string> getFileNames() = 0;
};

enum fileSystemStatus{file_does_not_exist = 10, file_is_open = 11};