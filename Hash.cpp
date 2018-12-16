// Hash.cpp
// Thomas Wise
// COSC 2030
// Project 02
// 15 Dec 2018

#include "Hash.h"

// Constructors for the hash class
hash::hash(void)
{
	val = 0;
}

hash::hash(fixedString x)
{
	unsigned long long int temp;
	val = 0;
	for (int i = 0; i < 8; i++)
	{
		temp = 1;
		for (int j = 0; j < i; j++)
		{
			temp *= 256;
		}
		val += (temp * static_cast<unsigned long long int>(x.getChar(i)));
	}
}

hash::hash(unsigned long long int x)
{
	val = x;
}

// Gets the numerical value of the hash
unsigned long long int hash::getHash(void) const
{
	return val;
}

// Converts the numerical value of the hash back to a string
fixedString hash::getString(void) const
{
	fixedString ans;
	unsigned long long int pwr, temp = val;
	for (int i = 0; i < 8; i++)
	{
		pwr = 1;
		for (int j = (7-i); j > 0; j--)
		{
			pwr *= 256;
		}
		ans.setChar(i, static_cast<char>(temp / pwr));
	}
	return ans;
}

// Changes the value of a hash
void hash::setHash(unsigned long long int x)
{
	val = x;
}

void hash::setHash(hash x)
{
	val = x.getHash();
}

// Allows the numerical value of two hashes to be added together
hash hash::operator+(const hash& right) const
{
	unsigned long long int temp;
	temp = val + right.getHash();
	return temp;
}