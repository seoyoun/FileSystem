/* File: ImageFile.h
   Authors: Yanpeng Yuan (yanpeng@wustl.edu), Ziwen Wang (ziwen.wang@wustl.edu), Sally Lee (sallylee@wustl.edu)
   Summary: declaration of the ImageFile class
			An ImageFile can be read, written to, copied, and displayed but cannot be appended.
			Its name and size can be accessed publicly.
			It is created through a SimpleFileFactory.
*/
#pragma once
#include "AbstractFile.h"
class ImageFile : public AbstractFile {
public:
	virtual std::vector<char> read();
	virtual int append(std::vector<char>);
	virtual unsigned int getSize();
	virtual std::string getName();
	int write(std::vector<char>);
	ImageFile(std::string);
	void accept(AbstractFileVisitor*);

	virtual AbstractFile* clone(std::string);
private:
	std::vector<char> contents;
	std::string name;
	char size;
	
};
