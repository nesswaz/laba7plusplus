#ifdef _WIN64
#include <windows.h>
#endif
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <string>
#include "laura7.h"
#include <algorithm>


int main() {
    #ifdef _WIN64
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    #endif
    using namespace std;
    int choice; 
    do {
        cout << "1. Задание Sort7 " << endl;
        cout << "2. Задание ExamTaskC15" << endl;
        cout << "3. Задание Five12" << endl;
        cout << "999. Выход из программы" << endl;
        cin >> choice;
        switch (choice) {
            case 1: {
                task1();
                break;
            }
            case 2: {
                task2();
                break;
            }
            case 3: {
                sortStudents();
                break;
            }
            case 999: {
                cout << "Выход из программы" <<endl;
                break;
            }
            default:
            cout << "Введены неверные данные" << endl;
            break;
        }
    }
    while (choice != 999);
    return 0;
}