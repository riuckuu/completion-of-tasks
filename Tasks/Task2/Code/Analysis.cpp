#include <iostream>
using namespace std;

int main()
{
	cout << "Введи будущее количество чисел\n" << endl;
	int countDigits;
	cin >> countDigits;

	if (countDigits < 0)
	{
		cout << "Количество цифр не может быть отрицательным\n" << endl;
		return 0;
	}

	if (countDigits == 0)
	{
		cout << "Количество цифр не может быть нулевым\n" << endl;
		return 0;
	}
	cout << "Введи " << countDigits << " цифр\n" << endl;
	double sum, avg;
	int minValue, maxValue;
	sum = 0.0;
	minValue = 10;
	maxValue =  -1;
	for (int i = 0; i < countDigits; i++)
	{
		int digit;
		cin >> digit;
		if (digit < 0 || digit >= 10)
		{
			cout << "Цифра должна быть от [0 - 9]\n" << endl;
			i--;
		}
		else
		{
			sum += digit;
			if (digit < minValue)
				minValue = digit;
			if (digit > maxValue)
				maxValue = digit;
		}

	}
	avg = sum / countDigits;

	cout << "Анализ завершён\nРезульат:\nСумма: " << sum << "\nСреднее: " << avg 
												  << "\nМинимальное: " << minValue << "\nМаксимальное: " 
												  << maxValue << endl;
}