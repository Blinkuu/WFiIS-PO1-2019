#pragma once

#include <iostream>
#include "Wrapper.h"

class PArr {
public:
	PArr() = default;
	PArr(int size);
	~PArr();

	void operator=(const PArr& arr);
	Wrapper* &operator[](int index);

	friend std::ostream& operator<<(std::ostream& out, const PArr& arr);
private:
	Wrapper** _member;
	int _size;
};

