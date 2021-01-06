// define methods of SimpleFileSystem class here
#include "SimpleFileSystem.h"
#include <iostream>
using namespace std;



int SimpleFileSystem::addFile(std::string InsertFile, AbstractFile* a) {
	//checks file does not already exist, file is not nullptr
	if (FileMap.find(InsertFile) != FileMap.end() || a == nullptr) {
		return 1;
	}
	FileMap[InsertFile] = a;
	return 0;
}



AbstractFile* SimpleFileSystem::openFile(std::string FileName) {
	if (FileMap.find(FileName) == FileMap.end()) {
		return nullptr;
	}
	if (OpenFile.find(FileMap[FileName]) != OpenFile.end()) {
		return nullptr;
	}
	
			OpenFile.insert(FileMap[FileName]);
			return FileMap[FileName];

}


int SimpleFileSystem::closeFile(AbstractFile* ClosedFile) {
	if (OpenFile.find(ClosedFile) != OpenFile.end()) {
		OpenFile.erase(ClosedFile);
		return 0;
	}
	return file_is_open;
}



int SimpleFileSystem::deleteFile(std::string FileName) {
	if (FileMap.find(FileName) != FileMap.end()) {
		if (OpenFile.find(FileMap[FileName]) == OpenFile.end()) {
			
			delete FileMap[FileName];
			FileMap.erase(FileName);
			return 0;
		}
		else {
			return file_is_open; //file is open
		}
	}
	return file_does_not_exist; //file not in system
}



set<string> SimpleFileSystem::getFileNames() {
	set<string> s;
	for (auto it = FileMap.begin(); it != FileMap.end(); ++it) {
		auto i = it->first;
		s.insert(i);
	}
	return s;
}