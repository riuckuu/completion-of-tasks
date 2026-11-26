#define _CRT_SECURE_NO_WARNINGS

#include "Date.h"
#include <ctime>
#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

bool isLeapYear(int year)
{//visokosnij
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year)
{// dni v month
	int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && isLeapYear(year))
		return 29;
	int currentMonth = month - 1;
	return days[currentMonth];
}

bool valid(int day, int month, int year)
{//valid date
	return ((month < 1 || month > 12) || day < 1 || day > daysInMonth(month, year))
		|| (year < 1900 || year > 2100) ? 0 : 1;
}

int daysFromStart(int day, int month, int year)
{//raznitsa
	int total = 0;
	for (int i = 1; i < year; i++)
		total += isLeapYear(i) ? 366 : 365;
	for (int k = 1; k < month; k++)
		total += daysInMonth(k, year);
	total += day;
	return total;
}

void calculateAge()
{//vvod: dd.mm.yy
	Date birthday;
	char symbol1, symbol2;
	if (cin >> birthday.day && (symbol1 = cin.get()) == '.' &&
		cin >> birthday.month && (symbol2 = cin.get()) == '.' &&
		cin >> birthday.year && cin.get() == '\n')
	{
		if (valid(birthday.day, birthday.month, birthday.year))
		{
			time_t currentTime = time(nullptr);
			tm* myTime = localtime(&currentTime);
			Date today;
			today.day = myTime->tm_mday;
			today.month = myTime->tm_mon + 1;
			today.year = myTime->tm_year + 1900;
			if (daysFromStart(birthday.day, birthday.month, birthday.year) >
				daysFromStart(today.day, today.month, today.year))
			{
				cout << "Др некоректное, т.к в будущем\n";
			}
			else
			{
				int age = today.year - birthday.year;

				if (today.month < birthday.month || (today.month == birthday.month
					&& today.day < birthday.day))
				{
					age--;
				}
				int totalDays = daysFromStart(today.day, today.month, today.year) -
					daysFromStart(birthday.day, birthday.month, birthday.year);
				cout << age << " лет\n";
				cout << totalDays << " дней\n";
			}
		}
		else
			cout << "Некоректная дата\n";
	}
	else
	{
		cout << "Ввод: dd.mm.yyyy\n";
		cin.clear();
		cin.ignore(10000, '\n');
	}
}


void calculator()
{
	double num1, num2;
	char operation;
	if (cin >> num1 >> operation >> num2)
	{
		while (cin.peek() == '\t' || cin.peek() == ' ')
			cin.get();
		if (cin.peek() != EOF && cin.peek() != '\n')
		{
			cout << "Только 2 числа" << endl;
			cin.clear();
			cin.clear(10000, '\n');
			return;
		}

		double result = 0;
		bool is = true;

		switch (operation)
		{
		case '+': result = num1 + num2; break;
		case '-': result = num1 - num2; break;
		case '*': result = num1 * num2; break;
		case '/':
			if (num2 == 0)
			{
				cout << "На ноль делить нельзя\n";
				is = false;
			}
			else result = num1 / num2;
			break;
		case '^': 
			result = pow(num1, num2);
			if (isnan(result) || isinf(result))
			{
				cout << "Нельзя так возводить" << endl;
				is = false;
			}
			break;
		case '%':
			if (num2 == 0)
			{
				cout << "На ноль делить нельзя\n";
				is = false;
			}
			else result = fmod(num1, num2);
			break;
		default:
			cout << "Нет такой операции\n";
			is = false;
		}

		if (is)
			cout << "Ответ: " << result << "\n";
	}
	else
		{
			cout << "Ошибка ввода\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		
}
