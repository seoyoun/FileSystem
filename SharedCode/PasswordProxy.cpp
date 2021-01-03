#include "PasswordProxy.h"
#include <iostream>
using namespace std;

PasswordProxy::PasswordProxy(AbstractFile* absFile, std::string pwd) : pwdProtectedFile(absFile), password(pwd) {

}

PasswordProxy::~PasswordProxy() {
	delete pwdProtectedFile;
}

string PasswordProxy::passwordPrompt() {
	cout << "please eneter the password" << endl;
	string input;
	getline(cin, input);
	return input;
}

vector<char> PasswordProxy::read() {
	string inputPwd = passwordPrompt();
	vector<char> empty;
	if (password == inputPwd) {
		return pwdProtectedFile->read();
	}
	return empty;
}


int PasswordProxy::write(vector<char> writtenStuff) {
	string inputPwd = passwordPrompt();
	vector<char> empty;
	if (password == inputPwd) {
		return pwdProtectedFile->write(writtenStuff);
	}
	return 1;
}


int PasswordProxy::append(vector<char> writtenStuff) {
	string inputPwd = passwordPrompt();
	vector<char> empty;
	if (password == inputPwd) {
		return pwdProtectedFile->append(writtenStuff);
	}
	return 1;
}



unsigned int PasswordProxy::getSize() {
	return pwdProtectedFile->getSize();
}


string PasswordProxy::getName() {
	return pwdProtectedFile->getName();
}


void PasswordProxy::accept(AbstractFileVisitor* file) {
	string inputPwd = passwordPrompt();
	if (password == inputPwd) {
		pwdProtectedFile->accept(file);
	}
}

AbstractFile* PasswordProxy::clone(string newFileName) {

	return new PasswordProxy(pwdProtectedFile->clone(newFileName), password);
}