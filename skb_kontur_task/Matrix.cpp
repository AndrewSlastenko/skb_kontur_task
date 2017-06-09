#include "Matrix.h"



template <typename T>
Matrix<T>::Matrix() {
	_matrix = new vector<T>(0);
	_count = 0;
}


template <typename T>
Matrix<T>::Matrix(int length) {
	_matrix = new vector<T>(length*length, 0);
	_count = length;
}

//template <typename T>

template <typename T>
Matrix<T>::~Matrix() {
	delete _matrix;
}


template <typename T>
T &Matrix<T>::at(int i, int j) {
	return _matrix[i*count + j];
}



/*template <typename T>
const T &Matrix<T>::at(int i, int j) const {
	return const _matrix[i*count + j];
}*/
