/* File: TextFile.h
   Authors: Yanpeng Yuan (yanpeng@wustl.edu), Ziwen Wang (ziwen.wang@wustl.edu), Sally Lee (sallylee@wustl.edu)
   Summary: declaration of the TextFile class
			A TextFile can be read, written to, appended, copied, and displayed.
			Its name and size can also be accessed publicly.
			It is created through a SimpleFileFactory.
*/
#pragma once
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