/* File: AbstractCommand.h
   Authors: Yanpeng Yuan (yanpeng@wustl.edu), Ziwen Wang (ziwen.wang@wustl.edu), Sally Lee (sallylee@wustl.edu)
   Summary: declaration of the AbstractCommand base class
			AbstractCommand is the interface each concrete command will define.
			AbstractCommand also documents the return values of different errors a command may yield.
*/
#pragma once
#include<string>
class AbstractCommand {
public:
	virtual int execute(std::string) = 0;
	virtual void displayInfo() = 0;

	virtual ~AbstractCommand() = default;

};

enum cmdStatus { success = 0, unexpectedException = 1, wrongFileName = 2, userQuit = 3, cannot_open_file = 4, cannot_copy_file = 5, cannot_add_file = 6, 
	cmd_failed = 7, cannot_create_file = 8, wrong_file_type = 9};
