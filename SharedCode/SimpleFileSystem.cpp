// define methods of SimpleFileSystem class here
#include "SimpleFileSystem.h"
int SimpleFileSystem::addFile(std::string InsertFile, AbstractFile* a) {
	if (FileMap.find(InsertFile) == FileMap.end() || a == nullptr) {
		return 1;
	}
	FileMap.insert({ InsertFile,a });
	return 0;
}
int SimpleFileSystem::createFile(std::string FileName) {
	if (FileMap.find(FileName) == FileMap.end()) {
		return 1;
	}
	size_t i = FileName.rfind('.', FileName.length());
	if (i != string::npos) {
		string exten=(FileName.substr(i + 1, FileName.length() - i));
		if (exten == "txt") {
			AbstractFile* tem =new TextFile(FileName);
			return addFile(FileName, tem);
		}
		if (exten == "img") {
			AbstractFile* tem = new ImageFile(FileName);
			return addFile(FileName, tem);
		}
	}

	return 1;
}
AbstractFile* SimpleFileSystem::openFile(std::string FileName) {
	if (FileMap.find(FileName) == FileMap.end()) {

		if (OpenFile.find(FileMap.at(FileName)) != OpenFile.end()) {
			OpenFile.insert(FileMap.at(FileName));
			return 0;
		}
		else {
			return nullptr;
		}
	}
	return nullptr;
}
int SimpleFileSystem::closeFile(AbstractFile* ClosedFile) {
	if (OpenFile.find(ClosedFile) != OpenFile.end()) {
		OpenFile.erase(ClosedFile);
		return 0;
	}
	return 1;
}
int SimpleFileSystem::deleteFile(std::string FileName) {
	if (FileMap.find(FileName) == FileMap.end()) {
		if (OpenFile.find(FileMap.at(FileName)) != OpenFile.end()) {
			FileMap.erase(FileName);
			delete FileMap.at(FileName);
		}
		else {
			return 1;
		}
	}
	return 1;
}