#pragma once

#include <iostream>
#include <utility>

#include "Number.h"

class OutOfRange {
public:
	OutOfRange(std::string name, double val, std::pair<double, double> range);
	~OutOfRange();

	friend std::ostream& operator<<(std::ostream& out, const OutOfRange& e);
private:
	std::string m_Name;
	double m_Value;
	std::pair<double, double> m_Range;
};