// Node.cpp
// Thomas Wise
// COSC 2030
// Project 02
// 15 Dec 2018

#include "Node.h"

// Creates a node with no info
node::node(void)
{
	setID("");
	setPID("");
	setRE("");
	setLHash("");
	setRHash("");
}

// Creates a node from a string
node::node(string RE)
{
	setID("");
	setPID("");
	setRE(RE);
	setLHash("");
	setRHash("");
}

// Creates a node from a string and the parent node
node::node(string RE, node& x)
{
	setID("");
	setPID(x.getID());
	setRE(RE);
	setLHash("");
	setRHash("");
}

// Copy constructor
node::node(const node& x)
{
	setID(x.getID());
	setPID(x.getPID());
	setRE(x.getRE());
	setLHash(x.getLHash());
	setRHash(x.getRHash());
	setLHist(x.getLHist());
	setRHist(x.getRHist());
}

// Destructor
node::~node(void)
{
}

// The next several simply access all of the elements of a node
fixedString node::getID(void) const
{
	return ID;
}

fixedString node::getPID(void) const
{
	return PID;
}

string node::getRE(void) const
{
	return RE;
}

fixedString node::getLHash(void) const
{
	return LHash;
}

fixedString node::getRHash(void) const
{
	return RHash;
}

vector<fixedString> node::getLHist(void) const
{
	return LHist;
}

vector<fixedString> node::getRHist(void) const
{
	return RHist;
}

// The next several change the values of elements in the node
void node::setID(fixedString x)
{
	ID.setString(x);
}

void node::setID(string x)
{
	ID.setString(x);
}

void node::setPID(fixedString x)
{
	PID.setString(x);
}

void node::setPID(string x)
{
	PID.setString(x);
}

void node::setRE(fixedString x)
{
	for (int i = 0; i < 8; i++)
	{
		RE[i] = x.getChar(i);
	}
}

void node::setRE(string x)
{
	RE = x;
}

void node::setLHash(fixedString x)
{
	LHash.setString(x);
}

void node::setLHash(string x)
{
	LHash.setString(x);
}

void node::setRHash(fixedString x)
{
	RHash.setString(x);
}

void node::setRHash(string x)
{
	RHash.setString(x);
}

void node::setLHist(vector<fixedString> x)
{
	LHist = x;
}

void node::setRHist(vector<fixedString> x)
{
	RHist = x;
}


// These append elements to the left and right histories of the node
void node::appendLHist(fixedString x)
{
	LHist.push_back(x);
}

void node::appendLHist(string x)
{
	LHist.push_back(fixedString(x));
}

void node::appendRHist(fixedString x)
{
	RHist.push_back(x);
}

void node::appendRHist(string x)
{
	RHist.push_back(fixedString(x));
}