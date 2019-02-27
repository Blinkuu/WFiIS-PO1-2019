#pragma once

#include <string>
#include "Wrapper.h"

class StringWrapper : public Wrapper {
public:
	StringWrapper() = default;
	StringWrapper(std::string s) : _member(s) {}
	~StringWrapper() = default;

	Wrapper* clone() const override;
	std::ostream& print() const override;
private:
	std::string _member;
};

Wrapper* StringWrapper::clone() const {
	return new StringWrapper(_member);
}

std::ostream& StringWrapper::print() const {
	return std::cout << _member << " ";
}