#pragma once
#include <map>
#include <fstream>
#include <iostream>
#include <string>

#include "Matrix.h"
#include "EmptyFile.h"
#include "InvalidNameOfChild.h"


using std::string;

class Children
{
public:
	Children() = delete;
	Children(string, string);
	~Children() = default;
	/*список всех не любимчиков, то есть детей которые никому не симпатичны*/
	void showUnlovedChildren();
	/*список всех несчастных детей, то есть тех, 
	которые не симпатичны ни одному ребенку из тех, кто симпатичен им самим
	исключением тех детей, которым никто не симпатичен.*/
	void showUnhappyChildren();
	/*список любимчиков, то есть всех детей, 
	которые симпатичны максимальному количеству других детей.*/
	void showLovedChildren();
private:
	std::map<string, int> _childIDPairs;
	Matrix<bool> *_sympathyMatrix;
	int _count = 0;

	void readChildrenFromFile(string);
	void readSympathyFromFile(string);
	void insertNewChild(string);
	void setNewSympathy(string, string);
	int getNameId(string);
};

