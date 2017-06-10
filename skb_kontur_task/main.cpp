#include "Children.h"

using std::cout;
using std::string;

bool checkFileForExisting(const string &path1, const string &path2) {
	bool result = false;
	std::ifstream f1(path1.c_str());
	std::ifstream f2(path2.c_str());
	if (f1.good() && f2.good()) result = true;
	return result;
}

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "");
	string pathToNames = "C:\\Users\\4glazy\\Documents\\Visual Studio 2017\\Projects\\skb_kontur_task\\Debug\\children.txt";
	string pathToSympathy = "C:\\Users\\4glazy\\Documents\\Visual Studio 2017\\Projects\\skb_kontur_task\\Debug\\sympathies.txt";
	/*for (int i = 0; i < argc; i++) { //дебаг инфа
		cout << "PARAM[" << i << "]: " <<  argv[i] << std::endl;
	}*/
	if (argc == 3) {
		pathToNames = argv[1];
		pathToSympathy = argv[2];
	}
	else {
		cout << "Wrong arguments" << std::endl;
		system("pause");
		exit(1);
	}
	bool exists = checkFileForExisting(pathToNames, pathToSympathy);
	if (!exists) {
		cout << "One of files doesn't exist";
	}
	try {
		Children children(pathToNames, pathToSympathy);
		while (true) {
			char choice;
			cout << "r -----------------------------------------" << std::endl;
			cout << "| ---Choose the command (enter a digit)----" << std::endl;
			cout << "| 1 - Print the list of the most unloved children" << std::endl;
			cout << "| 2 - Print the list of the most loved children" << std::endl;
			cout << "| 3 - Print the list of the most unhappy children" << std::endl;
			cout << "| 4 - Exit the programm" << std::endl;
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
				cout << "Invalid command..." << std::endl;
				break;
			}
			system("pause");
			system("cls");
			getchar();
		}
	}
	catch (InvalidNameOfChild& ex) {
		std::cerr << ex.what();
	}
	catch (IncorrentIndex& ex) {
		std::cerr << ex.what();
	}
	catch (EmptyFile& ex) {
		std::cerr << ex.what();
	}

	system("pause");
	///
}