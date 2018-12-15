// Project02.cpp
// Thomas Wise
// COSC 2030
// Project 02
// 14 Dec 2018

// This will be the main file of the project.

#include "TrackTree.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;


int main()
{
	string input;
	cout << "Please enter the first entry for the tree:" << endl;
	cin >> input;
	trackTree tree(input);

	while (input != "done")
	{
		cout << "Please enter the next entry for the tree:" << endl;
		cin >> input;
		if (input == "done")
		{
			break;
		}
		tree.addEntry(input);
	}
	return 0;
}