// TrackTree.cpp
// Thomas Wise
// COSC 2030
// Project 02
// 15 Dec 2018

#include "TrackTree.h"
#include <time.h>

// Constructors for the tracking tree
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
	place = 1;
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
	place = 1;
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
	place = 1;
}

trackTree::trackTree(node x)
{
	node head(x);
	tree.push_back(head);
	layers = 1;
	place = 1;
}

trackTree::~trackTree(void)
{
}

// These access the elements of the tree
node trackTree::getNode(int i) const
{
	return tree[i];
}

int trackTree::getLayers(void) const
{
	return layers;
}

int trackTree::getSize(void) const
{
	return tree.size();
}

// Adds all the necessary nodes for a new layer
void trackTree::addLayer(string RE)
{
	int newNodes, currentNode, parentNode;
	newNodes = layers * 2;
	int start = tree.size();
	currentNode = start;
	parentNode = (currentNode - 1) / 2;

	tree.push_back(node(RE));
	tree[currentNode].setPID(tree[parentNode].getID());

	hash PIDHash(tree[currentNode].getPID());
	hash REHash(tree[currentNode].getRE());
	hash IDHash;
	IDHash.setHash(PIDHash + REHash);
	tree[currentNode].setID(IDHash.getString());
	updateParent(currentNode);
	for (int i = 1; i < newNodes; i++)
	{
		currentNode = start + i;
		parentNode = (currentNode - 1) / 2;
		tree.push_back(node());
		tree[currentNode].setPID(tree[parentNode].getID());
	}
	layers++;
}

// Fills the next node in the bottom layer. If the bottom
// layer is full, it calls the addLayer function.
void trackTree::addEntry(string RE)
{
	if (place == (tree.size()))
	{
		addLayer(RE);
	}
	else
	{
		tree[place].setRE(RE);
		hash PIDHash(tree[place].getPID());
		hash REHash(tree[place].getRE());
		hash IDHash(PIDHash + REHash);
		tree[place].setID(IDHash.getString());
		updateParent(place);
	}
	place++;
}

// Allows for the RE to be updated after it already has something.
void trackTree::updateRE(int i, string x)
{
	tree[i].setRE(x);
	updateParent(i);
}

// Updates the parent of the current node and its parent and so on
// all the way up the tree
void trackTree::updateParent(int currentNode)
{
	if (currentNode != 0)
	{
		int parentNode = (currentNode - 1) / 2;
		hash IDHash(tree[currentNode].getID());
		hash PIDHash(tree[currentNode].getPID());
		hash REHash(tree[currentNode].getRE());
		hash LHash(tree[currentNode].getLHash());
		hash RHash(tree[currentNode].getRHash());
		hash newHash(IDHash + PIDHash + REHash + LHash + RHash);

		if ((currentNode % 2) == 1)
		{
			tree[parentNode].setLHash(newHash.getString());
			tree[parentNode].appendLHist(newHash.getString());
		}
		else
		{
			tree[parentNode].setRHash(newHash.getString());
			tree[parentNode].appendRHist(newHash.getString());
		}
		updateParent(parentNode);
	}
}