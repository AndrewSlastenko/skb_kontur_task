#pragma once
#include <vector>
#include "IncorrentIndex.h"

using std::vector;

template <typename T>
class Matrix
{
public:
	Matrix() {
		_matrix = vector<T>(0);
		_count = 0;
	}

	Matrix(int length) {
		_matrix = vector<T>(length*length, 0);
		_count = length*length;
	}

	~Matrix() = default;

	T &at(int i, int j) {
		int size = _matrix.size();
		int needed = i*_count + j;
		if ((i*_count + j) >= size)
			throw IncorrentIndex("i = " + std::to_string(i) + "; j =" + std::to_string(j));
		return _matrix[needed];
	}

	//const T &at(int, int) const;

private:
	vector<T> _matrix;
	int _count;
};
