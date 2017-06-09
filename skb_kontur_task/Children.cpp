#include "Children.h"



Children::Children() {

}


Children::~Children() {

}

int Children::getNameId(string name) {
	auto it = _childIDPairs.find(name);
	if (it != _childIDPairs.end()) return it->second;
	return -1;
}

void Children::readChildrenFromFile(string pathToFile) {
	std::ifstream file(pathToFile);
	string name;
	int numOfLines = 0;
	while (std::getline(file, name)) {
		insertNewChild(name);
		++numOfLines;
	}
	_sympathyMatrix = Matrix<bool>(_count);
	//mb check for zero child
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
				setNewSympathy(from, to);
				break;
			case ';':
				setNewSympathy(from, to);
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
			//mark
		}

		++numOfLines;
	}
	//mb check for zero sympathy
}


void Children::insertNewChild(string name) {
	_childIDPairs.insert(std::pair<string, int>(name, _count));
	++_count;
}


void Children::setNewSympathy(string nameFrom, string nameTo) {
	_sympathyMatrix.at(getNameId(nameFrom), getNameId(nameTo)) = true;
}


/*список всех не любимчиков, то есть детей которые никому не симпатичны*/
void Children::showUnlikedChildren() {

}


/*список всех несчастных детей, то есть тех,
которые не симпатичны ни одному ребенку из тех, кто симпатичен им самим
исключением тех детей, которым никто не симпатичен.*/
void Children::showUnluckyChildren() {

}


/*список любимчиков, то есть всех детей,
которые симпатичны максимальному количеству других детей.*/
void Children::showLikedChildren() {

}