#include "laura7.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>

void sort_v(std::vector<int>& a){
    using namespace std;
    ofstream file("b.txt");
    int k, m;
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        k = i;
        m = a[i];
        for (int j = i + 1; j < n; j++) {
            if (a[j] < m) {
                k = j;
                m = a[k];
            }
        }
        if (k != i) {
            a[k] = a[i]; 
            a[i] = m;
        }
        for (int t = 0; t < n; t++) {
            if (t == i + 1) {
                cout << "| ";
                file << "| ";
            }
            cout << a[t] << " ";
            file << a[t] << " ";
        }
        cout << endl;
        file << endl;
    }
    file.close();
}


void task1() {
    using namespace std;
    cout << "Введите количество элементов: ";
    int n;
    cin >> n;
    if (n < 0) {
        cout << "Вы ввели неверное значение\n";
        return;
    }
    vector<int> a(n);
    cout << "Введите элементы:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort_v(a);
    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;
}

void task2() {
    using namespace std;
    int k;
    cout << "Введите код одного из клиентов (К), (10-99) - "; cin >> k;
    int n;
    if (k < 10 || k > 99) {
        cout << "Вы ввели неверное значение" << endl;
        return;
    }
    cout << "Введите количество клиентов - "; cin >> n;
    if (n == 0) {
        cout << "Ошибка. 0 клиентов." << endl;
        return;
    }
    user f;
    int c = 0;
    int maxe[2011] = {0};
    int best[2011] = {0};
    for (int i = 0; i < n; i++) {
        cout << "Клиент " << i + 1 << endl;
        cout << "Введите код клиента (10-99) - "; cin >> f.code;
        cout << "Введите продолжительность занятий (в часах), (1-30) - "; cin >> f.hours;
        cout << "Введите год (2000 - 2010) - "; cin >> f.year;
        cout << "Введите номер месяца (1 - 12) - "; cin >> f.month;
        if (f.year < 2000 || f.year > 2010 ||  f.code < 10 || f.code > 99 || f.hours < 1 || f.hours > 30 || f.month < 1 || f.month > 12) {
            cout << "Вы ввели неверные данные " << endl;
            return;
        }
        if (f.code == k) {
            c++;
            int y = f.year;
            if (maxe[y] == 0) {
                maxe[y] = f.hours; best[y] = f.month;
            }
            else {
                if (f.hours > maxe[y]) {
                    maxe[y] = f.hours; best[y] = f.month;
                }
                else if (f.hours == maxe[y] && f.month < best[y]) {
                    best[y] = f.month;
                }
            }
        }
    }
    if (c == 0) {
        cout << "Нет данных" << endl;
        return;
    }
    for (int t = 0; t < 11; t++) { ///k
            int bestH = -1;
            int bestY = 0;
            int bestM = 0;
            for (int y = 2000; y <= 2010; y++) {
                if (maxe[y] > bestH ||(maxe[y] == bestH && maxe[y] != 0 && y < bestY)) {
                    bestH = maxe[y];
                    bestY = y;
                    bestM = best[y];
                }
            }
            if (bestH <= 0) break;
            cout << bestH << " " << bestY << " " << bestM << endl;
            maxe[bestY] = 0; 
    }
}

void mergeSort(student a[], int L, int R, student t[]) {
    if (L >= R) return;

    int mid = (L + R) / 2;

    mergeSort(a, L, mid, t);
    mergeSort(a, mid + 1, R, t);

    int i = L, j = mid + 1, k = L;

    while (i <= mid && j <= R) {
        if (a[i].ball >= a[j].ball) { 
            t[k++] = a[i++];
        } else {
            t[k++] = a[j++];
        }
    }

    while (i <= mid) t[k++] = a[i++];
    while (j <= R) t[k++] = a[j++];

    for (int e = L; e <= R; e++) a[e] = t[e];
}

void sortStudents() {
    using namespace std;
    student arr[100], temp[100];
    int n = 0;

    ifstream file("a.txt");
    if (!file) { cout << "Не удалось открыть a.txt" << endl; return; }

    while (file >> arr[n].surname >> arr[n].ball) n++;
    file.close();

    mergeSort(arr, 0, n - 1, temp);

    ofstream fout("e.txt");
    if (!fout) { cout << "Не удалось создать e.txt" << endl; return; }

    for (int i = 0; i < n; i++) {
        fout << left << setw(15) << arr[i].surname
             << right << setw(3) << arr[i].ball << endl;
    }

    fout.close();
    cout << "Данные отсортированы и записаны в e.txt" << endl;
}

