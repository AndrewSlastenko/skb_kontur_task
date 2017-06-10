#pragma once
#include <map>
#include <fstream>
#include <iostream>
#include <string>

#include "Matrix.h"
#include "EmptyFile.h"
#include "InvalidNameOfChild.h"

typedef unsigned char bool_t; //����� �� �������������� ������������� vector<bool>

class Children
{
public:
	Children() = delete;
	Children(std::string pathToNames, std::string pathToSympathy);
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
	std::map<std::string, int> _childIDPairs;
	Matrix<bool_t> _sympathyMatrix;
	int _count = 0;

	void readChildrenFromFile(std::string);
	void readSympathyFromFile(std::string);
	void insertNewChild(std::string);
	void setNewSympathy(std::string, std::string);
	int getNameId(std::string);
};
