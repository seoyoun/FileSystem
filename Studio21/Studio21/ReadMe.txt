Studio 21 ReadMe.txt 
2. So that all derived classes of the base class can also be destroyed, it avoid slicing and ensures that destruction starts at the most derived class.
3. Different implementations of the file system and file fatory can inject themselves into the command prompt object in the form of a pointer. This way, the command prompt itself does not have to care about what kind of system it is interacting with, and thus no modification or configuration is required when a different file system is used.
