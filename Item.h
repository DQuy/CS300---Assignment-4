// Item.h

#ifndef ITEM_H_
#define ITEM_H_

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


class Item {
	public:
		string barcode;
		string description;

		// Default constructor
		Item () {}

		// Overload constructor
		Item (string barcode){
			this -> barcode = barcode;
		}

		// Overload constructor
		Item (string barcode, string description) {
			this -> barcode = barcode;
			this -> description = description;
		}

		const string& getBarcode () const {
			return barcode;
		}

		void setBarcode (const string& barcode) {
			this -> barcode = barcode;
		}

		const string& getDescription () const {
			return description;
		}

		void setDescription (const string& description) {
			this -> description = description;
		}

		friend ostream & operator << (ostream &os, Item & c) {
			os << c.barcode << " " << c.description ;
			return os;
		}

		friend bool operator < (const Item& a, const Item& b) {
			return a.barcode < b.barcode;
		}

		friend bool operator > (const Item& a, const Item& b) {
			return a.barcode > b.barcode;
		}

		friend bool operator == (const Item& a, const Item& b) {
			return a.barcode + a.description == b.barcode + b.description;
		}
};

#endif

