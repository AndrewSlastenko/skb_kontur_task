#pragma once
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
	
	if (argc == 2) {
		pathToNames = argv[0];
		pathToSympathy = argv[1];
	}
	else {
		cout << "Wrong arguments";
	}
	bool exists = checkFileForExisting(pathToNames, pathToSympathy);
	if (!exists) {
		cout << "One of files doesn't exist";
	}
	/*children.readChildrenFromFile(pathToNames);
	children.readSympathyFromFile(pathToSympathy);*/
	Children children(pathToNames, pathToSympathy);
	try {
		while (true) {
			char choice;
			cout << (char)214 + " -----------------------------------------";
			cout << (char)199 + " ---Choose the command (enter a digit)----" << std::endl;
			cout << (char)199 + " 1 - Print the list of the most unloved children" << std::endl;
			cout << (char)199 + " 2 - Print the list of the most loved children" << std::endl;
			cout << (char)199 + " 3 - Print the list of the most unhappy children" << std::endl;
			cout << (char)199 + " 4 - Exit the programm";
			choice = getchar();
			switch (choice) {
			case '1':
				children.showUnlovedChildren();
				break;
			case '2':
				children.showLovedChildren();
				break;
			case '3':
				children.showUnhappyChildren();
				break;
			case '4':
				cout << "Exit...";
				exit(0);
				break;
			default:
				cout << "Invalid command...";
				break;
			}
			cout << string(50, '\n');
		}
	}
	catch (InvalidNameOfChild& ex) {
		ex.what();
	}
	catch (IncorrentIndex& ex) {
		ex.what();
	}
	catch (EmptyFile& ex) {
		ex.what();
	}

	system("pause");
	///
}