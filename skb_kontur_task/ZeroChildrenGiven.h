#pragma once
#include <exception>
#include <string>

class ZeroChildrenGiven :
	public std::exception
{
public:
	ZeroChildrenGiven() = default;
	ZeroChildrenGiven(std::string);
	~ZeroChildrenGiven() = default;
	const char* what() const noexcept;
private:
	std::string _message;
};

