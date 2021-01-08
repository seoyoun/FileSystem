/* File: AbstractParsingStrategy.h
   Authors: Yanpeng Yuan (yanpeng@wustl.edu), Ziwen Wang (ziwen.wang@wustl.edu), Sally Lee (sallylee@wustl.edu)
   Summary: declaration of the AbstractParsingStrategy base class
			AbstractParsingStrategy is the interface each concrete parsing strategy will define.
*/
#pragma once
#include <string>
#include <vector>
class AbstractParsingStrategy {
public:
	virtual std::vector<std::string> parse(std::string) = 0;
};


