#pragma once

#include <iostream>

class Wrapper {
public:
	virtual ~Wrapper() = default;

	virtual Wrapper* clone() const = 0;
	virtual std::ostream& print() const = 0;
};

static std::ostream& operator<<(std::ostream& out, const Wrapper& wrapper) {
	return wrapper.print();
}
