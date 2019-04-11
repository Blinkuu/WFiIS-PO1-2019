#pragma once

#include <iostream>
#include "predkosc_maksymalna.h"

// Abstrakcyjna klasa, po ktorej dziedzicza wszystkie pojazdy
class Pojazd {
public:
	Pojazd() = default;
	virtual ~Pojazd() = default;

	// Wirtualna metoda, ktora pozwala nam bez problemu przeladowac operator << dla wszystkich typow pojazdow
	virtual std::string printType() const = 0;

	// Przeladowany operator <<
	friend std::ostream& operator<<(std::ostream& out, const Pojazd& vehicle);
};

std::ostream& operator<<(std::ostream& out, const Pojazd& vehicle) {
	return out << vehicle.printType();
}