/*****************************************************************************/
//  Filename:      Lab4.cpp
//
//  Author:        Eduard Mirzoyan
//
//  Date:          2019.07.24
//
//  Modifications: Eduard Mirzoyan – 2019.07.24
//
//
//  Description:   This program calculates the number of books needed for a 
//				   class of students based on the book's nessesity. It also
//				   finds the profit gains froming selling said books.
//
/*****************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#define PROFIT_SELL_RATE 0.8;

int main()
{
	// Prototypes
	int calcNumOfBooks(double price, double rate, int students);
	double calculateProfit(int bookAmount, int bookPrice);
	void printOutput(int neededCopies, double profit, string ISBNcode);

	// Constants
	const double requiredAndNew = 0.9;
	const double requiredAndOld = 0.65;
	const double suggestedAndNew = .4;
	const double suggestedAndOld = 0.2;

	// Values and Rates in decimal
	bool isRequired, isNew;
	char bookState, bookRequirement;
	int classSize;
	double bookPrice;
	string ISBNcode;

	double expectedSellRate;

	// Gets input for book properties
	cout << "What is the book's ISBN number? ";
	cin >> ISBNcode;
	cout << "What is the book's price? ";
	cin >> bookPrice;
	cout << "How many students enrolled in the class? ";
	cin >> classSize;
	cout << "Is the book required (R) or suggested (S)? ";
	cin >> bookRequirement;
	cout << "Is the book new (N) or old (O)? ";
	cin >> bookState;

	// Sets the sellrate based on input
	if (toupper(bookRequirement) == 'R' && toupper(bookState) == 'N') {
		expectedSellRate = requiredAndNew;
	}
	if (toupper(bookRequirement) == 'R' && toupper(bookState) == 'O') {
		expectedSellRate = requiredAndOld;
	}
	if (toupper(bookRequirement) == 'S' && toupper(bookState) == 'N') {
		expectedSellRate = suggestedAndNew;
	}
	if (toupper(bookRequirement) == 'S' && toupper(bookState) == 'O') {
		expectedSellRate = suggestedAndOld;
	}
	if (toupper(bookRequirement) != 'R' && toupper(bookRequirement) != 'S' || toupper(bookState) != 'N'  && toupper(bookState) != 'O') {
		cout << endl << "Not a valid input, exiting program..." << endl;
		exit(0);
	}

	cout << expectedSellRate;

	// Calculates profit and needed books
	int neededCopies = calcNumOfBooks(bookPrice, expectedSellRate, classSize);
	int profit = calculateProfit(neededCopies, bookPrice);

	// Prints output of gathered information
	printOutput(neededCopies, profit, ISBNcode);
}

int calcNumOfBooks(double price, double rate, int students) {
	return static_cast<int>(students * rate + 0.5);
}

double calculateProfit(int bookAmount, int bookPrice) {
	return bookAmount * bookPrice * PROFIT_SELL_RATE;
}

void printOutput(int neededCopies, double profit, string ISBNcode) {
	cout << endl << "ISBN: " << ISBNcode;
	cout << endl << "Copies Needed: " << neededCopies;
	cout << endl << setprecision(2) << fixed << "Profit: $" << profit;
}

/* SET 1
What is the book's ISBN number? 0755798652
What is the book's price? 34.98
How many students enrolled in the class? 31
Is the book required (R) or suggested (S)? R
Is the book new (N) or old (O)? O

ISBN: 0755798652
Copies Needed: 20
Profit: $544.00
C:\Ed's Stuff\C++\Intro to C++\Debug\Lab 4.exe (process 15300) exited with code 0.
Press any key to close this window . . .
*/

/* SET 2
What is the book's ISBN number? 3453456784
What is the book's price? 23.95
How many students enrolled in the class? 100
Is the book required (R) or suggested (S)? r
Is the book new (N) or old (O)? N

ISBN: 3453456784
Copies Needed: 90
Profit: $1656.00
C:\Ed's Stuff\C++\Intro to C++\Debug\Lab 4.exe (process 6168) exited with code 0.
Press any key to close this window . . .
*/

/* SET 3
What is the book's ISBN number? 5677655673
What is the book's price? 54.50
How many students enrolled in the class? 40
Is the book required (R) or suggested (S)? R
Is the book new (N) or old (O)? O

ISBN: 5677655673
Copies Needed: 26
Profit: $1123.00
C:\Ed's Stuff\C++\Intro to C++\Debug\Lab 4.exe (process 4504) exited with code 0.
Press any key to close this window . . .
*/

/* SET 4
What is the book's ISBN number? 2462462464
What is the book's price? 5.95
How many students enrolled in the class? 40
Is the book required (R) or suggested (S)? s
Is the book new (N) or old (O)? O

ISBN: 2462462464
Copies Needed: 8
Profit: $32.00
C:\Ed's Stuff\C++\Intro to C++\Debug\Lab 4.exe (process 13864) exited with code 0.
Press any key to close this window . . .
*/

/* SET 5
What is the book's ISBN number? 8953647888
What is the book's price? 65.99
How many students enrolled in the class? 35
Is the book required (R) or suggested (S)? N
Is the book new (N) or old (O)? Y

Not a valid input, exiting program...

C:\Ed's Stuff\C++\Intro to C++\Debug\Lab 4.exe (process 3788) exited with code 0.
Press any key to close this window . . .
*/