#pragma once
// declaration of SimpleFileSystem class goes here
#include "AbstractFileSystem.h"
#include <map>


class SimpleFileSystem :public AbstractFileSystem {
private:
	std::map<std::string, AbstractFile*> FileMap;
	std::set<AbstractFile*> OpenFile;
public:
	virtual int addFile(std::string, AbstractFile*);
	virtual std::set<std::string> getFileNames() override;
	virtual int deleteFile(std::string) ;
	virtual AbstractFile* openFile(std::string) ;
	virtual int closeFile(AbstractFile*) ;
};