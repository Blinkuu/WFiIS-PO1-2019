#pragma once

#include "samochod.h"
#include "motorowka.h"

// Klasa Amfibia. Nie jest to klasa wirtualna - mozna stworzyc jej instancje. Laczy cechy samochodu i motorowki
class Amfibia : virtual public Samochod, virtual public Motorowka {
public:
	Amfibia() = default;
	Amfibia(PredkoscMaksymalna land, PredkoscMaksymalna water) : Samochod(land), Motorowka(water) {}
	~Amfibia() = default;
	
	// Getter dla predkosci maksymalnej dla ladu
	std::string predkoscMaksymalna_Lad() const { return Samochod::predkoscMaksymalna(); }

	// Getter dla predkosci maksymalnej dla wody
	std::string predkoscMaksymalna_Woda() const { return Motorowka::predkoscMaksymalna(); }

	// Nadpisana funkcja czysto wirtualna z klasy Pojazd -> zwraca rodzaj pojazdu w formie stringa
	virtual std::string printType() const override { return {"Amfibia"}; }
};