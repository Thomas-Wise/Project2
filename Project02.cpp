// Project02.cpp
// Thomas Wise
// COSC 2030
// Project 02
// 14 Dec 2018

// This will be the main file of the project.

#include "TrackTree.h"
#include "Visualization.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;


int main()
{
	bool skip = false;
	string input;
	cout << "Please enter the first entry for the tree:" << endl;
	cin >> input;
	trackTree tree(input);

	while (input != "done")
	{
		cout << "Please enter the next entry for the tree:" << endl;
		cout << "(\"done\" to exit / \"show\" to view tree)" << endl;
		cout << "(\"node\" to view a single node)" << endl;
		cout << "(\"change\" to change RE of a node)" << endl;
		cin >> input;

		if (input == "done")
		{
			break;
		}
		if (input == "show")
		{
			showTree(tree);
			skip = true;
		}
		if (input == "node")
		{
			showNode(tree);
			skip = true;
		}
		if (input == "change")
		{
			changeNode(tree);
			skip = true;
		}

		if (skip == false)
		{
			tree.addEntry(input);
		}
		else
		{
			skip = false;
		}
	}
	return 0;
}
