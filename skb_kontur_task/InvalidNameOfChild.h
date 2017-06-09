#pragma once
#include <exception>
#include <string>

class InvalidNameOfChild :
	public std::exception
{
public:
	InvalidNameOfChild() = default;
	~InvalidNameOfChild() = default;
	InvalidNameOfChild(std::string);
	const char* what() const noexcept;
private:
	std::string _message;
};

