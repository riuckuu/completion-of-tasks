#include <iostream>
#include "Date.h"

using namespace std;

int main() {
    int choice;
    while (true) {
        cout << "\n1 - калькулятор возраста\n";
        cout << "2 - калькулятор\n";
        cout << "3 - выход\n";


        if (cin >> choice) {
            if (choice == 1) calculateAge();
            else if (choice == 2) calculator();
            else if (choice == 3) break;
            else cout << "Действие не выбрно\n";
        }
        else {
            cout << "Ошибка\n";
        }
    }
    return 0;
}