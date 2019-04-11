#pragma once

#include "pojazd.h"

// Klasa Rower. Nie jest to klasa wirtualna - mozna stworzyc jej instancje
class Rower : virtual public PojazdLadowy {
public:
	Rower() = default;
	~Rower() = default;

	// Nadpisana funkcja czysto wirtualna z klasy Pojazd -> zwraca rodzaj pojazdu w formie stringa
	virtual std::string printType() const override { return {"Rower"}; }
};