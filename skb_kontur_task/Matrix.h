#pragma once
#include <vector>

using std::vector;

template <typename T>
class Matrix
{
public:
	Matrix();
	Matrix(int);
	~Matrix();
	//void add();
	T &at(int, int);
	//const T &at(int, int) const;

private:
	vector<T> _matrix;
	int _count;
};

