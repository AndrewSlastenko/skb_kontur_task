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

}


void Children::readSympathyFromFile(string pathToFile) {

}


void Children::insertNewChild(string name) {
	
}


void Children::setNewSympathy(string nameFrom, string nameTo) {

}


/*������ ���� �� ����������, �� ���� ����� ������� ������ �� ����������*/
void Children::showUnlikedChildren() {

}


/*������ ���� ���������� �����, �� ���� ���,
������� �� ���������� �� ������ ������� �� ���, ��� ���������� �� �����
����������� ��� �����, ������� ����� �� ����������.*/
void Children::showUnluckyChildren() {

}


/*������ ����������, �� ���� ���� �����,
������� ���������� ������������� ���������� ������ �����.*/
void Children::showLikedChildren() {

}