#pragma once

//szablon struktury, ktora trzyma metody swappujace obiekty
template<typename T, bool N>
struct Swap {
	static void swap(T& obj1, T& obj2) {
		T tmp = obj1;
		obj1 = obj2;
		obj2 = tmp;
	}
};

//specjalizacja struktury dla typow pod
template<typename T>
struct Swap<T, true> {
	static void swap(T& obj1, T& obj2) {
	T* tmp = new T();
	memcpy(tmp, &obj1, sizeof(T));
	memcpy(&obj1, &obj2, sizeof(T));
	memcpy(&obj2, tmp, sizeof(T));
	delete tmp;
	}
};