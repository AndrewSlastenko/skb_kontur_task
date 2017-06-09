#include "InvalidNameOfChild.h"



InvalidNameOfChild::InvalidNameOfChild(std::string message) {
	_message = message;
}


const char* InvalidNameOfChild::what() const noexcept {
	return ("Zero children was given: " + _message).c_str();
}
