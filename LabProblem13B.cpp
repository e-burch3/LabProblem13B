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
#include <fstream>

using namespace std;

//prototypes
bool isLeapYear(int year);
int daysInMonth(int month, int year);
int dayOfWeek(int month, int day, int year);
void printCalendar(int month, int year);
int monthFinder(string month);
void output(string filename, int month, int year);

const string MONTHS[] = {"January", "February", "March", "April", "May", "June", "July", "August",
							"September", "October", "November", "December" };

const string DAY_NAME[] = { "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
//					   Sa Fr Th We Tu Mo Su
//					   00 01 02 03 04 05 06 07 08 09 10 11 12
//					   01234567890123456789012345678901234567
string calendar[] =  {"                   1  2  3  4  5  6  7 ",
					  " 2  3  4  5  6  7  8  9 10 11 12 13 14 ",
					  " 9 10 11 12 13 14 15 16 17 18 19 20 21 ",
					  "16 17 18 19 20 21 22 23 24 25 26 27 28 ",
					  "23 24 25 26 27 28 29 30 31             ",
					  "30 31                                  " };

string week[] = { "Su", "Mo", "Tu", "We", "Th", "Fr", "Sa" };

string line1, line2, line3, line4, line5, line6;

string file;

int main(void) {
	int year;
	string month;
	int months;
	
	while (true) {
		cout << "Enter a month and year or Q to quit: ";
		cin >> month;
		cin >> year;
		if (month == "Q" || cin.fail())
			break;
		cout << "Enter file to output to: ";
		cin >> file;
		months = monthFinder(month);

		printCalendar(months, year);
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
int monthFinder(string month) {
	
	if (month[0] >= 97 && month[0] <= 122) {
		month[0] = month[0] - 32;
	}

	for (int i = 0; i < 12; i++)
		for(int j = 0; j < 10; j++)
			if (month == MONTHS[i])
				return i + 1;
	return 0;
}

void output(string filename, int month, int year) {
	ofstream outFile;
	outFile.open(filename);
	string str = MONTHS[month - 1];

	if (outFile.fail()) {
		printf("Error opening File. ");
	}
	else {
		for (int i = 21; i < line1.length(); i++) {
			line1[i] = ' ';
		}
		for (int i = 21; i < line2.length(); i++) {
			line2[i] = ' ';
		}
		for (int i = 21; i < line3.length(); i++) {
			line3[i] = ' ';
		}
		for (int i = 21; i < line4.length(); i++) {
			line4[i] = ' ';
		}
		for (int i = 21; i < line5.length(); i++) {
			line5[i] = ' ';
		}
		for (int i = 21; i < line6.length(); i++) {
			line6[i] = ' ';
		}
		outFile << str << " " << year << endl;
		outFile << "Su Mo Tu We Th Fr Sa\n";
		outFile << line1 << endl;
		outFile << line2 << endl;
		outFile << line3 << endl;
		outFile << line4 << endl;
		outFile << line5 << endl;
		outFile << line6 << endl;
	}
}

void printCalendar(int month, int year) {
	line1 = "";
	line2 = "";
	line3 = "";
	line4 = "";
	line5 = "";
	line6 = "";

	string str = MONTHS[month - 1];
	int firstDay = dayOfWeek(month, 1, year);
	int offset = 0;
	int lastPoint = 0;
	int lastDay = daysInMonth(month, year);
	char lastDayFirst = (lastDay / 10) + 48;
	char lastDaySecond = (lastDay % 10) + 48;
	char last = 0;
	char curr = 0;
	
	switch (firstDay) {
	case 0: // SATURDAY
		firstDay = 0;
		break;
	case 1://SUNDAY
		firstDay = 18;
		break;
	case 2: //MONDAY
		firstDay = 15;
		break;
	case 3: // TUESDAY
		firstDay = 12;
		break;
	case 4: // WEDNESDAY
		firstDay = 9;
		break;
	case 5: //THURSDAY
		firstDay = 6;
		break;
	case 6: // FRIDAY
		firstDay = 3;
		break;
	}
	
	
	
	lastPoint = 38;

	printf("%s", str.c_str());

	printf(" %i", year);
	printf("\n");
	printf("Su Mo Tu We Th Fr Sa\n");
	
	for (int j = 0; j <= 6; j++) {
		if (j == 0) {
			for (int i = firstDay; i <= lastPoint; i++) {
				line1 += calendar[j][i];
			}
		}
		else if (j == 1) {
			for (int i = firstDay; i <= lastPoint; i++) {
				line2 += calendar[j][i];
			}
		}
		else if (j == 2) {
			for (int i = firstDay; i <= lastPoint; i++) {
				line3 += calendar[j][i];
			}
		}
		else if (j == 3) {
			for (int i = firstDay ; i <= lastPoint; i++) {
				line4 += calendar[j][i];
			}
		}
		else if (j == 4) {
			for (int i = firstDay ; i <= lastPoint; i++) {
				line5 += calendar[j][i];
				if (calendar[j][i] == lastDaySecond && last == lastDayFirst && last != ' ')
					break;
				last = calendar[j][i];
			}
		}
		else if (j == 5 && firstDay <= 16) {
			for (int i = firstDay; i <= lastPoint; i++) {
				line6 += calendar[j][i];
				if (calendar[j][i] == lastDaySecond && last == lastDayFirst && last != ' ')
					break;
				last = calendar[j][i];
			}
		}
	}
	
	
	printf("%-.21s\n", line1.c_str());
	printf("%-.21s\n", line2.c_str());
	printf("%-.21s\n", line3.c_str());
	printf("%-.21s\n", line4.c_str());
	printf("%-.21s\n", line5.c_str());
	printf("%-.21s\n", line6.c_str());

	output(file, month, year);
}

