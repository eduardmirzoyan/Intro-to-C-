// Lab 2: Taxaiton
// Shows different taxes of a sale
//
// By: Eduard Mirzoyan
// Email: eduardmirzoyan123@gmail.com
// Date: 7/15/19

#include <iostream>
#include <iomanip>
#include <string>
#define STATE_SALES_TAX_RATE 0.053
// Definition rate is stored as a decimal instead of percent
using namespace std;

int main()
{
	int year;
	double totalAmount;
	string month;
	const double COUNTY_SALES_TAX_RATE = 0.031;
	// Constant rate stored as a decimal instead of percent

	cout << "What is the month? ";
	cin >> month;
	cout << "What is the year? ";
	cin >> year;
	cout << "What is the total amount? ";
	cin >> totalAmount;

	double totalSales = totalAmount / (1 + STATE_SALES_TAX_RATE + COUNTY_SALES_TAX_RATE);
	double totalSalesTax = totalAmount - totalSales;
	double countyTax = (COUNTY_SALES_TAX_RATE / (STATE_SALES_TAX_RATE + COUNTY_SALES_TAX_RATE))* totalSalesTax;
	double stateTax = (STATE_SALES_TAX_RATE / (STATE_SALES_TAX_RATE + COUNTY_SALES_TAX_RATE)) * totalSalesTax;
	// Calculates the tax amounts before output

	cout << setprecision(2) << fixed << endl << endl;
	cout << "Month: " << month << ", " << year << endl;
	cout << setfill('-') << setw(30) << ""  << setfill(' ') << endl; // Makes sure dotted line got to the dollar symbol
	cout << setw(30) << left << "Total Collected:" << right << "$" << setw(20) << totalAmount << endl;
	cout << setw(30) << left << "Sales:" << right << "$" << setw(20) << totalSales << endl;
	cout << setw(30) << left << "County Sales Tax:" << right << "$" << setw(20) << countyTax << endl;
	cout << setw(30) << left << "State Sales Tax:" << right << "$" << setw(20) << stateTax << endl;
	cout << setw(30) << left << "Total Sales Tax:" << right << "$" << setw(20) << totalSalesTax << endl;
}

/*
What is the month? March
What is the year? 2019
What is the total amount? 81673.67


Month: March, 2019
------------------------------
Total Collected:              $            81673.67
Sales:                        $            75344.71
County Sales Tax:             $             2335.69
State Sales Tax:              $             3993.27
Total Sales Tax:              $             6328.96

C:\Ed's Stuff\C++\Intro to C++\Debug\Lab 2.exe (process 11352) exited with code 0.
Press any key to close this window . . .

*/