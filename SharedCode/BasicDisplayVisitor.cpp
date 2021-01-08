/* File: BasicDisplayVisitor.cpp
   Authors: Yanpeng Yuan (yanpeng@wustl.edu), Ziwen Wang (ziwen.wang@wustl.edu), Sally Lee (sallylee@wustl.edu)
   Summary: definitions of the BasicDisplayVisitor class member functions.
			BasicDisplayVisitor displays / prints the contents of a TextFile or an ImageFile.
*/
#include "BasicDisplayVisitor.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

void BasicDisplayVisitor::visit_TextFile(TextFile* txt) {
	vector<char> contents = txt->read();
	for (unsigned int i = 0; i < txt->getSize(); ++i) {
	cout << contents[i]<<flush;
	}
}


void BasicDisplayVisitor::visit_ImageFile(ImageFile* img) {
	int length = int(sqrt(img->getSize()));
	vector<char> contents = img->read();

	for (int i = length - 1; i >= 0; --i) {
		for (int j = 0; j < length; ++j) {
			cout << contents[i * length + j] << flush;
		}
		cout << endl;
	}
}