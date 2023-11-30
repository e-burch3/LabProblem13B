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
int dayOfWeek(int month, int day, int year);

const string MONTHS[] = { "January", "February", "March", "April", "May", "June", "July", "August",
							"September", "October", "November", "December" };

const string DAY_NAME[] = { "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };


int main(void) {
	int year;
	int month;
	int day;
	while (true) {
		cout << "Enter a date or Q to quit: ";
		cin >> month;
		cin >> day;
		cin >> year;
		if (cin.fail())
			break;
		cout << DAY_NAME[dayOfWeek(month, day, year)] << ", " << MONTHS[month - 1] << " " << day << ", " << year << endl;
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

int dayOfWeek(int month, int day, int year) {
	if (month <= 2) {
		year--;
		month += 12;
	}

	int dayOfTheWeek = (day + (((month + 1) * 26) / 10) + year + (year / 4) + 6 * (year / 100) + (year / 400));

	return dayOfTheWeek % 7;

}