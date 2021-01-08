/* File: ImageFile.cpp
   Authors: Yanpeng Yuan (yanpeng@wustl.edu), Ziwen Wang (ziwen.wang@wustl.edu), Sally Lee (sallylee@wustl.edu)
   Summary: definitions of the ImageFile class member functions
			An ImageFile can be read, written to, copied, and displayed but cannot be appended.
			Its name and size can be accessed publicly.
			It is created through a SimpleFileFactory.
*/
#include "ImageFile.h"
#include <vector>
#include <iostream>
#include "AbstractFileVisitor.h"
#include <math.h>

using namespace std;

ImageFile::ImageFile(std::string name) :name{ name }, size{ 0 } {
}


unsigned int ImageFile::getSize() {
	return unsigned int(contents.size());
}


std::string ImageFile::getName() {
	return name;
}


int ImageFile::write(std::vector<char> file) {
	if (file.empty()) {
		file.push_back('0');
	}
	
	size = file.back();
	int length = (int)(size)-48;

	vector<char> checkedFile = file;
	contents.clear();
	for (int i = 0; i < checkedFile.size() - 1; ++i) {
		if (length * length != (checkedFile.size() - 1) || (checkedFile[i] != 'X' && checkedFile[i] != ' ')) {
			contents.clear();
			size = '0';
			cout << "can not write as image" << endl;
			return 1;
		}
		contents.push_back(checkedFile[i]);
	}
	
	return 0;
}


int ImageFile::append(std::vector<char> appenditem) {
	return 1;
}


vector<char> ImageFile::read() {
	return contents;
}

void ImageFile::accept(AbstractFileVisitor* visitor) {
	visitor->visit_ImageFile(this);

}

AbstractFile* ImageFile::clone(string newFileName) {
	
	AbstractFile* newFile = new ImageFile(newFileName + ".img");
	
	
	if (contents.size() != 0) {
		contents.push_back(size);
	}
	
	newFile->write(contents);



	return newFile;
}