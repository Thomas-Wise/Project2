// FixedString.cpp
// Thomas Wise
// COSC 2030
// Project 02
// 15 Dec 2018

#include"FixedString.h"

// The fixed string makes a string that is always exactly 8 characters long.

// Constructors
fixedString::fixedString(void)
{
	setString("");
}

fixedString::fixedString(string x)
{	
	setString(x);
}

fixedString::fixedString(const fixedString& x)
{
	for (int i = 0; i < 8; i++)
	{
		str[i] = x.getChar(i);
	}
}

fixedString::~fixedString(void)
{
}

// Returns a single character from the string
char fixedString::getChar(int i) const
{
	return str[i];
}

// Returns the whole string
string fixedString::getString(void) const
{
	string result = "";
	for (int i = 0; i < 8; i++)
	{
		result += str[i];
	}
	return result;
}

// Changes one character
void fixedString::setChar(int i, char x)
{
	str[i] = x;
}

// Changes the entire string
void fixedString::setString(fixedString x)
{
	for (int i = 0; i < 8; i++)
	{
		str[i] = x.getChar(i);
	}
}

void fixedString::setString(string x)
{
	for (unsigned int i = 0; i < 8; i++)
	{
		if (i < x.length())
		{
			str[i] = x[i];
		}
		else
		{
			str[i] = '\0';
		}
	}
}

// Allows string to be printed out
ostream& operator<<(ostream& out, fixedString x)
{
	for (int i = 0; i < 8; i++)
	{
		out << x.getChar(i);
	}
	return out;
}