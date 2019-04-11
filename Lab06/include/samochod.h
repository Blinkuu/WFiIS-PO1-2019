#pragma once

#include "pojazd.h"

// Klasa Samochod. Nie jest to klasa wirtualna - mozna stworzyc jej instancje
class Samochod : virtual public PojazdLadowy {
public:
	Samochod() = default;
	Samochod(PredkoscMaksymalna maxVelocity) : PojazdLadowy(), m_MaxLandVelocity(maxVelocity) {}
	~Samochod() override = default;

	// Getter dla ladowej predkosci maksymalnej
	std::string predkoscMaksymalna() const { return std::to_string(m_MaxLandVelocity.GetMaxVelocity()).append("km/h"); }

	// Nadpisana funkcja czysto wirtualna z klasy Pojazd -> zwraca rodzaj pojazdu w formie stringa
	virtual std::string printType() const override { return {"Samochod"}; }	

private:
	PredkoscMaksymalna m_MaxLandVelocity;
};