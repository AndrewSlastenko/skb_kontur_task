#pragma once
#include <vector>
#include "IncorrentIndex.h"

template <typename T>
class Matrix
{
public:
	Matrix() {
		_matrix = std::vector<T>(0);
		_count = 0;
	}

	Matrix(int length) {
		_matrix = std::vector<T>(length*length, 0);
		_count = length;
	}

	~Matrix() = default;

	T &at(int i, int j) {
		int size = _matrix.size();
		int needed = i*_count + j;
		if ((needed) >= size)
			throw IncorrentIndex("i = " + std::to_string(i) + "; j =" + std::to_string(j));
		return _matrix[needed];
	}

	//const T &at(int, int) const;

private:
	std::vector<T> _matrix;
	int _count;
};
