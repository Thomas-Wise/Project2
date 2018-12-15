// Node.h
// Thomas Wise
// COSC 2030
// Project 02
// 15 Dec 2018

#ifndef NODE_H
#define NODE_H

#include "FixedString.h"
#include <string>
#include <vector>
using std::string;
using std::vector;

class node
{
public:
	node(void);
	node(string);
	node(string, node&);
	node(node&);
	fixedString getID(void) const;
	fixedString getPID(void) const;
	string getRE(void) const;
	fixedString getLHash(void) const;
	fixedString getRHash(void) const;
	vector<fixedString> getLHist(void) const;
	vector<fixedString> getRHist(void) const;

	void setID(fixedString);
	void setID(string);
	void setPID(fixedString);
	void setPID(string);
	void setRE(string);
	void setLHash(fixedString);
	void setLHash(string);
	void setRHash(fixedString);
	void setRHash(string);
	void setLHist(vector<fixedString>);
	void setRHist(vector<fixedString>);
	void appendLHist(fixedString);
	void appendLHist(string);
	void appendRHist(fixedString);
	void appendRHist(string);
private:
	fixedString ID;
	fixedString PID;
	string RE;
	fixedString LHash;
	fixedString RHash;
	vector<fixedString> LHist;
	vector<fixedString> RHist;
};

#endif