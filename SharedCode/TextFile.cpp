//  Define the TextFile class here
#include "TextFile.h"
#include <vector>
#include <iostream>
#include"AbstractFileVisitor.h"
TextFile::TextFile(std::string name):name{ name } {
};
unsigned int TextFile::getSize(){
	return contents.size();
}
std::string TextFile::getName() {
	return name;

}

int TextFile::write(std::vector<char> name) {
	try{ contents = name; }
	catch (...) {
		return 1;
	}
	return 0;
	/*if (contents == name) {
		return 0;
	}*/
}
int TextFile::append(std::vector<char> appenditem) {
	try{ contents.insert(contents.end(), appenditem.begin(), appenditem.end()); }
	catch (...) {
		return 1;
	}
	return 0;
}
vector<char> TextFile::read() {
	//for (int i = 0; i < contents.size(); ++i) {
	//	cout << contents[i]<<flush;
	//}
	return contents;
}

void TextFile::accept(AbstractFileVisitor* visitor) {
	visitor->visit_TextFile(this);

}