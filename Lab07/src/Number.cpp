#include "Number.h"
#include "OutOfRange.h"

std::pair<double, double> Number::m_Range{};
std::vector<Number*> Number::m_NumberFactory{};

void Number::Print() const 
{ 
	std::cout << m_Name << " " << m_Value << std::endl; 
}

void Number::SetRange(double r1, double r2) noexcept 
{
	m_Range = std::pair<double, double>(r1, r2);
}

Number* Number::Factory(std::string name, double val)
{
	std::cout << "Manufacturing number " << val << std::endl;
	Number* number = new Number(name, val);
	m_NumberFactory.push_back(number);

	if(val > m_Range.second || val < m_Range.first)
	{
		throw OutOfRange(name, val, m_Range);
	}

	return number;
}