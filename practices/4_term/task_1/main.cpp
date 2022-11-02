#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void Sorting(int X[], int N) { //Функция сортировки массива по убыванию
    for (int i = 0; i < N + 1; i++) {
        for (int j = i + 1; j < N + 1; j++) {
            if (X[i] < X[j]) {
                int k = X[i];
                X[i] = X[j];
                X[j] = k;
            }
        }
    }
}

void addElement(int X[], int N) { //Функция вставки элемента
    int H = rand() % 10 + 1;
    printf("Элемент для вставки:\t%d\n", H);
    X[N] = H;
}

int Average(int num, int &summ, int &amount) { //Функция нахождения простых чисел
    if (num > 1) {
        for (int i = 2; i < num; i++)
            if (num % i == 0)
                return false;
        summ += num;
        amount++;
    } else
        return false;
}

int main() {
    int N;
    int summ = 0, amount = 0;
    float answ;
    srand((unsigned int) time(NULL));
    printf("Укажите количество элементов массива: ");
    scanf("%d", &N);

    int *X = new int[N + 1];
    for (int i = 0; i < N; i++) X[i] = rand() % 10 + 1;

    for (int i = 0; i < N; i++) { // Переход в функцию нахождения суммы простых чисел и их среднего арифметического
        Average(X[i], summ, amount);
    }

    Sorting(X, N); // Сортируем массив по убыванию

    for (int i = 0; i < N; i++) printf("%d\t", X[i]);

    printf("\n");
    printf("Среднее арифметическое простых чисел до вставки числа: %.2f\n", (float) summ / amount);

    addElement(X, N); // Добавляем элемент
    Sorting(X, N); // Сортируем массив по убыванию
    summ = 0, amount = 0;
    for (int i = 0; i < N; i++) { // Переход в функцию нахождения суммы простых чисел и их среднего арифметического
        Average(X[i], summ, amount);
    }
    for (int i = 0; i < N + 1; i++) printf("%d\t", X[i]);
    printf("\n");
    printf("Среднее арифметическое простых чисел после вставки числа: %.2f\n", (float) summ / amount);
}