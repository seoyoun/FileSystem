studio 18 answers here

2. The factory method decoupples the create file function from the manage file function. So it is easier for us to add new file types in the future, we only need to change the implementation of the factory instead of the entire file system. If a new file type is implemented, and if it uses abstractfile interface, then we can just use the old implementation, except for the createFIle method, so it would be relatively easy.

3. The factory pattern allows us to decoupple the create object functionality from the rest of the implementation, therefore reducing the work needed when adding new file types in the future. One disadvantage is that you still need to change the factory implementation itself when adding new files, sepecifically, in the createFile method, to check for the new extension. We can, and that is another one of the benefits of this pttern. No, because as aforementioned, different files requires different implementatons of the factory.

4. We tried to use the fileFactory to create a text file, add it to the file system, add it, open it, then write to it, then read it and it all works.

	AbstractFileSystem * absSys= new SimpleFileSystem();

	AbstractFileFactory* absFactory = new SimpleFileFactory();

	AbstractFile* txt = absFactory->createFile("1.txt");
	vector<char> input;
	input.push_back('s');
	txt->write(input);
	absSys->addFile("1.txt", txt);
	AbstractFile* txt2 = absSys->openFile("1.txt");

	txt2->read();

	return: s;

	5. It only depends on the interface.


	

