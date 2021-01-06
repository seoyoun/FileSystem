#pragma once
// declaration of the interface all file systems provide goes here

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