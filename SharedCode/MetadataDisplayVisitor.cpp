// definitions of metadata visitor here
#include "MetadataDisplayVisitor.h"
#include <iostream>
#include <string>
using namespace std;

void MetadataDisplayVisitor::visit_TextFile(TextFile* txt) {
	cout << txt->getName()<<endl;
	cout << "text" << endl;
	cout << txt->getSize() << endl;
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* img) {
	cout << img->getName() << endl;
	cout << "image" << endl;
	cout << img->getSize() << endl;

}