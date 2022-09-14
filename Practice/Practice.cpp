// File Name: Write_file_simple_demo.cpp
//
// This program uses the procedures laid out in Canvas to 
// write simple text string and variable to a file

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ofstream file_out;
	/*
	   // For example, this is my local directory in Windows
	   const string pathname = "C:\\Users\\Vic\\Documents\\Visual Studio 2017\\All Solutions\\All Demos\\file IO Demos\\";

	   // If you have a Mac, it would be something like this, say you are using the memory stick:
	   const string pathname = "/Volumes/Lexar/c_plusplus/";

	   // concatenate the path with the name to give the fullname:
	   string fullname = pathname + "out_data.txt";
	*/

	// here we just make it simple to use the current project directory, i.e. no pathname provided:
	string fullname = "out_data2.txt";
	file_out.open(fullname.c_str());

	double pi = 3.14159;
	string description = "is the output value.";

	if (!file_out.fail())
	{
		file_out << setw(32) << left << setfill('.') << "May I have your attention"
			<< setw(10) << right << setfill(' ') << setprecision(4) << fixed << pi
			<< setw(22) << description;
		file_out.close(); // close the file after finished writing to it
		cout << "Writing to file completed!" << endl;
	}
	else
		cout << "File open failed. Program abort." << endl;

	return 0;
}
