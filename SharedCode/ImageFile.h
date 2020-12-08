#pragma once
// Image file class declaration here
#include "AbstractFile.h"
class ImageFile : public AbstractFile {
public:
	virtual vector<char> read();
	virtual int append(std::vector<char>);
	virtual unsigned int getSize();
	virtual std::string getName();
	int write(std::vector<char>);
	ImageFile(std::string);
	void accept(AbstractFileVisitor*);
private:
	std::vector<char> contents;
	std::string name;
	char size;
};
