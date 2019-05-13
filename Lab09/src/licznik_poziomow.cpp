#include "licznik_poziomow.h"
#include <iostream>

int LicznikPoziomow::mCounter{0};

LicznikPoziomow::LicznikPoziomow() {
	++mCounter;
	std::cout << "Rozpoczynamy poziom numer " << mCounter << std::endl;
}

LicznikPoziomow::~LicznikPoziomow() {
	std::cout << "Konczymy poziom numer " << mCounter << std::endl;
	--mCounter;
}