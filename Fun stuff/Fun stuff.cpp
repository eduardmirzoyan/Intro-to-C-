// Fun stuff.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>

#define lbsInKilo 2.20462
#define cmInInch 2.54

using namespace std;

void convertWeightToKilo(double weight);
void convertWeightToPound(double weight);
void convertHeightToCm(int feet, int inch);

int main()
{
	int feet;
	int inch;


	cout << "How many feet are you? ";
	cin >> feet;
	cout << "How many inches are left? ";
	cin >> inch;

	cout << setprecision(2) << fixed;
	convertHeightToCm(feet, inch);

	return 0;
}

void convertWeightToKilo(double weight) {
	cout << endl << "Your weight in kilos is: " << weight / lbsInKilo;
}

void convertWeightToPound(double weight) {
	cout << endl << "Your weight in pounds is: " << weight * lbsInKilo;
}

void convertHeightToCm(int feet, int inch) {
	cout << endl << "Your heigh in centimeters is: " << (feet * 12 + inch) * cmInInch;
}