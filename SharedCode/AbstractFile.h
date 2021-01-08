/* File: AbstractFile.h
   Authors: Yanpeng Yuan (yanpeng@wustl.edu), Ziwen Wang (ziwen.wang@wustl.edu), Sally Lee (sallylee@wustl.edu)
   Summary: declaration of the AbstractFile base class
			AbstractFile is the interface each concrete file will define.
*/
#pragma once
#include <vector>
#include <string>
class AbstractFileVisitor;

class AbstractFile {
public:
	virtual std::vector<char> read() = 0;
	virtual int write(std::vector<char>) = 0;
	virtual int append(std::vector<char>) = 0;
	virtual unsigned int getSize() = 0;
	virtual std::string getName() = 0;
	virtual ~AbstractFile() = default;
	virtual void accept(AbstractFileVisitor*) = 0;


	virtual AbstractFile* clone(std::string) = 0; ///prototype pattern for CopyCommand
};


