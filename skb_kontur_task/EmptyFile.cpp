#include "EmptyFile.h"



EmptyFile::EmptyFile(std::string message) {
	_message = message;
}


const char* EmptyFile::what() const noexcept {
	return ("Empty file: " + _message).c_str();
}