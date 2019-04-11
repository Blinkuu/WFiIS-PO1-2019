#pragma once

#include <string>
#include <iostream>

class InfoClass{
public:
	InfoClass(const std::string & sinfo) : m_info(sinfo) 
	{
		std::cout << "++ Tworze obiekt InfoClass: " << info() << std::endl;
	}	
	virtual ~InfoClass() 
	{
		std::cout << "++ Usuwam obiekt InfoClass: " << info() << std::endl;
	}

	virtual std::string info() const
	{
		return "info = " + m_info;
	}
	
	void info(const std::string & sinfo)
	{
		m_info = sinfo;
	}
	
private:
	std::string m_info;
};

class InfoSuperClass : public InfoClass{
public:
	InfoSuperClass(const std::string & sinfo, int num) : InfoClass(sinfo), m_num(num) 
	{
	}
	
	virtual std::string info() const
	{
		return InfoClass::info() + ", num = " + std::to_string(m_num);
	}
private:
	int m_num;
};


