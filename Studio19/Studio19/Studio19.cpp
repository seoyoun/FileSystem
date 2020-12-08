// Studio19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstddef>
#include "..\..\\SharedCode\AbstractFileSystem.h"
#include "..\..\\SharedCode\SimpleFileFactory.h"
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include "..\..\\SharedCode\AbstractFile.h"

#include "..\..\\SharedCode\BasicDisplayVisitor.h"

using namespace std;

int main()
{
	AbstractFileSystem* absSys = new SimpleFileSystem();

	AbstractFileFactory* absFactory = new SimpleFileFactory();

	AbstractFile* txt = absFactory->createFile("1.img");
	/*vector<char>output = txt->read();

	for (std::vector<char>::const_iterator i = output.begin(); i != output.end(); ++i) {
		std::cout << *i << ' ';
	}*/
	std::vector<char> input = { 'X', ' ', 'X', ' ', 'X', ' ', 'X',' ', 'X', '3' };
	txt->write(input);
	absSys->addFile("1.img", txt);
	AbstractFile* txt2 = absSys->openFile("1.img");

	/*vector<char>output=txt->read();
	
	for (std::vector<char>::const_iterator i = output.begin(); i != output.end(); ++i) {
		std::cout << *i << ' ';
	}*/

	BasicDisplayVisitor* visitor = new BasicDisplayVisitor;
	
	txt2->accept(visitor);
	


	return 0;
}
