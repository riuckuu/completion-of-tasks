#include <iostream>
#include "Date.h"

using namespace std;

/*
Добавить обработку ошибок cin, чтобы программа не зацикливалась при некорректном вводе.
Проверить работу программы при вводе букв, некорректных дат и математических выражений.
*/


int main() {
    int choice;
    while (true) {
        cout << "\n1 - калькулятор возраста\n";
        cout << "2 - калькулятор\n";
        cout << "3 - выход\n";


        if (cin >> choice) {
            while (cin.peek() == '\t' || cin.peek() == ' ')
                cin.get();
            if (cin.peek() != EOF && cin.peek() != '\n')
            {
                cout << "Выбери пункты 1, 2 или 3" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }

            if (choice == 1) calculateAge();
            else if (choice == 2) calculator();
            else if (choice == 3) break;
            else cout << "Действие не выбрно\n";
        }
        else 
            {
                cout << "Ошибка\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
    }
    return 0;
}
