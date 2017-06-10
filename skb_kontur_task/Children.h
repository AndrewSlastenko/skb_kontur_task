#pragma once
#include <map>
#include <fstream>
#include <iostream>
#include <string>

#include "Matrix.h"
#include "EmptyFile.h"
#include "InvalidNameOfChild.h"

typedef unsigned char bool_t; //чтобы не использовалась специализаци€ vector<bool>

class Children
{
public:
	Children() = delete;
	Children(std::string pathToNames, std::string pathToSympathy);
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
	std::map<std::string, int> _childIDPairs;
	Matrix<bool_t> _sympathyMatrix;
	int _count = 0;

	void readChildrenFromFile(std::string);
	void readSympathyFromFile(std::string);
	void insertNewChild(std::string);
	void setNewSympathy(std::string, std::string);
	int getNameId(std::string);
};
