// FixedString.cpp
// Thomas Wise
// COSC 2030
// Project 02
// 14 Dec 2018

#include"FixedString.h"

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

char fixedString::getChar(int i) const
{
	return str[i];
}

string fixedString::getString(void) const
{
	string result = "";
	for (int i = 0; i < 8; i++)
	{
		result += str[i];
	}
	return result;
}

void fixedString::setChar(int i, char x)
{
	str[i] = x;
}

void fixedString::setString(string x)
{
	for (int i = 0; i < 8; i++)
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