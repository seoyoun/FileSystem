// studio 18 - simple file factory definitions
#include "SimpleFileFactory.h"
#include "AbstractFile.h"
#include "SimpleFileSystem.h"
#include <iostream>
#include <string>
#include <cstddef>
#include "TextFile.h"
#include "ImageFile.h"

using namespace std;

AbstractFile* SimpleFileFactory::createFile(std::string FileName) {
	size_t i = FileName.rfind('.', FileName.length());
	if (i != string::npos) {
		string exten = (FileName.substr(i + 1, FileName.length() - i));
		if (exten == "txt") {
			AbstractFile* tem = new TextFile(FileName);
			return tem;
		}
		if (exten == "img") {
			AbstractFile* tem = new ImageFile(FileName);
			return tem;
		}
	}

	return nullptr;


}


