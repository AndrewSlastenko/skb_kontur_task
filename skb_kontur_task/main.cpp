#include "Children.h"
#include <iostream>
#include <fstream>

using std::cout;

bool checkFileForExisting(const string &path1, const string &path2) {
	bool result = false;
	std::ifstream f1(path1.c_str());
	std::ifstream f2(path2.c_str());
	if (f1.good() && f2.good()) result = true;
	return result;
}

int main(int argc, char* argv[]) {
	string pathToNames;
	string pathToSympathy;
	Children children;
	if (argc == 2) {
		pathToNames = argv[0];
		pathToSympathy = argv[1];
	}
	else {
		cout << "Wrong arguments";
	}
	bool exists = checkFileForExisting(pathToNames, pathToSympathy);
	if (!exists) return 0;

	///
}