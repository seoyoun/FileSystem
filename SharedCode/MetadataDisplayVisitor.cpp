// definitions of metadata visitor here
#include "MetadataDisplayVisitor.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void MetadataDisplayVisitor::visit_TextFile(TextFile* txt) {
	cout << left << setw(20) << txt->getName()<<flush;
	cout << left << setw(10) << "text" << flush;
	cout << left << setw(20) << txt->getSize() << endl;
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* img) {
	cout <<left<<setw(20)<< img->getName() << flush;
	cout << left << setw(10)<< "image" << flush;
	cout << left << setw(20) << img->getSize() << endl;

}