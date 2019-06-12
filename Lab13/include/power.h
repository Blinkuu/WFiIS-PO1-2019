#pragma once

template<int B, int E, bool NEG, bool GR>
class MyPower {
public:
	static const double value;
};

template<int B, int E, bool NEG, bool GR>
const double MyPower<B, E, NEG, GR>::value = 0.0;

// Dodatnie, mniejsze od 10
template<int B, int E>
class MyPower<B, E, false, false> {
public:
	static const double value;
};

template<int B, int E>
const double MyPower<B, E, false, false>::value = B*MyPower<B, E-1, false, false>::value;

// Wykladnik 0
template<int B>
class MyPower<B, 0, false, false> {
public:
	static const double value;
};

template<int B>
const double MyPower<B, 0, false, false>::value = 1.0;

////////////////////////
////////////////////////
////////////////////////

// Ujemne, mniejsze od 10
template<int B, int E>
class MyPower<B, E, true, false> {
public:
	static const double value;
};

template<int B, int E>
const double MyPower<B, E, true, false>::value = (1.0/B)*MyPower<B, E+1, true, false>::value;

// Wykladnik 0
template<int B>
class MyPower<B, 0, true, false> {
public:
	static const double value;
};

template<int B>
const double MyPower<B, 0, true, false>::value = 1.0;

////////////////////////
////////////////////////
////////////////////////

// Dodatnie, wieksze od 10

const int TooLargeExponentMustBeSmallerThan10();

template<int B, int E>
class MyPower<B, E, false, true> {
public:
	static const double value;
};

template<int B, int E>
const double MyPower<B, E, false, true>::value = TooLargeExponentMustBeSmallerThan10();

// Dodatnie, mniejsze od 10
template<int B, int E>
class MyPower<B, E, true, true> {
public:
	static const double value;
};

template<int B, int E>
const double MyPower<B, E, true, true>::value = TooLargeExponentMustBeSmallerThan10();

////////////////////////
////////////////////////
////////////////////////

template<int B, int E>
class Power {
public:
	static const double value;
};

template<int B, int E>
const double Power<B, E>::value = MyPower<B, E, E < 0, (E > 10)>::value;
