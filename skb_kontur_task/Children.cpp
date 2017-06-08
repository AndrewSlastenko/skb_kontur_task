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