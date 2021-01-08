/* File: MetadataDisplayVisitor.cpp
   Authors: Yanpeng Yuan (yanpeng@wustl.edu), Ziwen Wang (ziwen.wang@wustl.edu), Sally Lee (sallylee@wustl.edu)
   Summary: defintions of the MetadataDisplayVisitor class member functions
			MetadataDisplayVisitor displays / prints the metadata of a TextFile or an ImageFile
*/
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