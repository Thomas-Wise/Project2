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
	void addLayer(void);
	void updateRE(int);
	void updateID(void);
	void updateLHash(void);
	void updateRHash(void);
	void appendLHist(void);
	void appendRHist(void);
private:
	vector<node> tree;
	int layers;
};

#endif