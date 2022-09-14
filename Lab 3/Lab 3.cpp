/*****************************************************************************/
//  Filename:      Lab3.cpp
//
//  Author:        Eduard Mirzoyan
//
//  Date:          2019.07.18
//
//  Modifications: Eduard Mirzoyan – 2019.07.19
//
//
//  Description:   This program calculates the total cost of a purchase
//				   various electronics, neatly formatted.
//
/*****************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#define TAX_RATE 0.0875 // Tax rate is stored as a decimal instead of percent
using namespace std;

int main()
{
	// Constant value for each electronic
	const double tvPrice = 500.00;
	const double dvdPlayerPrice = 380.00;
	const double remoteControllerPrice = 35.20;
	const double cdPlayerPrice = 74.50;
	const double avProcessorPrice = 1500.00;

	// Total amounts of each electronic
	int tvAmount;
	int dvdPlayerAmount;
	int remoteControllerAmount;
	int cdPlayerAmount;
	int avProcessorAmount;

	// Asks user for the amount of each electronic sold
	cout << "How many TVs were sold? ";
	cin >> tvAmount;
	cout << endl << "How many DVD Players were sold? ";
	cin >> dvdPlayerAmount;
	cout << endl << "How many remote Controllers were sold? ";
	cin >> remoteControllerAmount;
	cout << endl << "How many CD Players were sold? ";
	cin >> cdPlayerAmount;
	cout << endl << "How many AV Processors were sold? ";
	cin >> avProcessorAmount;

	// Calculate values before printing
	double tvTotal = tvAmount * tvPrice;
	double dvdTotal = dvdPlayerAmount * dvdPlayerPrice;
	double remoteTotal = remoteControllerAmount * remoteControllerPrice;
	double cdTotal = cdPlayerAmount * cdPlayerPrice;
	double avTotal = avProcessorAmount * avProcessorPrice;

	double subTotal = tvTotal + dvdTotal + remoteTotal + cdTotal + avTotal;
	double tax = subTotal * TAX_RATE;
	double grandTotal = tax + subTotal;

	// Sets the money format and table foramt for future values
	cout << setprecision(2) << fixed << endl << endl; 
	cout << "QTY" << setw(15) << "Description" << setw(20) << "Unit Price" << setw(20) << "Total Price" << endl;

	// Only prints the output line for each electronic if the amount is above 0
	if (tvAmount > 0) {
		cout << left << setw(7) << tvAmount << setw(21) << "TV" << right << setw(10) << tvPrice << setw(20) << tvTotal << endl;
	}
	if (dvdPlayerAmount > 0) {
		cout << left << setw(7) << dvdPlayerAmount << setw(21) << "DVD Player" << right << setw(10) << dvdPlayerPrice << setw(20) << dvdTotal << endl;
	}
	if (remoteControllerAmount > 0) {
		cout << left << setw(7) << remoteControllerAmount << setw(21) << "Remote Controller" << right << setw(10) << remoteControllerPrice << setw(20) << remoteTotal << endl;
	}
	if (cdPlayerAmount > 0) {
		cout << left << setw(7) << cdPlayerAmount << setw(21) << "CD Player" << right << setw(10) << cdPlayerPrice << setw(20) << cdTotal << endl;
	}
	if (avProcessorAmount > 0) {
		cout << left << setw(7) << avProcessorAmount << setw(21) << "AV Processor" << right << setw(10) << avProcessorPrice << setw(20) << avTotal << endl;
	}

	// Prints out the totals of all the electronics
	cout << endl << endl;
	cout << left << setw(7) << "" << setw(21) << "" << setw(21) << "Sub Total" << right << setw(9) << subTotal << endl;
	cout << left << setw(7) << "" << setw(21) << "" << setw(21) << "Tax ( 8.75% )" << right << setw(9) << tax << endl;
	cout << left << setw(7) << "" << setw(21) << "" << setw(21) << "Total" << right << setw(9) << grandTotal << endl;
}

/*
Data Set: 13, 2, 3, 1, 21

How many TVs were sold? 13

How many DVD Players were sold? 2

How many remote Controllers were sold? 3

How many CD Players were sold? 1

How many AV Processors were sold? 21


QTY    Description          Unit Price         Total Price
13     TV                       500.00             6500.00
2      DVD Player               380.00              760.00
3      Remote Controller         35.20              105.60
1      CD Player                 74.50               74.50
21     AV Processor            1500.00            31500.00


							Sub Total             38940.10
							Tax ( 8.75% )          3407.26
							Total                 42347.36

C:\Ed's Stuff\C++\Intro to C++\Debug\Lab 3.exe (process 15932) exited with code 0.
Press any key to close this window . . .

*/


/*
Data Set: 0, 2, 0, 1, 0 

How many TVs were sold? 0

How many DVD Players were sold? 2

How many remote Controllers were sold? 0

How many CD Players were sold? 1

How many AV Processors were sold? 0


QTY    Description          Unit Price         Total Price
2      DVD Player               380.00              760.00
1      CD Player                 74.50               74.50


							Sub Total               834.50
							Tax ( 8.75% )            73.02
							Total                   907.52

C:\Ed's Stuff\C++\Intro to C++\Debug\Lab 3.exe (process 3376) exited with code 0.
Press any key to close this window . . .

*/