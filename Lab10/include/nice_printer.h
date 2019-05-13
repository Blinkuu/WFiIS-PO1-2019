#pragma once

#include <iostream>
#include <iomanip>

// Klasa NicePrinter odpowiada za wypisywanie sformatowanego, przekazanego argumentu. Obiekty tej klasy sa obiektami funkcyjnymi.
class NicePrinter {
public:

	NicePrinter(int num) : mNum(num) {}

	// Przeladowany operator nawiasow, ktory pozwala na traktowanie tej klasy jako
	// obiekt funkcyjny i wypisywanie przekazanego argumentu
	template<typename T>
	void operator()(const T& arg) const;

private:
	int mNum; // Do ilu miejsc po przecinku wypisujemy
	static int mLineNumber; // Licznik linii
};

template<typename T>
void NicePrinter::operator()(const T& arg) const {
	std::cout << std::setw( mNum ) << ++mLineNumber << ": " << arg << std::endl;
}
