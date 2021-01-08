/* File: SimpleFileSystem.h
   Authors: Yanpeng Yuan (yanpeng@wustl.edu), Ziwen Wang (ziwen.wang@wustl.edu), Sally Lee (sallylee@wustl.edu)
   Summary: declaration of the SimpleFileSystem class
			SimpleFileSystem can add, open, close, and delete files
			SimpleFileSystem also allows access to the names of all files in it.
*/
#pragma once
#include "AbstractFileSystem.h"
#include <map>


class SimpleFileSystem :public AbstractFileSystem {
private:
	std::map<std::string, AbstractFile*> FileMap;
	std::set<AbstractFile*> OpenFile;
public:
	virtual int addFile(std::string, AbstractFile*);
	virtual std::set<std::string> getFileNames();
	virtual int deleteFile(std::string) ;
	virtual AbstractFile* openFile(std::string) ;
	virtual int closeFile(AbstractFile*) ;
};