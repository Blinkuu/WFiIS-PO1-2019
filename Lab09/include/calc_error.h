#pragma once

#include <string>
#include <vector>
#include <stdexcept>

// Klasa zbierajaca wyrzucone wyjatki na wszystkich poziomach
class Calc_error : public std::runtime_error {
public:

	// Konstruktor
	Calc_error(std::runtime_error* err, std::string str, std::string file, int line);

	// Metoda odpowiadajaca za wypisanie wszystkich koniecznych informacji o wyjatku
	void print() const noexcept;

	// Statyczna metoda wywolywana na koncu programu, ktora wypisuje wszystkie informacje o wszystkich wyjatkach
	static void handler();

private:

	std::runtime_error* mError; // Wskaznik na wyjatek
	std::string mText; // Tekst, ktory wyswietlamy przy wystapieniu bledu
	std::string mFile; // Plik, w ktorym wystapil blad
	int mLine; // Linia, w ktorej wystapil blad

	static std::vector<Calc_error*> mErrors; // Vector wyjatkow
};