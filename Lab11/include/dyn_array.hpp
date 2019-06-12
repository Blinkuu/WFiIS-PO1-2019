#pragma once

#include <iostream>

/*
 * Dynamicznie alokowany kontener z zaimplementowanymi iteratorami w stylu STL.
 */

template<typename T>
class DynArray {
public:


	/*
	 * Konstruktor przyjmujacy jako argument wielkosc kontenera i alokujacy odpowiednio pamiec.
	 */

	DynArray(int size) : m_size(size) {
		m_array = new T[m_size];
	}

	/*
	 * Konstruktor przyjmujacy jako argumenty wielkosc kontenera i wskaznik na inny kontener.
	 * Jego zadaniem jest zaalokowanie odpowiednio pamieci i przepisanie z innej tablicy/kontenera wartosci.
	 */

	DynArray(int size, const T* array) : m_size(size) {
		m_array = new T[m_size];	

		for(int i = 0; i < m_size; ++i)
		{
			m_array[i] = array[i];
		}
	}


	/*
	 * Konstruktor kopiujacy.
	 */

	DynArray(const DynArray& other) : m_size(other.size()) {
		m_array = new T[m_size];

		for(int i = 0; i < m_size; ++i)
		{
			m_array[i] = other.m_array[i];
		}
	}


	/*
	 * Destruktor.
	 */

	~DynArray() {
		delete[] m_array;
	}


	/*
	 * Metoda zwracajaca aktualna wielkosc kontenera.
	 */

	constexpr int size() const noexcept { return m_size; }

public:


	/*
	 * Przeladowany operator nawiasow kwadratowych, ktory pozwala na operacje na kontenerze jak na tablicy.
	 */

	constexpr T& operator[](int index) noexcept {
		return m_array[index];
	}

public:
	

	/*
	 * Wewnetrzna klasa Iterator, ktora sluzy do poruszania sie po kontenerze i pozwala na korzystanie z niego 
	 * w metodach biblioteki STL.
	 */

	class Iterator {
	public:
		Iterator(T* ptr) : m_ptr(ptr) {}

		void operator++() {
			++m_ptr;
		}

		bool operator!=(const Iterator& it) {
			return m_ptr != it.m_ptr;
		}

		T& operator*() {
			return *m_ptr;
		}

		T* operator->() {
			return m_ptr;
		}

	private:
		T* m_ptr;
	};


	/*
	 * Metoda zwracajaca iterator na poczatek kontenera
	 */

	Iterator begin() {
		return Iterator(m_array);
	}

	/*
	 * Metoda zwracajaca iterator na koniec kontenera
	 */

	Iterator end() {
		return Iterator(m_array + m_size);
	}

private:
	T* m_array; /* Wskaznik, ktory trzyma adres dynamicznie zaalokowanej pamieci na typ T */
	int m_size; /* Aktualny rozmiar kontenera */
};

template<typename T>
std::ostream& operator<<(std::ostream& out, DynArray<T>& arr) {

	out << "{";
	int i = 0;
	for(; i < arr.size() - 1; ++i) {
		out << "\"" << arr[i] << "\", ";
	}

	out << "\"" << arr[i] << "\"}";

	return out;
}