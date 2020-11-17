// Studio16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\\SharedCode\TextFile.h"
#include <iostream>
using namespace std;


int main()
{
	auto a = TextFile("asd");
	std::vector<char> tem;
	tem.push_back('tem');
	a.write(tem);
	a.read();
	return 0;
}


