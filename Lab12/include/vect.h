#pragma once

#include <vector>
#include <functional>
#include <string.h>

#include "swap.h"

//szablon klasy, ktorego mozna zrobic specjalizacje,
//aby zaznaczyc, ze dany tym jest typem pod.
template<typename T> 
struct is_pod {
  const static bool pod = false;
};

//szablon klasy ktory sluzy za pojemnik
template<typename T>
class Vect {
public:
	//konstruktor klasy Vect, przyjmujacy rozmiar pojemnika oraz alokujacy pamiec
	Vect(int size);

	//destruktor klasy Vect, dealokujacy pamiec
	~Vect();

	//metoda zwracajaca wielkosc pojemnika
	size_t size() const { return static_cast<size_t>(m_Size); }

	//metoda buble_sort sluzaca do sortowania zawartosci pojemnika,
	//wedlug podanego komparatora
	void buble_sort(std::function<bool(const T&, const T&)> cmp);
public:
	//przeladowany operator [] sprawiajacy, ze pojemnik zachowuje sie jak tablica
	T& operator[](int index);

	//przeladowany operator [] sprawiajacy, ze pojemnik zachowuje sie jak tablica.
	//stworzony z mysla o specyfikatorach const
	const T& operator[](int index) const;

private:
	T* m_Array = nullptr; //wskaznik na obiekt T
	int m_Size; //rozmiar pojemnika
};

template<typename T>
Vect<T>::Vect(int size) : m_Size(size) {
	m_Array = new T[m_Size];
}

template<typename T>
Vect<T>::~Vect() {
	delete[] m_Array;
}

template<typename T>
T& Vect<T>::operator[](int index) {
	return m_Array[index];
}
template<typename T>
const T& Vect<T>::operator[](int index) const {
	return m_Array[index];
}

template<typename T>
void Vect<T>::buble_sort(std::function<bool(const T&, const T&)> cmp) {
	for(int i = 0; i < m_Size; i++)
	   for(int j = i+1; j < m_Size; ++j) 
	      if(!cmp(m_Array[j], m_Array[i]))
	      	Swap<T, is_pod<T>::pod>::swap(m_Array[i], m_Array[j]);
}