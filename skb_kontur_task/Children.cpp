#include "Children.h"

using std::string;
using std::getline;

Children::Children(string pathToNames, string pathToSympathy) {
	readChildrenFromFile(pathToNames);
	_sympathyMatrix = Matrix<bool_t>(_childIDPairs.size());
	readSympathyFromFile(pathToSympathy);
}


int Children::getNameId(string name) {
	auto it = _childIDPairs.find(name);
	/*if (it == _childIDPairs.end())
		throw InvalidNameOfChild(name);*/
	return it->second;
}

void Children::readChildrenFromFile(string pathToFile) {
	std::ifstream file(pathToFile);
	std::string name;
	int numOfLines = 0;
	while (getline(file, name)) {
		insertNewChild(name);
		++numOfLines;
	}
	if (numOfLines == 0)
		throw EmptyFile(pathToFile);
}


void Children::readSympathyFromFile(string pathToFile) {
	std::ifstream file(pathToFile);
	string tempString;
	string from;
	string to;
	bool args;
	int numOfLines = 0;
	while (std::getline(file, tempString)) {
		args = false;
		for (char symb : tempString) {
			switch (symb) {
			case ':':
				args = true;
				break;
			case ',':
				if (from != to)
					setNewSympathy(from, to);
				to = "";
				break;
			case ';':
				if (from != to)
					setNewSympathy(from, to);
				from = "";
				to = "";
				break;
			case ' ':
				//������ �������� ���� ��������
				break;
			default:
				if (!args) {
					from += symb;
				}
				else {
					to += symb;
				}
				break;
			}
		}
		++numOfLines;
	}
	if (numOfLines == 0)
		throw EmptyFile(pathToFile);
}


void Children::insertNewChild(string name) {
	_childIDPairs.insert(std::pair<string, int>(name, _count));
	++_count;
}


void Children::setNewSympathy(string nameFrom, string nameTo) {
	_sympathyMatrix.at(getNameId(nameFrom), getNameId(nameTo)) = true;
}


/*������ ���� �� ����������, �� ���� ����� ������� ������ �� ����������*/
void Children::showUnlovedChildren() {
	std::map <string, int> tempMap; //����� �������� �� ������ ����� (������ ��� �� �����)
	bool unlikeFlag = true;
	for (auto const &child : _childIDPairs) {
		unlikeFlag = true;
		for (int i = 0; i < _count; i++) {
			if (_sympathyMatrix.at(i, child.second)) {
				unlikeFlag = false;
				break;
			}
		}
		if (unlikeFlag) {
			tempMap.insert(child);
		}
	}
	std::cout << "|-----------The most unloved kids-------------" << std::endl;
	for (auto const &unlikedChild : tempMap) {
		std::cout << "|	" << unlikedChild.first << std::endl;
	}
}


/*������ ���� ���������� �����, �� ���� ���,
������� �� ���������� �� ������ ������� �� ���, ��� ���������� �� �����
����������� ��� �����, ������� ����� �� ����������.*/
void Children::showUnhappyChildren() {
	int numOfSymp = 0;
	bool unluckyFlag = true;
	std::map <string, int> tempMap;
	for (auto const &child : _childIDPairs) {
		unluckyFlag = true;
		numOfSymp = 0;
		for (int i = 0; i < _count; i++) {
			if (_sympathyMatrix.at(child.second, i) && _sympathyMatrix.at(i, child.second)) {
				unluckyFlag = false;
				++numOfSymp;
				break;
			}
			else if (_sympathyMatrix.at(child.second, i)) {
				++numOfSymp;
			}
		}
		if ((numOfSymp != 0) && unluckyFlag) {
			tempMap.insert(child);
		}
	}
	std::cout << "|----------Unhappy kids---------" << std::endl;
	for (auto const &unluckyChild : tempMap) {
		std::cout << "|	" << unluckyChild.first << std::endl;
	}
}


/*������ ����������, �� ���� ���� �����,
������� ���������� ������������� ���������� ������ �����.*/
void Children::showLovedChildren() {
	std::vector<std::pair<int, string>> sympathyCounts;
	int maxCount = 0;
	for (auto const &child : _childIDPairs) {
		int tempCount = 0;
		for (int i = 0; i < _count; i++) {
			if (_sympathyMatrix.at(i, child.second))
				++tempCount;
		}
		if (tempCount >= maxCount)
			maxCount = tempCount;
		sympathyCounts.push_back(std::pair<int, string>(tempCount, child.first));
	}
	std::cout << "|---------The most loved kids----------" << std::endl;
	for (auto const &ent : sympathyCounts) {
		if (ent.first >= maxCount)
			std::cout << "|	" << ent.second << std::endl;
	}
}