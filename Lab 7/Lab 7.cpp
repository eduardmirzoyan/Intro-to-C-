/*****************************************************************************/
//  Filename:      Lab7.cpp
//
//  Author:        Eduard Mirzoyan
//
//  Date:          2019.08.08
//
//  Modifications: Eduard Mirzoyan – 2019.08.08
//
//
//  Description:   This program gathers heartrate information from a user
//					and calculates estimated values about thier health such
//					as thier exercised days and weekly average heartrate.
//					The program outputs these results to a file with catagories
//					for easy viewing.
//					
//				   
//
/*****************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
// Common values made into definitions
#define MAX_HEARTRATE 220
#define ARRAY_SIZE 10
#define SPACING 20

using namespace std;

// Function Prototypes
void calculateMeasuredHeartrateRatio(double ratioOfMeasuredHeartrate[], int estimatedMaxHeartrate[], int measuredMaxHeartrate, int subjectCount);
void inputAndCalculate(istream& fileIn, int id[], double weeklyAvgHeartrate[], int excerciseDays[], int estimatedMaxHeartrate[], double ratioOfMeasuredHeartrate[], double ratioOfCommutingHeartrate[]);
void sort(int id[], double weeklyAvgHeartrate[], int excerciseDays[], int estimatedMaxHeartrate[], double ratioOfMeasuredHeartrate[], double ratioOfCommutingHeartrate[], int size);
void outputHeader(ostream& fileOut);
void outputResults(ostream& fileOut, int id[], double weeklyAvgHeartrate[], int excercise[], int estimatedMaxHeartrate[], double ratioOfMeasuredHeartrate[], double ratioOfCommutingHeartrate[]);

int main()
{
	// Output and input variables along with their names
	ifstream fileIn;
	ofstream fileOut;
	string inputPath = "HR.txt";
	string outputPath = "Output.txt";

	int id[ARRAY_SIZE] = {};
	double weeklyAvgHeartrate[ARRAY_SIZE] = {};
	int excerciseDays[ARRAY_SIZE] = {};
	int estimatedMaxHeartrate[ARRAY_SIZE] = {};
	double ratioOfMeasuredHeartrate[ARRAY_SIZE] = {};
	double ratioOfCommutingHeartrate[ARRAY_SIZE] = {};

	// Gathers values from text file and calculates information
	fileIn.open(inputPath);
	inputAndCalculate(fileIn, id, weeklyAvgHeartrate, excerciseDays, estimatedMaxHeartrate, ratioOfMeasuredHeartrate, ratioOfCommutingHeartrate);
	fileIn.close();

	// Sorts all the arrays at once from smallest id number to largest
	sort(id, weeklyAvgHeartrate, excerciseDays, estimatedMaxHeartrate, ratioOfMeasuredHeartrate, ratioOfCommutingHeartrate, ARRAY_SIZE);

	// Outputs results to textfile with header outputed seperately
	fileOut.open(outputPath.c_str());
	outputHeader(fileOut);
	outputResults(fileOut, id, weeklyAvgHeartrate, excerciseDays, estimatedMaxHeartrate, ratioOfMeasuredHeartrate, ratioOfCommutingHeartrate);
	fileOut.close();

	// Gives verbal confirmation of completion
	cout << endl << "Output Complete" << endl;
}

void inputAndCalculate(istream& fileIn, int id[], double weeklyAvgHeartrate[], int excerciseDays[], int estimatedMaxHeartrate[], double ratioOfMeasuredHeartrate[], double ratioOfCommutingHeartrate[])
{
	if (!fileIn.fail()) {
		// Counter to show which subject's data is being worked on
		int subjectCount = 0;

		// Data for first line
		int patientID;
		int measuredMaxHeartrate;
		int age;

		// Data for lines 2-6
		double avgCommutingHeartrate;
		double maxCommutingHeartrate;
		double excerciseHeartrate;

		// Counters for patient's data
		double weeklyAvgCommutingHeartrate = 0;
		double validCommutingDays = 0;
		int excercisedDays = 0;
		double largestCommutingHeartrate = 0;

		// Loops through each "block" of data and calculates related values
		for (int i = 0; i < 6; i++) {
			if (i == 0) {
				if (fileIn >> patientID >> measuredMaxHeartrate >> age) {
					id[subjectCount] = patientID;
					estimatedMaxHeartrate[subjectCount] = MAX_HEARTRATE - age;
					calculateMeasuredHeartrateRatio(ratioOfMeasuredHeartrate, estimatedMaxHeartrate, measuredMaxHeartrate, subjectCount);
					subjectCount++;
				}
				else
					break;
			}
			else {
				if (fileIn >> avgCommutingHeartrate >> maxCommutingHeartrate >> excerciseHeartrate) {
					if (avgCommutingHeartrate >= 0) {
						weeklyAvgCommutingHeartrate += avgCommutingHeartrate;
						validCommutingDays++;
					}
					if (excerciseHeartrate > 0) {
						excercisedDays++;
					}
					if (maxCommutingHeartrate > 0 && maxCommutingHeartrate > largestCommutingHeartrate) {
						largestCommutingHeartrate = maxCommutingHeartrate;
					}
				}
				else
					break;
			}

			if (i == 5) {
				weeklyAvgHeartrate[subjectCount - 1] = weeklyAvgCommutingHeartrate / validCommutingDays;
				excerciseDays[subjectCount - 1] = excercisedDays;
				ratioOfCommutingHeartrate[subjectCount - 1] = largestCommutingHeartrate / measuredMaxHeartrate * 100;

				// Reset counters for next block of data
				weeklyAvgCommutingHeartrate = 0;
				validCommutingDays = 0;
				excercisedDays = 0;
				largestCommutingHeartrate = 0;
				i = -1;
			}
		}
	}
}

// Outpus header and catagory labels
void outputHeader(ostream& fileOut)
{
	if (!fileOut.fail()) {
		fileOut << setprecision(1) << fixed;
		fileOut << setw(30) << "" << "COMMUTING AND EXERCISE HEART RATE SUMMARY" << endl << endl;
		fileOut << right << setw(10) << "Subject" << setw(SPACING) << "Avg Weekly" << setw(SPACING) << "Days" << setw(SPACING) << "Estimated Maximum" << setw(SPACING) << "Ratio of Measured" << setw(SPACING) << "Ratio of Commuting" << endl;
		fileOut << right << setw(10) << "Number" << setw(SPACING) << "Heartrate" << setw(SPACING) << "Exercised" << setw(SPACING) << "Heartrate" << setw(SPACING) << "Heartrate (%)" << setw(SPACING) << "Heartrate (%)" << endl;
	}
	else cout << "Failed to output header...";
}

// Outputs values gathered in the arrays above
void outputResults(ostream& fileOut, int id[], double weeklyAvgHeartrate[], int excercise[], int estimatedMaxHeartrate[], double ratioOfMeasuredHeartrate[], double ratioOfCommutingHeartrate[])
{
	if (!fileOut.fail()) {
		for (int i = 0; i < ARRAY_SIZE; i++) {
			fileOut << right << setw(10) << id[i] << setw(SPACING) << weeklyAvgHeartrate[i] << setw(SPACING) << excercise[i] << setw(SPACING) << estimatedMaxHeartrate[i] << setw(SPACING) << ratioOfMeasuredHeartrate[i] << setw(SPACING) << ratioOfCommutingHeartrate[i] << endl;
		}
	}
	else cout << "Failed to output results...";
}

// This function takes in all the arrays and sorts them based on the first one from smallest to largest
void sort(int id[], double weeklyAvgHeartrate[], int excerciseDays[], int estimatedMaxHeartrate[], double ratioOfMeasuredHeartrate[], double ratioOfCommutingHeartrate[], int size)
{
	int startValue, minIndex, minValue;
	double tempDoubleValue;
	int tempIntValue;

	for (startValue = 0; startValue < (size - 1); startValue++)
	{
		minIndex = startValue;
		minValue = id[startValue];
		for (int index = startValue + 1; index < size; index++)
		{
			if (id[index] < minValue)
			{
				minValue = id[index];

				minIndex = index;

			}
		}
		id[minIndex] = id[startValue];
		id[startValue] = minValue;

		tempDoubleValue = weeklyAvgHeartrate[minIndex];
		weeklyAvgHeartrate[minIndex] = weeklyAvgHeartrate[startValue];
		weeklyAvgHeartrate[startValue] = tempDoubleValue;

		tempIntValue = excerciseDays[minIndex];
		excerciseDays[minIndex] = excerciseDays[startValue];
		excerciseDays[startValue] = tempIntValue;

		tempIntValue = estimatedMaxHeartrate[minIndex];
		estimatedMaxHeartrate[minIndex] = estimatedMaxHeartrate[startValue];
		estimatedMaxHeartrate[startValue] = tempIntValue;

		tempDoubleValue = ratioOfMeasuredHeartrate[minIndex];
		ratioOfMeasuredHeartrate[minIndex] = ratioOfMeasuredHeartrate[startValue];
		ratioOfMeasuredHeartrate[startValue] = tempDoubleValue;

		tempDoubleValue = ratioOfCommutingHeartrate[minIndex];
		ratioOfCommutingHeartrate[minIndex] = ratioOfCommutingHeartrate[startValue];
		ratioOfCommutingHeartrate[startValue] = tempDoubleValue;
	}
}

// Solely calcualtes the measured heartrate ratio, no return
void calculateMeasuredHeartrateRatio(double ratioOfMeasuredHeartrate[], int estimatedMaxHeartrate[], int measuredMaxHeartrate, int subjectCount)
{
	ratioOfMeasuredHeartrate[subjectCount] = 1.0 * estimatedMaxHeartrate[subjectCount] / measuredMaxHeartrate * 100;
}