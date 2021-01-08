/* File: PasswordProxy.h
   Authors: Yanpeng Yuan (yanpeng@wustl.edu), Ziwen Wang (ziwen.wang@wustl.edu), Sally Lee (sallylee@wustl.edu)
   Summary: declaration of the PasswordProxy class 
			PasswordProxy protects an AbstractFile with a password
*/
#pragma once
#include "AbstractFile.h"
#include <string>


class PasswordProxy : public AbstractFile {
public:
	PasswordProxy(AbstractFile*, std::string);
	~PasswordProxy();
	std::vector<char> read();
	int write(std::vector<char>);
	int append(std::vector<char>);
	unsigned int getSize();
	std::string getName();
	void accept(AbstractFileVisitor*);

	virtual AbstractFile* clone(std::string);

private:
	AbstractFile* pwdProtectedFile;
	std::string password;

protected:
	std::string passwordPrompt();

};