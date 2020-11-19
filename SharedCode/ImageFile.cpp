// definition of ImageFile class here
#include "ImageFile.h"
#include <vector>
#include <iostream>
ImageFile::ImageFile(std::string name) :name{ name }, size{ 0 } {
};
unsigned int ImageFile::getSize() {
	return contents.size();
}
std::string ImageFile::getName() {
	return name;

}
int ImageFile::write(std::vector<char> file) {
	size = file.back();
	int length = (int)(size)-48;
	for (int i = 0; i < file.size()-1; ++i) {
		if (length*length!=(file.size()-1)||(file[i] != 'X' && file[i] != ' ')) {
			contents.clear();
			size = '0';
			return 1;
		}
		contents.push_back(file[i]);
	}
	return 0;
};
int ImageFile::append(std::vector<char> appenditem) {
	return 1;
}
void ImageFile::read() {
	int length = (int)(size)-48;
	for (int i = length - 1; i >= 0; --i) {
		for (int j = 0; j < length; ++j) {
			cout << contents[i * length + j]<<flush;
		}
		cout << endl;
	}
};
