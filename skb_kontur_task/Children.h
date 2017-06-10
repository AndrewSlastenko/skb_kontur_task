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
	/*������ ���� �� ����������, �� ���� ����� ������� ������ �� ����������*/
	void showUnlovedChildren();
	/*������ ���� ���������� �����, �� ���� ���, 
	������� �� ���������� �� ������ ������� �� ���, ��� ���������� �� �����
	����������� ��� �����, ������� ����� �� ����������.*/
	void showUnhappyChildren();
	/*������ ����������, �� ���� ���� �����, 
	������� ���������� ������������� ���������� ������ �����.*/
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

