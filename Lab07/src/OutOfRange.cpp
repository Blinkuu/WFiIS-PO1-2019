#include "OutOfRange.h"
#include "Number.h"


OutOfRange::OutOfRange(std::string name, double val, std::pair<double, double> range) 
	: m_Name(name), m_Value(val), m_Range(range) {}

OutOfRange::~OutOfRange()
{
	while(!Number::m_NumberFactory.empty())
	{
		Number* num = Number::m_NumberFactory.back();
		Number::m_NumberFactory.pop_back();
		delete num;
	}
}

std::ostream& operator<<(std::ostream& out, const OutOfRange& e)
{
	return out << "Number named: " << e.m_Name << " has value " << e.m_Value << 
  					  " which is outside of the allowed range: [" << 
  					  e.m_Range.first << ", " << e.m_Range.second << "]";
}
