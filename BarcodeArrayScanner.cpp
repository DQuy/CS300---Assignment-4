// BarcodeArrayScanner.cpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>

using namespace std;

struct barcodeInfo
{	string barcode;
	string description;
};

ostream& operator << (ostream& os, const barcodeInfo& barcodeInfo) {
	return os << "Barcode: " << barcodeInfo.barcode << endl
		  << "" << barcodeInfo.description << endl;
}

const int ARRAY_SIZE = 10000;

barcodeInfo myArray [ARRAY_SIZE];

void loadArray() {

	ifstream myFile ("upc_corpus.txt");						// read a text file into an object

	if (!myFile.is_open()) {							// confirm if the file is opened or not
		cout << "File failed to open" << endl;					// print out if it is not opened
	}	

	string line, barcode, description;
	int i = 0;									// create a counter to control the size

	while (getline(myFile, line) && i < ARRAY_SIZE) {				// read the file into each line and stop if the counter 
											// reaches the array size
		stringstream ss (line);							// read each line as an object
		getline (ss, myArray[i].barcode, ',');					// read the line until the stopper commna and store it
		getline (ss, myArray[i].description);					// read after the commna and store it into array
		i++;									// increment the counter after a line processed
		}

	myFile.close();									// close the file

	for (int j=0; j < ARRAY_SIZE; j++) {						// loop through the array
		cout << myArray[j].barcode << " - " << myArray[j].description <<endl;	// print out the load operation
	}
}

int searchArray () {
	string searchItem;

	cout << "--------------------------------------------" << endl;
	cout << "Please Enter a Barcode to Search: " ;					// ask a user for a barcode to search
	cin >> searchItem;								// read in as a search item
	int found = 0;									// set the value boolean to 0

	clock_t t;
	t = clock ();									// start clock the time of operation
	
	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (myArray[i].barcode.compare(searchItem) == 0) {			// compare two string, 0 means they are matched
			found = 1;							// change the boolean to true (1) to break from
			break;								// from the loop
		}
	}
	if (found) {
		cout << "UPC Code: " << searchItem << '\n' <<myArray[1].description <<endl; 	// print out the search result
	}
	else {
		cout << "Not Found" << endl;						// print out if not found
	}

	t = clock () - t;								// calculate the time of the operation

	cout << "Array Search time: " << t << " miliseconds" << endl;			// print out the time of operations
	cout << "----------------------------------------------" << endl;
	return 0;
}


int main () {
	
	loadArray();

	searchArray();

	return 0;
}

