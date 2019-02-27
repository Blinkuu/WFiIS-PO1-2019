#pragma once

#include "Wrapper.h"

class FloatWrapper : public Wrapper {
public:
	FloatWrapper() = default;
	FloatWrapper(float f) : _member(f) {}
	~FloatWrapper() = default;

	Wrapper* clone() const override;
	std::ostream& print() const override;
private:
	float _member;
};

Wrapper* FloatWrapper::clone() const {
	return new FloatWrapper(_member);
}

std::ostream& FloatWrapper::print() const {
	return std::cout << _member << " ";
}