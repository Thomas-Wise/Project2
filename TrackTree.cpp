// TrackTree.cpp
// Thomas Wise
// COSC 2030
// Project 02
// 15 Dec 2018

#include "TrackTree.h"
#include <time.h>

trackTree::trackTree(void)
{
	srand(time(NULL));
	int temp;
	string RE, PID;
	for (int i = 0; i < 8; i++)
	{
		temp = rand() % 256;
		RE += static_cast<char>(temp);
		temp = rand() % 256;
		PID += static_cast<char>(temp);
	}
	node head;
	head.setRE(RE);
	head.setPID(PID);
	hash PIDHash(PID);
	hash REHash(RE);
	hash IDHash;
	IDHash.setHash(PIDHash + REHash);
	head.setID(IDHash.getString());
	tree.push_back(head);
	layers = 1;
}

trackTree::trackTree(string RE)
{
	srand(time(NULL));
	int temp;
	string PID;
	for (int i = 0; i < 8; i++)
	{
		temp = rand() % 256;
		PID += static_cast<char>(temp);
	}
	node head;
	head.setRE(RE);
	head.setPID(PID);
	hash PIDHash(PID);
	hash REHash(RE);
	hash IDHash;
	IDHash.setHash(PIDHash + REHash);
	head.setID(IDHash.getString());
	tree.push_back(head);
	layers = 1;
}

trackTree::trackTree(fixedString RE)
{
	srand(time(NULL));
	int temp;
	string PID;
	for (int i = 0; i < 8; i++)
	{
		temp = rand() % 256;
		PID += static_cast<char>(temp);
	}
	node head;
	head.setRE(RE);
	head.setPID(PID);
	hash PIDHash(PID);
	hash REHash(RE);
	hash IDHash;
	IDHash.setHash(PIDHash + REHash);
	head.setID(IDHash.getString());
	tree.push_back(head);
	layers = 1;
}

trackTree::trackTree(node x)
{
	node head(x);
	tree.push_back(head);
	layers = 1;
}

trackTree::~trackTree(void)
{
}

node trackTree::getNode(int i) const
{
	return tree[i];
}

void trackTree::addLayer(void)
{
	
}