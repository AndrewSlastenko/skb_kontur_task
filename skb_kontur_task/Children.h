#pragma once
#include <map>
#include <fstream>
#include <iostream>
#include <string>
#include "Matrix.h"

using std::string;
using std::map;

class Children
{
public:
	Children();
	~Children();
	void readChildrenFromFile(string);
	void readSympathyFromFile(string);
	void insertNewChild(string);
	void setNewSympathy(string, string);
	int getNameId(string);
	/*список всех не любимчиков, то есть детей которые никому не симпатичны*/
	void showUnlikedChildren();
	/*список всех несчастных детей, то есть тех, 
	которые не симпатичны ни одному ребенку из тех, кто симпатичен им самим
	исключением тех детей, которым никто не симпатичен.*/
	void showUnluckyChildren();
	/*список любимчиков, то есть всех детей, 
	которые симпатичны максимальному количеству других детей.*/
	void showLikedChildren();
private:
	map <string, int> _childIDPairs;
	Matrix<bool> _sympathyMatrix;
	int _count = 0;
};

