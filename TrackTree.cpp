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
		temp = rand() % 10;
		RE += temp;
		temp = rand() % 10;
		PID += temp;
	}
	node head;
	head.setRE(RE);
	head.setPID(PID);
	tree.push_back(head);
}

trackTree::trackTree(string RE)
{
	node head;
	head.setRE(RE);
}