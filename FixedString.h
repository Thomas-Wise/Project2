// FixedString.h
// Thomas Wise
// COSC 2030
// Project 02
// 14 Dec 2018

#ifndef FIXED_STRING_H
#define FIXED_STRING_H

#include <string>
using std::string;

class fixedString
{
public:
	fixedString(string);
	fixedString(fixedString&);
	char getChar(int) const;
	string getString(void) const;
	void setChar(int, char);
	void setString(string);
private:
	char str[8];
};

#endif