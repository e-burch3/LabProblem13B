/*
*	File:			LabProblem13B.cpp
*	Author:			Ethan Burch
* 
*	Date:			11/30/2023
*	Description:	prints out a calender
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;


//prototypes
bool isLeapYear(int year);


int main(void) {
	int year;
	while (true) {
		cout << "Enter a year or Q to quit: ";
		cin >> year;
		if (cin.fail())
			break;
		if (isLeapYear(year))
			cout << year << " is a leap year.\n";
		else
			cout << year << " is not a leap year.\n";
	}
}

bool isLeapYear(int year) {
	if (year % 4 && year % 100)
		return false;
	else
		return true;
}