#pragma once

#include <string>
#include <vector>

class WordAccess {
public:
	static bool eofSentence(std::string str);
	static bool eofWord(char chr);
};

class ReadAccess {
public:
	ReadAccess() = default;
	ReadAccess(std::string str);
	virtual ~ReadAccess() = default;

	const std::string operator[](int word_index) const;
protected:
	int MoveToWord(int i) const;
protected:
	std::string m_String;
	int m_WordCount;
};

class ReadWriteAccess : public ReadAccess {
public:
	ReadWriteAccess() = default;
	ReadWriteAccess(const char* str);
	~ReadWriteAccess() = default;

	char* operator[](int word_index);
private:
	const char* m_AccessString;
};