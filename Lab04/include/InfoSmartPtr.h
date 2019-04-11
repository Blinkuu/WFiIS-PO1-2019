#pragma once

#include "InfoClass.h"

class InfoSmartPtr {
public:
	InfoSmartPtr(InfoClass* infoClass = nullptr);
	InfoSmartPtr(const InfoSmartPtr& other);
	~InfoSmartPtr();

	void operator=(InfoSmartPtr& other);
	InfoClass*& operator->();
	const InfoClass* operator->() const;
	const InfoClass& operator*() const;

private:
	void Delete();

private:
	InfoClass* m_Ptr;
	int* m_Counter;
};