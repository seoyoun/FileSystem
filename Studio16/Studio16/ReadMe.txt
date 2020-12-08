Answer studio 16 questions here
1. Ziwen Wang, Yanpeng Yuan, Sally Lee
2. To decalre an interface, we need to declare a class name and any function to be used. 
3. (a)interface inheritance (b)private
4. code:
    auto a = TextFile("asd");
	std::vector<char> tem;
	tem.push_back('m');
	cout << tem[0] << endl;
	a.write(tem);
	a.read();
	return 0;

	output: m
	The textfile object call read() method to print m, as expected.
5. code: 