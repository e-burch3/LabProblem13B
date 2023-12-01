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
void printCalendar(int month, int year);


const string MONTHS[] = { "January", "February", "March", "April", "May", "June", "July", "August",
							"September", "October", "November", "December" };

const string DAY_NAME[] = { "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
//					   Sa Fr Th We Tu Mo Su
//					   00 01 02 03 04 05 06 07 08 09 10 11 12
//					   01234567890123456789012345678901234567
char calendar[][40] ={"                   1  2  3  4  5  6  7 ",
					  " 2  3  4  5  6  7  8  9 10 11 12 13 14 ",
					  " 9 10 11 12 13 14 15 16 17 18 19 20 21 ",
					  "16 17 18 19 20 21 22 23 24 25 26 27 28 ",
					  "23 24 25 26 27 28 29 30 31             ",
					  "30 31                                  " };

string week[] = { "Su", "Mo", "Tu", "We", "Th", "Fr", "Sa" };

int main(void) {
	int year;
	int month;
	int count = 0;
	
	
	while (true) {
		cout << "Enter a month and year or Q to quit: ";
		cin >> month;
		
		cin >> year;
		if (cin.fail())
			break;

		printCalendar(month, year);
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

void printCalendar(int month, int year) {
	// char lines[6][40];
	int firstDay = dayOfWeek(month, 1, year);
	int offset;
	int lastPoint;
	int lastDay = daysInMonth(month, year);
	char lastDayFirst = (lastDay / 10) + 48;
	char lastDaySecond = (lastDay % 10) + 48;
	char last;

	firstDay *= 3;

	
	for (int j = 0; j <= 6; j++) {
		cout << endl;
		if (j >= 0 && j <= 3) {
			for (int i = firstDay-3; i <= lastPoint; i++) {
				if (i == 39) 
					break;
				//lines[j][i - firstDay] = calendar[j][i];
				//cout << lines[j][i - firstDay];
				cout << calendar[j][i];
			}
		}
		else if (j == 4) {
			for (int i = firstDay-3; i <= lastPoint; i++) {
				if (i == 39)
					break;
				//lines[j][i - firstDay] = calendar[j][i];
				//cout << lines[j][i - firstDay];
				cout << calendar[j][i];
				if (calendar[j][i] == lastDaySecond && last == lastDayFirst && last != ' ')
					break;
				last = calendar[j][i];
			}
		}
		else if (j == 5 && firstDay <= 16) {
			for (int i = firstDay-3; i <= lastPoint; i++) {
				if (i == 39)
					break;
				//lines[j][i - firstDay] = calendar[j][i];
				//cout << lines[j][i - firstDay];
				cout << calendar[j][i];
				if (calendar[j][i] == lastDaySecond && last == lastDayFirst && last != ' ')
					break;
				last = calendar[j][i];
			}
		}
	}
}

