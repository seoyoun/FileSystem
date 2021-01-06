// definition of ImageFile class here
#include "ImageFile.h"
#include <vector>
#include <iostream>
#include "AbstractFileVisitor.h"

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
		file.push_back(0);
	}
	modifiedcontents = file;
	size = file.back();
	int length = (int)(size)-48;

	vector<char> checkedFile = file;

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
	vector<char> newvector = modifiedcontents;
	
	
	char length = (char)getSize();
	cout << length << endl;

	
	cout << endl;
	newFile->write(newvector);



	return newFile;
}