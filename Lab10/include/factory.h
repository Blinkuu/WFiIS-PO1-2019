#pragma once

// Klasa produkujaca obiekty
class Factory {
public:

	// Sparametryzowana metoda, ktora pozwala na ustawienie obiektu, ktory nastepnie mozemy produkowac
	template<typename T>
	T base(const T& arg, bool flag = true) const noexcept;

	// Metoda pomocnicza pozwalajaca na zapamietywanie obiektow, ktore bedziemy chcieli produkowac
	template<typename T>
	T remember_base(const T& arg, bool flag) const noexcept;

	// Metoda zwracajaca aktualnie ustawiony przez klase obiekt
	template<typename T>
	T product() const noexcept;

};

template<typename T>
T Factory::base(const T& arg, bool flag) const noexcept {
	return remember_base(arg, flag);
}

template<typename T>
T Factory::remember_base(const T& arg, bool flag) const noexcept {
	static T base = arg;
	
	if(flag == true) {
		base = arg;
	}

	return base;
}

template<typename T>
T Factory::product() const noexcept {
	return base(T(), false);
}
