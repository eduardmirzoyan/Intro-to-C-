/*****************************************************************************/
//  Filename:      Lab5.cpp
//
//  Author:        Eduard Mirzoyan
//
//  Date:          2019.07.31
//
//  Modifications: Eduard Mirzoyan – 2019.07.31
//
//
//  Description:   This program does gets user input about house selling price
//				   intrest rate and time for the loan. Calculates the loan
//				   mortgage and total monthly costs for the house. The program
//				   outs the results to a text file.
//				   
//
/*****************************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>

// Tax rates are saved as a decimal
#define TAX_RATE 0.0125
#define COST_OF_INSURANCE 550.00
#define COST_OF_UTILITIES 300.00

using namespace std;

// Prototypes of functions
void getMortgageData(double& sellingPrice, double& rateOfIntrest, int& loanYears);
double computeDownPayment(double sellingPrice, double downRate);
double computeLoan(double downPayment, double sellingPrice);
double computeMortgage(double loan, double intrestRate, int time);
double calcMonthlyCosts(double loan, double intrestRate, int time, int sellingPrice);
void outputToText(double sellingPrice, double downPayment, double loan, double intrestRate, int loanTime, double mortgage, double monthlyCost);

int main()
{
	const double DOWN_PAYMENT_RATE = 0.2;

	double sellingPrice;
	double rateOfIntrest;
	int loanYears;

	// Gets user input of selling price, intrest rate and loan length of house
	getMortgageData(sellingPrice, rateOfIntrest, loanYears);

	// Calculates various properties of the house
	double downPayment = computeDownPayment(sellingPrice, DOWN_PAYMENT_RATE);
	double loan = computeLoan(DOWN_PAYMENT_RATE, sellingPrice);
	double mortgage = computeMortgage(loan, rateOfIntrest, loanYears);
	double monthlyCosts = calcMonthlyCosts(DOWN_PAYMENT_RATE, rateOfIntrest, loanYears, sellingPrice);

	// Outputs gathered information to text file
	outputToText(sellingPrice, downPayment, loan, rateOfIntrest, loanYears, mortgage, monthlyCosts);
}

void getMortgageData(double &sellingPrice, double &rateOfIntrest, int &loanYears) {
	cout << "What is the selling price? ";
	cin >> sellingPrice;
	cout << "What is the intrest rate? ";
	cin >> rateOfIntrest;
	rateOfIntrest /= 100;
	cout << "How many years are on the loan? ";
	cin >> loanYears;
}

// Calculates down payments of the house
double computeDownPayment(double sellingPrice, double downRate) {
	return sellingPrice * downRate;
}

// Calculates the loan of the house
double computeLoan(double downPaymentRate, double sellingPrice) {
	return sellingPrice - downPaymentRate * sellingPrice;
}

// Calculates the mortgage of the house
double computeMortgage(double loan, double intrestRate, int time) {
	time *= 12;
	intrestRate /= 12;
	return ((loan * intrestRate * pow(1 + intrestRate, time) / (pow(1 + intrestRate, time) - 1)));
}

// Calculates the monthly costs
double calcMonthlyCosts(double downRate, double intrestRate, int time, int sellingPrice) {
	double loan = computeLoan(downRate, sellingPrice);

	return computeMortgage(loan, intrestRate, time) + COST_OF_UTILITIES + (TAX_RATE * sellingPrice) / 12 + COST_OF_INSURANCE / 12;
}

// Outputs values to text file
void outputToText(double sellingPrice, double downPayment, double loan, double intrestRate, int loanTime, double mortgage, double monthlyCost) {
	ofstream fileOut;
	string fullname = "Mortgage.txt";
	fileOut.open(fullname.c_str());

	if (!fileOut.fail()) {
		fileOut;
		fileOut << setfill('*') << setw(70) << right << "";
		fileOut << endl << setfill(' ') << setw(25) << "" << "Monthly Cost of House" << endl;
		fileOut << setfill('*') << setw(70) << right << "";
		fileOut << setprecision(2) << fixed << setfill(' ') << endl;
		
		fileOut << setw(60) << left << "SELLING PRICE" << right << "$" << setw(8) << sellingPrice << endl;
		fileOut << setw(60) << left << "DOWN PAYMENT" << right << "$" << setw(8) << downPayment << endl;
		fileOut << setw(60) << left << "AMOUNT OF LOAN" << right << "$" << setw(8) << loan << endl << endl;

		fileOut << setw(30) << left << "INTREST RATE" << right << setw(8) << intrestRate * 100 << "%" << endl;
		fileOut << setw(30) << left << "TAX RATE" << right << setw(8) << TAX_RATE * 100 << "%" << endl << endl;

		fileOut << setw(30) << left << "DURATION OF LOAN (YEARS)" << right << setw(5) << loanTime << " yrs" << endl << endl << endl;


		fileOut << setw(20) << setfill('*') << right << "";
		fileOut << endl << "MONTHLY PATYMENT" << endl;
		fileOut << setw(20) << setfill('*') << right << "" << setfill(' ') << endl;

		fileOut << setw(60) << left << "MORTGAGE PAYMENT" << right << "$" << setw(8) << mortgage  << endl;
		fileOut << setw(60) << left << "UTILITIES" << right << "$" << setw(8) << COST_OF_UTILITIES << endl;
		fileOut << setw(60) << left << "PROPERTY TAXES" << right << "$" << setw(8) << (TAX_RATE * sellingPrice) / 12 << endl;
		fileOut << setw(60) << left << "INSURANCE" << right << "$" << setw(8) << COST_OF_INSURANCE / 12 << endl;
		
		fileOut << endl << setw(70 - 16) << "" << setw(16) << setfill('-') << "" << setfill(' ') << endl;
		fileOut << setw(60) << left << "" << right << "$" << setw(8) << monthlyCost << endl;

	}
	cout << endl << "You're mortgage bill is complete!";
	fileOut.close();
}