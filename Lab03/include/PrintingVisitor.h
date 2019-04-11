#pragma once

#include <iostream>
#include "Visitor.h"

// PrintingVisitor class implementation. This class's purpose is to visit containers and print them.

class PrintingVisitor : public Visitor {
public:
	PrintingVisitor() = default;
	~PrintingVisitor() = default;

	// Visit function implementation. It's purpose is to visit a container and print relevant data.
	void visit(Data* data) override;
};

void PrintingVisitor::visit(Data* data) {
	if (dynamic_cast<IntData*>(data)) {
		IntData* tmpPtr = dynamic_cast<IntData*>(data);
		std::cout << " " << tmpPtr->get();
	} else if (dynamic_cast<FloatData*>(data)) {
		FloatData* tmpPtr = dynamic_cast<FloatData*>(data);
		std::cout << " " << tmpPtr->getFloat();
	}
}
