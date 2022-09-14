/*****************************************************************************/
//  Filename:      Lab6.cpp
//
//  Author:        Eduard Mirzoyan
//
//  Date:          2019.08.05
//
//  Modifications: Eduard Mirzoyan – 2019.08.05
//
//
//  Description:   This program gets the credit card debt of a person based on their
//					input values such as starting balance and annual apr. The output
//					is given in a line by line output to a text file.
//				   
//
/*****************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void getUserInput(double& creditCardBalance, double& intrestRate, double& percentOfPayment);
void calculateMonthly(double& creditCardBalance, double intrestRate, double percentOfPayment, double& minimumPayment, double& monthlyIntrest);
void outputResults(ofstream &fileOut, int month, double intrestRate, double percentOfPayment, double creditCardBalance, double monthlyIntrest, double minimumPayment, double totalIntrestPaid);


int main()
{
	double creditCardBalance = 0;
	double intrestRate = 0;
	double percentOfPayment = 0;

	int month = 0;
	double totalIntrestPaid = 0;
	double monthlyIntrest = 0;
	double minimumPayment = 0;
	ofstream fileOut;
	string fullname = "Credit_Card_Debt.txt";

	getUserInput(creditCardBalance, intrestRate, percentOfPayment);

	// Sets the labels for future data
	fileOut.open(fullname.c_str());
	fileOut << setprecision(2) << fixed;
	fileOut << "Balance Owing: $" << creditCardBalance << endl;
	fileOut << "APR as % " << static_cast<int>(intrestRate * 100) << endl;
	fileOut << "Percent for minimum payment as % " << static_cast<int>(percentOfPayment * 100) << endl;
	fileOut << setw(80) << setfill('-') << "" << endl;
	fileOut << setfill(' ') << right << setw(10) << "Month" << setw(20) << "Balance" << setw(20) << "Monthly Intrest" << setw(20) << "Minimum Payment" << setw(20) << "Total Intrest" << endl;

	while (creditCardBalance > 0) {
		calculateMonthly(creditCardBalance, intrestRate, percentOfPayment, minimumPayment, monthlyIntrest);
		totalIntrestPaid += monthlyIntrest;
		month++;
		outputResults(fileOut, month, intrestRate, percentOfPayment, creditCardBalance, monthlyIntrest, minimumPayment, totalIntrestPaid);
	}
	//cout << "Output Complete";

}

// Gets the starting balance, APR and percent of the minimum payment from the user
void getUserInput(double &creditCardBalance, double &intrestRate, double &percentOfPayment) {
	ifstream fileIn;
	string file = "numbers.txt";
	fileIn.open(file.c_str());

	while (!fileIn.fail()) {
		fileIn >> creditCardBalance;
		fileIn >> intrestRate;
		fileIn >> percentOfPayment;

	}
	percentOfPayment /= 100;
	intrestRate /= 100;
	fileIn.close();
}

// Calculates the monthly paymenents required for that month such as the monthly intrest and minimum payment
void calculateMonthly(double& creditCardBalance, double intrestRate, double percentOfPayment, double& minimumPayment, double& monthlyIntrest) {
	const int MINIMUM_PAYMENT = 15;
	monthlyIntrest = creditCardBalance * (intrestRate / 12);
	minimumPayment = creditCardBalance * (1 + intrestRate / 12) * percentOfPayment;

	if (minimumPayment < MINIMUM_PAYMENT)
		minimumPayment = MINIMUM_PAYMENT;
	if (minimumPayment - monthlyIntrest > creditCardBalance) {
		minimumPayment = creditCardBalance + monthlyIntrest;
		creditCardBalance = 0;
	}
	else
		creditCardBalance -= (minimumPayment - monthlyIntrest);
}

// Prints the out of each months properties such as its intrest rate and remaining credicard balance
void outputResults(ofstream &fileOut, int month, double intrestRate, double percentOfPayment, double creditCardBalance, double monthlyIntrest, double minimumPayment, double totalIntrestPaid) {
	if (!fileOut.fail()) {
		fileOut << setprecision(2) << fixed;
		fileOut << right  << setw(10) << month << setw(20) << creditCardBalance << setw(20) << monthlyIntrest << setw(20) << minimumPayment << setw(20) << totalIntrestPaid << endl;
	}
}

/*
Output:
Balance Owing: $624.00
APR as % 24
Percent for minimum payment as % 4
--------------------------------------------------------------------------------
	 Month             Balance     Monthly Intrest     Minimum Payment       Total Intrest
		 1              611.02               12.48               25.46               12.48
		 2              598.31               12.22               24.93               24.70
		 3              585.87               11.97               24.41               36.67
		 4              573.68               11.72               23.90               48.38
		 5              561.75               11.47               23.41               59.86
		 6              550.06               11.23               22.92               71.09
		 7              538.62               11.00               22.44               82.09
		 8              527.42               10.77               21.98               92.87
		 9              516.45               10.55               21.52              103.41
		10              505.71               10.33               21.07              113.74
		11              495.19               10.11               20.63              123.86
		12              484.89                9.90               20.20              133.76
		13              474.80                9.70               19.78              143.46
		14              464.93                9.50               19.37              152.96
		15              455.26                9.30               18.97              162.25
		16              445.79                9.11               18.57              171.36
		17              436.51                8.92               18.19              180.27
		18              427.43                8.73               17.81              189.01
		19              418.54                8.55               17.44              197.55
		20              409.84                8.37               17.08              205.92
		21              401.31                8.20               16.72              214.12
		22              392.97                8.03               16.37              222.15
		23              384.79                7.86               16.03              230.01
		24              376.79                7.70               15.70              237.70
		25              368.95                7.54               15.37              245.24
		26              361.28                7.38               15.05              252.62
		27              353.50                7.23               15.00              259.84
		28              345.57                7.07               15.00              266.91
		29              337.48                6.91               15.00              273.82
		30              329.23                6.75               15.00              280.57
		31              320.82                6.58               15.00              287.16
		32              312.24                6.42               15.00              293.58
		33              303.48                6.24               15.00              299.82
		34              294.55                6.07               15.00              305.89
		35              285.44                5.89               15.00              311.78
		36              276.15                5.71               15.00              317.49
		37              266.67                5.52               15.00              323.01
		38              257.01                5.33               15.00              328.35
		39              247.15                5.14               15.00              333.49
		40              237.09                4.94               15.00              338.43
		41              226.83                4.74               15.00              343.17
		42              216.37                4.54               15.00              347.71
		43              205.69                4.33               15.00              352.03
		44              194.81                4.11               15.00              356.15
		45              183.70                3.90               15.00              360.04
		46              172.38                3.67               15.00              363.72
		47              160.83                3.45               15.00              367.17
		48              149.04                3.22               15.00              370.38
		49              137.02                2.98               15.00              373.36
		50              124.76                2.74               15.00              376.10
		51              112.26                2.50               15.00              378.60
		52               99.51                2.25               15.00              380.84
		53               86.50                1.99               15.00              382.84
		54               73.23                1.73               15.00              384.56
		55               59.69                1.46               15.00              386.03
		56               45.88                1.19               15.00              387.22
		57               31.80                0.92               15.00              388.14
		58               17.44                0.64               15.00              388.78
		59                2.79                0.35               15.00              389.13
		60                0.00                0.06                2.84              389.18

*/