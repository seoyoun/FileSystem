#pragma once
// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary
#include <vector>
#include <string>
//#include "AbstractFileVisitor.h"
class AbstractFileVisitor;
using namespace std;
class AbstractFile {
public:
	virtual vector<char> read()=0;
	virtual int write(std::vector<char>)=0;
	virtual int append(std::vector<char>)=0;
	virtual unsigned int getSize() = 0;
	virtual std::string getName() = 0;
	virtual ~AbstractFile() = default;
	virtual void accept(AbstractFileVisitor*) = 0;
};
