#pragma once
// declaration of SimpleFileSystem class goes here
#include <vector>
#include <string>
#include "AbstractFileSystem.h"
#include "AbstractFile.h"
#include "TextFile.h"
#include "ImageFile.h"
#include <map>
#include <set>

class SimpleFileSystem :public AbstractFileSystem {
private:
	std::map<std::string, AbstractFile*> FileMap;
	std::set<AbstractFile*>OpenFile;
public:
	
	int createFile(std::string) ;
	int deleteFile(std::string) ;
	 AbstractFile* openFile(std::string) ;
	int closeFile(AbstractFile*) ;
};