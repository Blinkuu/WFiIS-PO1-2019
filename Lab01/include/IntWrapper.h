#pragma once

#include "Wrapper.h"

class IntWrapper : public Wrapper {
public:
	IntWrapper() = default;
	IntWrapper(int i) : _member(i) {}
	~IntWrapper() = default;

	Wrapper* clone() const override;
	std::ostream& print() const override;
private:
	int _member;
};

Wrapper* IntWrapper::clone() const {
	return new IntWrapper(_member);
}

std::ostream& IntWrapper::print() const {
	return std::cout << _member << " ";
}