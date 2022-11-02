#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <iostream>

using namespace std;

void CreateArray(vector<float> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        vec.at(i) = (float) (rand() % (10000 * vec.size())) / 1000 - 30;
        printf("%.2f\t", vec[i]);
    }
}

void TaskA(vector<float> &vec) {
    printf("Количество положительных элементов менее 5?\t");
    int times = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (vec.at(i) > 0)
            times++;
    }
    if (times > 5)
        printf("Нет!");
    else
        printf("Да!");
}

void TaskB(vector<float> &vec) {
    int times = 0, times2 = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (vec.at(i) < 50)
            times++;
        if (vec.at(i) < 55)
            times2++;
    }
    if (times % 4 == 0 && times != 0)
        printf("Количество элементов больших чем 50, кратно 4!\n");
    else
        printf("Количество элементов меньших чем 50, не кратно 4!\n");
    if (times2 % 4 == 0 && times != 0)
        printf("Количество элементов больших чем 55, кратно 4!");
    else
        printf("Количество элементов меньших чем 55, не кратно 4!");
}

int main() {
    srand((unsigned int) time(NULL));
    vector<float> vec(rand() % 30);
    printf("Сгенерирован следующий массив:\n");
    CreateArray(vec); //Заполнение вектора
    printf("\n");
    TaskA(vec); //Задача А
    printf("\n");
    TaskB(vec); //Задача Б
}

