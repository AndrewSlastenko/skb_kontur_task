#include "IncorrentIndex.h"



IncorrentIndex::IncorrentIndex(std::string message) {
	_message = message;
}

const char* IncorrentIndex::what() const noexcept {
	return ("Incorrect index:" + _message).c_str();
}
