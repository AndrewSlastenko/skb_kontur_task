#include "Children.h"



Children::Children(string pathToNames, string pathToSympathy) {
	readChildrenFromFile(pathToNames);
	_sympathyMatrix = new Matrix<bool>(_count*_count);
	readSympathyFromFile(pathToSympathy);
}


int Children::getNameId(string name) {
	auto it = _childIDPairs.find(name);
	if (it == _childIDPairs.end())
		throw InvalidNameOfChild(name);
	return it->second;
}

void Children::readChildrenFromFile(string pathToFile) {
	std::ifstream file(pathToFile);
	string name;
	int numOfLines = 0;
	while (std::getline(file, name)) {
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
				to = "";
				break;
			case ' ':
				//больше пробелов богу пробелов
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
	_sympathyMatrix->at(getNameId(nameFrom), getNameId(nameTo)) = true;
}


/*список всех не любимчиков, то есть детей которые никому не симпатичны*/
void Children::showUnlovedChildren() {
	std::map <string, int> tempMap; //можно заменить на вектор строк (второй инт не нужен)
	bool unlikeFlag = true;
	for (auto const &child : _childIDPairs) {
		unlikeFlag = true;
		for (int i = 0; i < _count; i++) {
			if (_sympathyMatrix->at(i, child.second)) {
				unlikeFlag = false;
				break;
			}
		}
		if (unlikeFlag) {
			tempMap.insert(child);
		}
	}
	std::cout << "|-----------Нелюбимчки-------------";
	for (auto const &unlikedChild : tempMap) {
		std::cout << "|/t" << unlikedChild.first << std::endl;
	}
}


/*список всех несчастных детей, то есть тех,
которые не симпатичны ни одному ребенку из тех, кто симпатичен им самим
исключением тех детей, которым никто не симпатичен.*/
void Children::showUnhappyChildren() {
	int numOfSymp = 0;
	bool unluckyFlag = true;
	std::map <string, int> tempMap;
	for (auto const &child : _childIDPairs) {
		unluckyFlag = true;
		numOfSymp = 0;
		for (int i = 0; i < _count; i++) {
			if (_sympathyMatrix->at(child.second, i) && _sympathyMatrix->at(i, child.second)) {
				unluckyFlag = false;
				++numOfSymp;
				break;
			}
			else if (_sympathyMatrix->at(child.second, i)) {
				++numOfSymp;
			}
		}
		if ((numOfSymp != 0) && unluckyFlag) {
			tempMap.insert(child);
		}
	}
	std::cout << "|----------Несчастные дети---------";
	for (auto const &unluckyChild : tempMap) {
		std::cout << "|/t" << unluckyChild.first << std::endl;
	}
}


/*список любимчиков, то есть всех детей,
которые симпатичны максимальному количеству других детей.*/
void Children::showLovedChildren() {
	std::vector<std::pair<int, string>> sympathyCounts;
	int maxCount = 0;
	for (auto const &child : _childIDPairs) {
		int tempCount = 0;
		for (int i = 0; i < _count; i++) {
			if (_sympathyMatrix->at(i, child.second))
				++tempCount;
		}
		if (tempCount >= maxCount)
			maxCount = tempCount;
		sympathyCounts.push_back(std::pair<int, string>(tempCount, child.first));
	}
	std::cout << "|------------Любимчки--------------";
	for (auto const &ent : sympathyCounts) {
		if (ent.first >= maxCount)
			std::cout << "|/t" << ent.second << std::endl;
	}
}