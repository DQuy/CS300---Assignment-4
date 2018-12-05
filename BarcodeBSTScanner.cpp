// BarcodeBSTScanner.cpp


#include "BinarySearchTree.h"
#include "Item.h"

#include <iostream>
#include <sstream>
#include <string>
#include <time.h>

using namespace std;

const int SIZE = 10000;

// create a binary search tree 
BinarySearchTree <Item> myTree;

// Function load the barcode into a binary search tree
void loadBST () {
	
	// read in a provided data file 
	ifstream myFile("upc_corpus.txt");

	// check if the data file is opened or not
	if (!myFile.is_open()) {
		cout << "File failed to open" << endl;
	}

	int counter = 0;						// create a counter to control the data to read
	string line;
	string barcode;
	string description;

	while (getline(myFile, line) && counter < SIZE) {		// read the text file myFile and store into a line
		stringstream ss (line);					// pass the line into a stringstream class ss
		getline (ss, barcode, ',');				// read the stringstream class ss and store the first string before the comma
		getline (ss, description);				// read next ss to store into the next string and stop at th
		counter++;						// increment the counter after read each line of the file

		Item *c = new Item (barcode, description);
		myTree.insert(*c);					// load into a binary search tree

		cout << barcode << " " << description << endl;		// print out the content after loading into the tree
	}

	myFile.close();							// close the file
}

// Function to search an item in a binary search tree including recording the time of performance
void searchBST () {
	string barcode;

	cout << "---------------------------------------------------" << endl;
	cout << "Please Enter a Barcode to Search: ";			// ask a user for a barcode
	cin >> barcode;

	Item *searchItem = new Item (barcode);

	clock_t t;							// clock the time of the operation
	t = clock();

        Item result = myTree.search(*searchItem);			// create a item with only the bardoe
	if (result.barcode == barcode ) {				// check if the barcode and search item has matched
	
		cout << "UPC Barcode: " << barcode << '\n' << result.description << endl;
	}								// print out the mathch of barcode and its description

	else {
		cout <<" Barcode not Found" << endl;			// inform the user if it is not found
	}

	t = clock() - t;						// clock the time after the operation

	cout << "BST Search time: " << t << " miliseconds" << endl;	// print out the time of the operation
	cout << "--------------------------------------------------" << endl;
}


int main () {


	loadBST();							// perform the load into the binary search tree
	
	searchBST();							// perform the search operation

	return 0;
}

