// TrackTree.h
// Thomas Wise
// COSC 2030
// Project 02
// 15 Dec 2018

#ifndef TRACK_TREE_H
#define TRACK_TREE_H

#include "Node.h"
#include "FixedString.h"
#include "Hash.h"

class trackTree
{
public:
	trackTree(void);
	trackTree(string);
	trackTree(fixedString);
	trackTree(node);
	~trackTree(void);
	node getNode(int) const;
	int getLayers(void) const;
	int getSize(void) const;
	void addLayer(string);
	void addEntry(string);
	void updateRE(int, string);
	void updateParent(int);
private:
	vector<node> tree;
	int layers;
	int place;
};

#endif