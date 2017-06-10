#include "Matrix.h"



template <typename T>
Matrix<T>::Matrix() {
	_matrix = vector<T>(0);
	_count = 0;
}


template <typename T>
Matrix<T>::Matrix(int length) {
	_matrix = vector<T>(length*length, 0);
	_count = length*length;
}


/*template <typename T>
Matrix<T>::~Matrix() {
	delete _matrix;
}*/


template <typename T>
T &Matrix<T>::at(int i, int j) {
	if ((i*_count + j) >= _matrix->size())
		throw IncorrentIndex("i = " + std::to_string(i) + "; j =" + std::to_string(j));
	return _matrix.at(i*_count + j);
}


/*template <typename T>
const T &Matrix<T>::at(int i, int j) const {
	return const _matrix[i*count + j];
}*/
