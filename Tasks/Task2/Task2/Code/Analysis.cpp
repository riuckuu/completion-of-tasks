#include <iostream>
using namespace std;


/*
По условию программа должна анализировать числа, а не цифры.
Убрите пожалуйста ограничение диапазона 0–9.
Пожалуйста продемонстрируйте работу программы с отрицательными, положительными
*/


int main()
{
	cout << "Введи будущее количество чисел\n" << endl;
	int countDigits;
	cin >> countDigits;

	if (countDigits < 0)
	{
		cout << "Количество чисел не может быть отрицательным\n" << endl;
		return 0;
	}

	if (countDigits == 0)
	{
		cout << "Количество чисел не может быть нулевым\n" << endl;
		return 0;
	}
	cout << "Введи " << countDigits << " чисел\n" << endl;
	double sum, avg;
	int minValue, maxValue;
	sum = 0.0;
	minValue = 0;
	maxValue = 0;
	for (int i = 0; i < countDigits; i++)
	{
		int digit;
		cin >> digit;
		if (i == 0)
		{
			minValue = digit;
			maxValue = digit;
		}
		sum += digit;
		if (digit < minValue)
			minValue = digit;
		if (digit > maxValue)
			maxValue = digit;
	}
	avg = sum / countDigits;

	cout << "Анализ завершён\nРезульат:\nСумма: " << sum << "\nСреднее: " << avg
		<< "\nМинимальное: " << minValue << "\nМаксимальное: "
		<< maxValue << endl;
}