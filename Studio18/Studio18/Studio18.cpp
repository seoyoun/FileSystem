// Studio18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <cstddef>
#include "..\..\\SharedCode\AbstractFileSystem.h"
#include "..\..\\SharedCode\SimpleFileFactory.h"
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include "..\..\\SharedCode\AbstractFile.h"

using namespace std;

int main()
{
	AbstractFileSystem * absSys= new SimpleFileSystem();

	AbstractFileFactory* absFactory = new SimpleFileFactory();

	AbstractFile* txt = absFactory->createFile("1.txt");
	vector<char> input;
	input.push_back('s');
	txt->write(input);
	absSys->addFile("1.txt", txt);
	AbstractFile* txt2 = absSys->openFile("1.txt");

	txt2->read();

	return 0;
}
