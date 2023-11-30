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
int daysInMonth(int month, int year);

const string MONTHS[] = { "January", "February", "March", "April", "May", "June", "July", "August",
							"September", "October", "November", "December" };
int main(void) {
	int year;
	int month;
	while (true) {
		cout << "Enter a month or Q to quit: ";
		cin >> month;
		cin >> year;
		if (cin.fail())
			break;
		cout << MONTHS[month - 1] << ' ' << year << " has " << daysInMonth(month, year) << " days.\n";
	}
}

bool isLeapYear(int year) {
	if (year % 4 || year % 400)
		return false;
	else
		return true;
}

int daysInMonth(int month, int year) {
	switch (month) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
		break;
	case 2:
		if (isLeapYear(year))
			return 29;
		else
			return 28;
		break;
	default:
		return NULL;
		break;
	}
}