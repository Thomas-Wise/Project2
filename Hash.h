// Hash.h
// Thomas Wise
// COSC 2030
// Project 02
// 15 Dec 2018

#ifndef HASH_H
#define HASH_H
#include "FixedString.h"

class hash
{
public:
	hash(void);
	hash(fixedString);
	hash(unsigned long long int);
	unsigned long long int getHash(void) const;
	fixedString getString(void) const;
	void setHash(unsigned long long int);
	void setHash(hash);
	hash operator+(const hash&) const;
private:
	unsigned long long int val;
};

#endif