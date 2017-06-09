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
	/*������ ���� �� ����������, �� ���� ����� ������� ������ �� ����������*/
	void showUnlikedChildren();
	/*������ ���� ���������� �����, �� ���� ���, 
	������� �� ���������� �� ������ ������� �� ���, ��� ���������� �� �����
	����������� ��� �����, ������� ����� �� ����������.*/
	void showUnluckyChildren();
	/*������ ����������, �� ���� ���� �����, 
	������� ���������� ������������� ���������� ������ �����.*/
	void showLikedChildren();
private:
	map <string, int> _childIDPairs;
	Matrix<bool> _sympathyMatrix;
	int _count = 0;
};

