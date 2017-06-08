#pragma once
#include <map>

using std::string;
using std::map;

class Children
{
public:
	Children();
	~Children();
	void readChildrenFromFile(string pathToFile);
	void readSympathyFromFile(string pathToFile);
private:
	map <string, int> _childIDPairs;

};

