#pragma once
#include <exception>
#include <string>

class EmptyFile :
	public std::exception
{
public:
	EmptyFile() = default;
	EmptyFile(std::string);
	~EmptyFile() = default;
	const char* what() const noexcept;
private:
	std::string _message;
};

