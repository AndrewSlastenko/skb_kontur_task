#pragma once
#include <exception>
#include <string>

class IncorrentIndex :
	public std::exception
{
public:
	IncorrentIndex() = default;
	IncorrentIndex(std::string);
	~IncorrentIndex() = default;
	const char* what() const noexcept;
private:
	std::string _message;
};

