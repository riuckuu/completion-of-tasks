#pragma once

struct Date
{
	int day;
	int month;
	int year;
};

bool isLeapYear(int year);
int daysInMonth(int month, int year);
bool valid(int day, int month, int year);
int daysFromStart(int day, int month, int year);
void calculateAge();
void calculator();