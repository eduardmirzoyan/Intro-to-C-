// This program uses a selection sort to arrange an array of integers in
// ascending order

// Names: Eduard Mirzoyan
//			Jessica Dinh

#include <iostream>
using namespace std;

// function prototypes

void selectionSortArray(int[], int);
void displayArray(int[], int);
const int SIZE = 5;

int main()
{
	int values[SIZE] = { 9,2,0,11,5 };

	cout << "The values before the selection sort is performed are:" << endl;
	displayArray(values, SIZE);

	selectionSortArray(values, SIZE);
	cout << "The values after the selection sort is performed are:" << endl;
	displayArray(values, SIZE);

	return 0;
}

//******************************************************************
//                      displayArray
//
// task:	  	  to print the array
// data in:       the array to be printed, the array size
// data out:      none
//
//******************************************************************

void displayArray(int array[], int elems)    // function heading
{							   // Displays array
	for (int count = 0; count < elems; count++)
		cout << array[count] << "  ";
	cout << endl;
}

//******************************************************************
//                      selectionSortArray
//
// task:	  to sort values of an array in ascending order
// data in:       the array, the array size
// data out:      the sorted array
//
//******************************************************************


void selectionSortArray(int array[], int elems)
{
	int seek;      //array position currently being put in order
	int minCount;  //location of smallest value found
	int minValue;  //holds the smallest value found

	for (seek = 0; seek < (elems - 1); seek++)  // outer loop performs the swap
										   // and then increments seek
	{
		// code for swap and seek increment
		minCount = seek;
		minValue = array[seek];

		for (int index = seek + 1; index < elems; index++)
		{
			if (array[index] < minValue)
			{
				minValue = array[index];
				minCount = index;
			}
		}

		// Write two statements exchange the value of the
		// element currently needing the smallest value found in the
		// pass(indicated by seek) with the smallest value found
		// (located in minValue)

		array[minCount] = array[seek];
		array[seek] = minValue;

	}
}