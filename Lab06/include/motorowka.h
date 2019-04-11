#pragma once

#include "pojazd.h"

// Klasa Motorowka. Nie jest to klasa wirtualna - mozna stworzyc jej instancje
class Motorowka : virtual public Pojazd {
public:
	Motorowka() = default;
	Motorowka(PredkoscMaksymalna maxVelocity) : Pojazd(), m_MaxWaterVelocity(maxVelocity) {}
	~Motorowka() override = default;

	// Getter dla wodnej predkosci maksymalnej
	std::string predkoscMaksymalna() const { return std::to_string(m_MaxWaterVelocity.GetMaxVelocity()).append("km/h"); }

	// Nadpisana funkcja czysto wirtualna z klasy Pojazd -> zwraca rodzaj pojazdu w formie stringa
	virtual std::string printType() const override { return {"Motorowka"}; }

private:
	PredkoscMaksymalna m_MaxWaterVelocity;
};