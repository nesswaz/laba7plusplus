#ifndef H_H
#define H_H

#include <vector>
#include <string>


void sort_v(std::vector<int>& a);
void task1();

struct user {
    int code;
    int hours;
    int year;
    int month;
};


void task2();

struct student {
    std::string surname;
    int ball;
};

void sortStudents();
void mergeSort(student a[], int L, int R, student t[]);


#endif