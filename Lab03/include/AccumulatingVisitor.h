#pragma once

#include <iostream>
#include "Visitor.h"

// AccumulatingVisitor class implementation. This class's purpose is to visit containers and accumulate.

class AccumulatingVisitor : public Visitor {
public:
	AccumulatingVisitor() = default;
	~AccumulatingVisitor() = default;

	// Visit function implementation. It's purpose is to visit a container and accumulate relevant data.
	void visit(Data* data) override;

	// This function returns the total sum which was accumulated using visit method.
	double getTotalSum() const;
private:
	double m_Sum;
};

void AccumulatingVisitor::visit(Data* data) {
	if (dynamic_cast<IntData*>(data)) {
		IntData* tmpPtr = dynamic_cast<IntData*>(data);
		m_Sum += tmpPtr->get();
	} else if (dynamic_cast<FloatData*>(data)) {
		FloatData* tmpPtr = dynamic_cast<FloatData*>(data);
		m_Sum += tmpPtr->getFloat();
	}
}

double AccumulatingVisitor::getTotalSum() const {
	return m_Sum;
}