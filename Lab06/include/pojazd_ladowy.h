#pragma once 

#include "pojazd.h"

// Klasa abstrakcyjna, z ktorej dziedzicza wszystkie pojazdy ladowe
class PojazdLadowy : virtual public Pojazd {
public:
	PojazdLadowy() = default;
	~PojazdLadowy() override = default;
};