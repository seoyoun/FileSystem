/* File: RenameParsingStrategy.h
   Authors: Yanpeng Yuan (yanpeng@wustl.edu), Ziwen Wang (ziwen.wang@wustl.edu), Sally Lee (sallylee@wustl.edu)
   Summary: declaration of the RenameParsingStrategy class
			RenameParsingStrategy takes the singular input to the rename command 
			and separates the different inputs that should be passed to the copy and remove command the rename command is composed of.
*/
#pragma once
#include "AbstractParsingStrategy.h"


class RenameParsingStrategy : public AbstractParsingStrategy {
public:
	virtual std::vector<std::string> parse(std::string);
};
