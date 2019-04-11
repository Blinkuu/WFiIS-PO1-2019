#pragma once

#include <iostream>

// Klasa-wrapper na predkosc maksymalna pojazdu (zarowno ladowa, jak i wodna)
class PredkoscMaksymalna {
public:
	PredkoscMaksymalna() = default;
	PredkoscMaksymalna(int velocity) : m_MaxVelocity(velocity) {}
	~PredkoscMaksymalna() = default;

	// Getter predkosci maksymalnej
	int GetMaxVelocity() const { return m_MaxVelocity; }

	// Przeladowany operator <<
	friend std::ostream& operator<<(std::ostream& out, const PredkoscMaksymalna& maxVelocity);

private:
	int m_MaxVelocity;
};

std::ostream& operator<<(std::ostream& out, const PredkoscMaksymalna& maxVelocity) {
	return out << std::to_string(maxVelocity.GetMaxVelocity()) << "km/h";
}