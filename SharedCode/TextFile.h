#pragma once
// TextFile declaration goes here
#include "AbstractFile.h"
class TextFile : public AbstractFile {
public:
	virtual std::vector<char> read();
	virtual int write(std::vector<char>);
	virtual int append(std::vector<char>);
	virtual unsigned int getSize();
	virtual std::string getName();
	void accept(AbstractFileVisitor*);
	TextFile(std::string);

	virtual AbstractFile* clone(std::string);
private:
	std::vector<char> contents;
	std::string name;
};