// Studio17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

using namespace std;
#include "..\..\\SharedCode\ImageFile.h"

int main()
{
	auto a = ImageFile("asd");
	std::vector<char> tem;
	for (int i = 0; i < 9; ++i) {
		tem.push_back('X');
	}
	tem.push_back('3');
	a.write(tem);
	a.read();
	return 0;
}

