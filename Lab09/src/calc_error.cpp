#include "calc_error.h"
#include <iostream>

std::vector<Calc_error*> Calc_error::mErrors{};

Calc_error::Calc_error(std::runtime_error* err, std::string str, std::string file, int line) 
: 	std::runtime_error(*err),
	mError{err},
	mText{str},
	mFile{file},
	mLine{line}
{
	mErrors.push_back(this);
}

void Calc_error::print() const noexcept
{
	std::cout << "-- z powodu: " << mText << ", " << "[plik = " << mFile << ", linia = " << mLine << "]" << std::endl;
}

void Calc_error::handler() 
{
	std::cout << "Zlapano wyjatek:" << std::endl;
	
	for(auto it = mErrors.size() - 1; it > 0; --it)
	{
		mErrors[it]->print();	
		delete mErrors[it];
	}

	mErrors[0]->print();
	std::cout << "-- z powodu: " <<  mErrors[0]->mError->what() << std::endl;
	delete mErrors[0]->mError;
	delete mErrors[0];
}