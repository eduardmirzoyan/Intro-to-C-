// Lab 1: Change is all you have in your pocket
//
// By: Eduard Mirzoyan
// Email: eduardmirzoyan123@gmail.com
// Date: 7 / 10 / 2019

#include <iostream>
#include <iomanip>
using namespace std;

int pennies, nickles, dimes, quarters; // Contains quanity of each respective coin

int main()
{
	cout << "Solution provided by Eduard Mizoyan" << endl << endl;

	cout << "Please enter the number of quarters: ";
	cin >> quarters;
	cout << "Please enter the number of dimes: ";
	cin >> dimes;
	cout << "Please enter the number of nickles: ";
	cin >> nickles;
	cout << "Please enter the number of pennies: ";
	cin >> pennies;
	//Gather the amount of coins from each catagory

	cout << "Thank you." << endl << endl;


	double sum = (pennies + nickles * 5 + dimes * 10 + quarters * 25) / 100.0; // Formulates the sum of all the coins by scaling them with their respective values
	cout << setprecision(2) << fixed; //Set to always display 2 decimals places

    cout << "The total value of " << quarters << " quarters, " << dimes << " dimes, " << nickles << " nickles and " << pennies << " pennies is $" << sum << "." << endl;
}

/*
Solution provided by Eduard Mizoyan

Please enter the number of quarters: 3
Please enter the number of dimes: 0
Please enter the number of nickles: 5
Please enter the number of pennies: 23
Thank you.

The total value of 3 quarters, 0 dimes, 5 nickles and 23 pennies is $1.23.

C:\Ed's Stuff\C++\Intro to C++\Debug\Lab 1.exe (process 9360) exited with code 0.
Press any key to close this window . . .
*/
