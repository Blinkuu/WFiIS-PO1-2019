#include "PArr.h"

#include <iostream>

PArr::PArr(int size) : _size(size) {
	_member = new Wrapper*[_size];
}

PArr::~PArr() {
	for(int i = 0; i < _size; ++i) {
		delete _member[i];
	}

	delete _member;
}

void PArr::operator=(const PArr& arr) {
	this->~PArr();

	_member = new Wrapper*[arr._size];
	_size = arr._size;

	for(int i = 0; i < _size; ++i) {
		_member[i] = arr._member[i]->clone();
	}
}

Wrapper* &PArr::operator[](int index) {
	return _member[index];
}

std::ostream& operator<<(std::ostream& out, const PArr& arr) {
	for(int i = 0; i < arr._size; ++i)
		out << *arr._member[i] << " ";
	return out;
}