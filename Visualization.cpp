// Visualization.cpp
// Thomas Wise
// COSC 2030
// Project 02
// 15 Dec 2018

#include "Visualization.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// Displays the first three rows of the tree
void showTree(trackTree tree)
{
	int layers = tree.getLayers();
	int currentLayer = 1;
	string tab = "\t\t\t";
	if (layers > 3)
	{
		layers = 3;
	}

	while (currentLayer <= layers)
	{
		if (currentLayer == 1)
		{
			cout << tab << tab << "ID:  " << tree.getNode(0).getID() << endl;
			cout << tab << tab << "PID: " << tree.getNode(0).getPID() << endl;
			cout << tab << tab << "RE:  " << tree.getNode(0).getRE() << endl;
			cout << tab << tab << "LH:  " << tree.getNode(0).getLHash() << endl;
			cout << tab << tab << "RH:  " << tree.getNode(0).getRHash() << endl << endl << endl;
		}
		else if (currentLayer == 2)
		{
			cout << tab << "ID:  " << tree.getNode(1).getID() << tab << tab << "ID:  " << tree.getNode(2).getID() << endl;
			cout << tab << "PID: " << tree.getNode(1).getPID() << tab << tab << "PID: " << tree.getNode(2).getPID() << endl;
			cout << tab << "RE:  " << tree.getNode(1).getRE() << tab << tab << "RE:  " << tree.getNode(2).getRE() << endl;
			cout << tab << "LH:  " << tree.getNode(1).getLHash() << tab << tab << "LH:  " << tree.getNode(2).getLHash() << endl;
			cout << tab << "RH:  " << tree.getNode(1).getRHash() << tab << tab << "RH:  " << tree.getNode(2).getRHash() << endl << endl << endl;
		}
		else if (currentLayer == 3)
		{
			cout << "ID:  " << tree.getNode(3).getID() << "\t" << "ID:  " << tree.getNode(4).getID() << tab << tab << "ID:  " << tree.getNode(5).getID() << "\t" << "ID:  " << tree.getNode(6).getID() << endl;
			cout << "PID: " << tree.getNode(3).getPID() << "\t" << "PID: " << tree.getNode(4).getPID() << tab << tab << "PID: " << tree.getNode(5).getPID() << "\t" << "PID: " << tree.getNode(6).getPID() << endl;
			cout << "RE:  " << tree.getNode(3).getRE() << "\t" << "RE:  " << tree.getNode(4).getRE() << tab << tab << "RE:  " << tree.getNode(5).getRE() << "\t" << "RE:  " << tree.getNode(6).getRE() << endl;
			cout << "LH:  " << tree.getNode(3).getLHash() << "\t" << "LH:  " << tree.getNode(4).getLHash() << tab << tab << "LH:  " << tree.getNode(5).getLHash() << "\t" << "LH:  " << tree.getNode(6).getLHash() << endl;
			cout << "RH:  " << tree.getNode(3).getRHash() << "\t" << "RH:  " << tree.getNode(4).getRHash() << tab << tab << "RH:  " << tree.getNode(5).getRHash() << "\t" << "RH:  " << tree.getNode(6).getRHash() << endl << endl << endl;
		}
		currentLayer++;
	}
}

// Shows the information for one specific node in the tree
void showNode(trackTree tree)
{
	int i = -1;
	cout << endl << "Please enter the index for the node you want to see(0 - " << (tree.getSize() - 1) << ")" << endl;
	while (i < 0 || i > (tree.getSize() - 1))
	{
		while (!(cin >> i))
		{
			cin.clear();
			cin.ignore();
		}
	}
	cout << "ID:  " << tree.getNode(i).getID() << endl;
	cout << "PID: " << tree.getNode(i).getPID() << endl;
	cout << "RE:  " << tree.getNode(i).getRE() << endl;
	cout << "LH:  " << tree.getNode(i).getLHash() << endl;
	cout << "RH:  " << tree.getNode(i).getRHash() << endl << endl;

	cout << "LeftHistory:" << endl;
	for (int j = 0; j < tree.getNode(i).getLHist().size(); j++)
	{
		cout << tree.getNode(i).getLHist()[j] << endl;
	}
	cout << endl;

	cout << "RightHistory:" << endl;
	for (int j = 0; j < tree.getNode(i).getRHist().size(); j++)
	{
		cout << tree.getNode(i).getRHist()[j] << endl;
	}
	cout << endl << endl;
}

// Changes the RE of one node in the tree
void changeNode(trackTree& tree)
{
	int nodeIndex = -1;
	string newRE;
	cout << endl << "Please enter the index of the node you would like to change (0 - " << (tree.getSize() - 1) << ")" << endl;
	while (nodeIndex < 0 || nodeIndex >(tree.getSize() - 1))
	{
		while (!(cin >> nodeIndex))
		{
			cin.clear();
			cin.ignore();
		}
	}

	cout << endl << "Please enter the new value for RE:" << endl;
	cin >> newRE;
	tree.updateRE(nodeIndex, newRE);
	cout << endl << endl;
}