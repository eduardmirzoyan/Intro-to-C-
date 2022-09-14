// File Name: Write_file_simple_demo.cpp
//


#include <iostream>

using namespace std;

int main()
{
	bool input_started;
	double result = 0;
	double input = 0;
	do {
		input_started = true;
		cout << "Enter a new input number, type any non-numeric key to end data input: ";
		cin >> input;
		result += input * input;
	} while (!cin.fail());
	cout << "The sum of the squares of your inputs is: " << result;
	
}

