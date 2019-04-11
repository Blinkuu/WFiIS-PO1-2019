#include "InfoSmartPtr.h"

#include <iostream>

InfoSmartPtr::InfoSmartPtr(InfoClass* infoClass) : m_Counter(nullptr) {
	if(infoClass) {
		m_Ptr = infoClass;
		m_Counter = new int();
		++(*m_Counter);
	}
}

InfoSmartPtr::InfoSmartPtr(const InfoSmartPtr& other) {
	m_Ptr = other.m_Ptr;
	m_Counter = other.m_Counter;
	++(*m_Counter);
}

InfoSmartPtr::~InfoSmartPtr() {
	Delete();
}

void InfoSmartPtr::operator=(InfoSmartPtr& other) {
	Delete();
	m_Ptr = other.m_Ptr;
	m_Counter = other.m_Counter;
	++(*m_Counter);
}

InfoClass*& InfoSmartPtr::operator->() {
	return m_Ptr;
}

const InfoClass* InfoSmartPtr::operator->() const {
	return m_Ptr;
}

const InfoClass& InfoSmartPtr::operator*() const {
	return *m_Ptr;
}

void InfoSmartPtr::Delete() {
	if(m_Counter){
		--(*m_Counter);
		if(!(*m_Counter)) {
			delete m_Ptr;
			delete m_Counter;
		}	
	}
}