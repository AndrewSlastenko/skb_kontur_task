#include "InvalidNameOfChild.h"



InvalidNameOfChild::InvalidNameOfChild(std::string message) {
	_message = message;
}


const char* InvalidNameOfChild::what() const noexcept {
	return ("Invalid name of child (mb doesn't exist): " + _message).c_str();
}
