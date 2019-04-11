#include <WordAccess.h>

#include <iostream>

bool WordAccess::eofSentence(std::string str) {
	return !str[0];
}

bool WordAccess::eofWord(char chr) {
	return !chr;
}

ReadAccess::ReadAccess(std::string str) : m_String(str) {
	for(unsigned i = 0; i < m_String.length(); ++i) {
		if(m_String[i] == ' ')
			++m_WordCount;
	}

	--m_WordCount;
}

const std::string ReadAccess::operator[](int word_index) const {
	int wordIdx = MoveToWord(word_index);
	std::string tmp;


	while(m_String[wordIdx] != ' ') {
		tmp += m_String[wordIdx];
		++wordIdx;
	}

	return tmp;
}

int ReadAccess::MoveToWord(int i) const {
	if(i == 0) {
		return 0;
	}

	int chrs = 0;
	int new_word = 0;
	for(unsigned k = 0; k < m_String.length() && new_word < i; ++k) {
		if(m_String[k] == ' ') {
			++new_word;
			++chrs;
		}
		else {
			++chrs;
		}
	}

	return chrs;
}

ReadWriteAccess::ReadWriteAccess(const char* str) : ReadAccess(str), m_AccessString(str) {}

char* ReadWriteAccess::operator[](int word_index) {
	int wordIdx = MoveToWord(word_index);
	return const_cast<char*>(m_AccessString + wordIdx);
}