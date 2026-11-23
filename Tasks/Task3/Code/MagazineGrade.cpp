#include <iostream>
#include <string>

using namespace std;

double averageGrade(const int grades[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += grades[i];
	}
	return (double)sum / n;
}

int minGrade(const int grades[], int n)
{
	int min = 6;
	for (int i = 0; i < n; i++)
	{
		if (grades[i] < min)
			min = grades[i];
	}
	return min;
}

int maxGrade(const int grades[], int n)
{
	int max = 1;
	for (int i = 0; i < n; i++)
	{
		if (grades[i] > max)
		max = grades[i];
	}
	return max;
}

int counterGradesTwo(const int grades[], int n)
{
	int counter = 0;
	for (int i = 0; i < n; i++)
	{
		if (grades[i] == 2)
			counter++;
	}
	return counter;
}

int main() 
{
	int number;
	string studentName;
	cout << "Введи свой номер из журнала\n" << endl;
	cin >> number;
	if (number <= 0)
	{
		cout << "Твой номер должен быть из списка\n" << endl;
		return 1;
	}
	int N = 5 + (number % 5);
	cout << "Введи имя студента" << endl;
	cin >> studentName;
	cout << "Введи массив из " << N << " оценок\n" << endl;
	int grades[10];
	for (int i = 0; i < N; i++)
	{
		cin >> grades[i];
		while (grades[i] < 2 || grades[i] > 5)
		{
			cout << "Введи оценку от [2 - 5]\n" << endl;
			cin >> grades[i];
		}
	}

	cout << "Журнал оценок студента " << studentName << " под номером: " << number << endl;
	cout << "\nУ студента средний балл: " << averageGrade(grades, N) << endl;
	cout << "\nУ студента минимальная оценка: " << minGrade(grades, N) << endl;
	cout << "\nУ студента максимальная оценка: " << maxGrade(grades, N) << endl;
	int dolg = counterGradesTwo(grades, N);
	if (dolg == 0)
		cout << "\nСтудент молодец, не имеет пересдач\n" << endl;
	else 
		cout << "\nСтудентик то, должничёк, вон сколько пересдач имеет: " << dolg << endl;
}
