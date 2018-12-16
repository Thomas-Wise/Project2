// FixedString.h
// Thomas Wise
// COSC 2030
// Project 02
// 15 Dec 2018

#ifndef FIXED_STRING_H
#define FIXED_STRING_H

#include <string>
#include <iostream>
using std::ostream;
using std::string;

class fixedString
{
public:
	fixedString(void);
	fixedString(string);
	fixedString(const fixedString&);
	~fixedString(void);
	char getChar(int) const;
	string getString(void) const;
	void setChar(int, char);
	void setString(fixedString);
	void setString(string);
private:
	char str[8];
};

ostream& operator<<(ostream& out, fixedString x);
#endif