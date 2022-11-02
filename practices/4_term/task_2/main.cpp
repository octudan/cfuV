#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <iostream>

using namespace std;

void CreateArray(vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        vec.at(i) = rand() % 10 + 11;
        printf("%d\t", vec[i]);
    }
}

void TaskA(vector<int> &vec) {
    printf("Массив после выполнения задачи А:\t");
    for (int i = 0; i < vec.size(); i++) {
        if (vec.at(i) % 10 == 4) {
            printf("%d\t", vec[i] / 2);
        } else {
            printf("%d\t", vec[i]);
        }
    }
}

void TaskB(vector<int> &vec) {
    printf("Массив после выполнения задачи Б:\t");
    for (int i = 0; i < vec.size(); i++) {
        if (vec.at(i) % 2 == 0) {
            printf("%.0f\t", pow(vec[i], 2));
        } else {
            printf("%d\t", vec[i]*2);
        }
    }
}

void TaskC(vector<int> &vec, int &A, int &B) {
    printf("Массив после выполнения задачи В:\t");
    for (int i = 0; i < vec.size(); i++) {
        if (vec.at(i) % 2 == 0) {
            printf("%d\t", vec[i] + A);
        } 
        else if (i % 2 == 0){
            printf("%d\t", vec[i] - B);
        }
        else{
            printf("%d\t", vec[i]);
        }
    }
}

int main() {
    srand((unsigned int) time(NULL));
    int A, B;
    vector<int> vec(rand() % 10);
    A = rand() % 10;
    B = rand() % 10 + 4;
    printf("Сгенерированны следущие значения\tА: %d\tB: %d\n", A, B);
    printf("Сгенерирован следующий массив:\t\t");
    CreateArray(vec); //Заполнение вектора
    printf("\n");
    TaskA(vec); //Задача А
    printf("\n");
    TaskB(vec); //Задача Б
    printf("\n");
    TaskC(vec, A, B); //Задача В
    printf("\n");
}