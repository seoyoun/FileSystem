#pragma once
// TextFile declaration goes here
#include "AbstractFile.h"
class TextFile : public AbstractFile {
public:
	virtual void read() ;
	virtual int write(std::vector<char>) ;
	virtual int append(std::vector<char>);
	virtual unsigned int getSize();
	virtual std::string getName() ;

	TextFile(std::string);
private:
	std::vector<char> contents;
	std::string name;
};