// definitions of basic display visitor here
#include "BasicDisplayVisitor.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

void BasicDisplayVisitor::visit_TextFile(TextFile* txt) {
	vector<char> contents = txt->read();
	for (int i = 0; i < txt->getSize(); ++i) {
	cout << contents[i]<<flush;
	}

}
void BasicDisplayVisitor::visit_ImageFile(ImageFile* img) {
	int length = sqrt(img->getSize());
	vector<char> contents = img->read();

	//for (std::vector<char>::const_iterator i = contents.begin(); i != contents.end(); ++i)
	//std::cout << *i << ' ';
	/*cout << " other length: "<<length<<endl;*/


	for (int i = length - 1; i >= 0; --i) {
		for (int j = 0; j < length; ++j) {
			cout << contents[i * length + j]<<flush;
		}
		cout << endl;
	}
}