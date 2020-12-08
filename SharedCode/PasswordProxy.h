#pragma once
#include "AbstractFile.h"
#include <string>
class PasswordProxy : public AbstractFile {
public:
	PasswordProxy(AbstractFile*, std::string);
	~PasswordProxy();
	vector<char> read();
	int write(std::vector<char>);
	int append(std::vector<char>);
	unsigned int getSize();
	std::string getName();
	void accept(AbstractFileVisitor*);

private:
	AbstractFile* pwdProtectedFile;
	std::string password;

protected:
	std::string passwordPrompt();

};