// Node.cpp
// Thomas Wise
// COSC 2030
// Project 02
// 15 Dec 2018

#include "Node.h"

node::node(void)
{
	setID("");
	setPID("");
	setRE("");
	setLHash("");
	setRHash("");
}

node::node(string RE)
{
	setID("");
	setPID("");
	setRE(RE);
	setLHash("");
	setRHash("");
}

node::node(string RE, node& x)
{
	setID("");
	setPID(x.getID());
	setRE(RE);
	setLHash("");
	setRHash("");
}

node::node(node& x)
{
	setID(x.getID());
	setPID(x.getPID());
	setRE(x.getRE);
	setLHash(x.getLHash());
	setRHash(x.getRHash());
	setLHist(x.getLHist());
	setRHist(x.getRHist());
}

node::~node(void)
{
	LHist.clear();
}

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