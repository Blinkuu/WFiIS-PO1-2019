#pragma once

#include "Data.h"

// Visitator abstract class which is meant to be a base class.

class Visitor {
public:
	Visitor() = default;
	~Visitor() = default;

	// Pure virtual visit function. Different types of visitors implement it in a different way
	virtual void visit(Data* data) = 0;
};