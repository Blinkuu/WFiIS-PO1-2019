#pragma once

#include <iostream>
#include <utility>
#include <vector>

class Number {
	friend class OutOfRange;
public:
	Number(std::string name, double val) : m_Name(name), m_Value(val) {}

	~Number() 
	{ 
		std::cout << "Destroying number " << m_Value << std::endl;
	} 

	void Print() const;

	static void SetRange(double r1, double r2) noexcept;
	static Number* Factory(std::string name, double val);
private:
	std::string m_Name;
	double m_Value;
	static std::pair<double, double> m_Range;
	static std::vector<Number*> m_NumberFactory;
};
