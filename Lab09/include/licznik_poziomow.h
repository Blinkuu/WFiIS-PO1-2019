#pragma once

// Klasa liczaca ilosc poziomow operacji
class LicznikPoziomow {
public:

	// Konstruktor inkrementuje licznik
	LicznikPoziomow();

	// Destruktor dekrementuje licznik
	~LicznikPoziomow();
	
private:

	// Statyczny licznik
	static int mCounter;
};