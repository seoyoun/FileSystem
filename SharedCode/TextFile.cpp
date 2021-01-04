//  Define the TextFile class here
#include "TextFile.h"
#include <vector>
#include <iostream>
#include"AbstractFileVisitor.h"

using namespace std;


TextFile::TextFile(std::string name) :name{ name } {
};


unsigned int TextFile::getSize() {
	return unsigned int(contents.size());
}


std::string TextFile::getName() {
	return name;

}

int TextFile::write(std::vector<char> name) {
	try { contents = name; }
	catch (...) {
		return 1;
	}
	return 0;
}


int TextFile::append(std::vector<char> appenditem) {
	try { contents.insert(contents.end(), appenditem.begin(), appenditem.end()); }
	catch (...) {
		return 1;
	}
	return 0;
}


vector<char> TextFile::read() {
	return contents;
}

void TextFile::accept(AbstractFileVisitor* visitor) {
	visitor->visit_TextFile(this);

}

AbstractFile* TextFile::clone(string newFileName) {
	AbstractFile* newFile = new TextFile(newFileName + ".txt");
	newFile->write(contents);
	return newFile;
}