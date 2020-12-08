// Studio20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <cstddef>
#include "..\..\\SharedCode\AbstractFileSystem.h"
#include "..\..\\SharedCode\SimpleFileFactory.h"
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include "..\..\\SharedCode\AbstractFile.h"
#include "..\..\\SharedCode\PasswordProxy.h"
#include "..\..\\SharedCode\BasicDisplayVisitor.h"
int main()
{
	AbstractFileSystem* absSys = new SimpleFileSystem();

	AbstractFileFactory* absFactory = new SimpleFileFactory();

	AbstractFile* txt = absFactory->createFile("1.img");
	PasswordProxy tem(txt, "123");
	std::vector<char> input = { 'X', ' ', 'X', ' ', 'X', ' ', 'X',' ', 'X', '3' };
	tem.write(input);
	/*vector<char>output = tem.read();

	for (std::vector<char>::const_iterator i = output.begin(); i != output.end(); ++i) {
		std::cout << *i << ' ';
	}*/
	BasicDisplayVisitor* visitor = new BasicDisplayVisitor;

	tem.accept(visitor);
}

