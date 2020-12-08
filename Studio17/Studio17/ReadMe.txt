Answer the studio 17 questions here.
1. Ziwen Wang, Yanpeng Yuan, Sally Lee
2.int main()
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
output: 
XXX
XXX
XXX
as expected
3. With "programming a client to use an interface rather than a concrete class", we can have more flexibility in the future. The client will work files of any type.
4. In createFile(), addinge a new type of extension.