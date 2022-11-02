#include <stdio.h>
#include <vector>
#include <ctime>
#include <string.h>
#include <iostream>

using namespace std;

struct MyStruct {
    char Surname[255];
    char Group[255];
    int MarkPhysics;
    int MarkInformatic;
    int MarkHistory;

};

void CreateArray(vector<MyStruct> &vec, int &N) {
    MyStruct Student; //Чтобы поместить в структуру объект, объект должен существовать
    printf("Введите количество студентов: ");
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        vec.push_back(Student);
        char group[255], surname[255];
        printf("Введите фамилию студента: ");
        scanf("%s", surname);
        printf("Введите группу студента: ");
        scanf("%s", group);

        strcpy(vec.at(i).Group, group);
        strcpy(vec.at(i).Surname, surname);
        vec.at(i).MarkPhysics = rand() % 4 + 2;
        vec.at(i).MarkInformatic = rand() % 4 + 2; //Генерация оценки ОТ ДВУХ до 4+1
        vec.at(i).MarkHistory = rand() % 4 + 2;


    }
}

void ListSort(vector<MyStruct> &vec, int &N) {
    for (int i = 1; i < vec.size(); i++) {
        for (int j = 1; j < vec.size(); j++) {
            if (vec.at(j).Surname > vec.at(j - 1).Surname) {
                printf("НЕВЕРНО!");
                auto times = vec.at(j);
                vec.at(j) = vec.at(j - 1);
                vec.at(j - 1) = times;
            }
        }
    }
}

void StudentsList(vector<MyStruct> &vec, int &N) {
    printf("Список студентов:\n");
    int times = 1;
    for (int i = 0; i < N; i++) {
        printf("****КАРТОЧКА СТУДЕНТА №%d:****\n", times++);
        printf("Фамилия: %s\n", vec.at(i).Surname);
        printf("Группа: %s\n", vec.at(i).Group);
        printf("Физика: %d\n", vec.at(i).MarkPhysics);
        printf("Информатика: %d\n", vec.at(i).MarkInformatic);
        printf("История: %d\n", vec.at(i).MarkHistory);
    }
}

void GPAinHistory(vector<MyStruct> &vec, int &N) {
    double GPA;
    for (int i = 0; i < N; i++) {
        GPA += vec.at(i).MarkHistory;
    }
    printf("Среднйи балл по истории: %.2f\n", GPA / N);
}

void NicePhysics(vector<MyStruct> &vec, int &N) {
    printf("Оценку 5 по физике имеют следующие студенты:\n");
    int times;
    for (int i = 0; i < N; i++) {
        if (vec.at(i).MarkPhysics == 5) {
            printf("************************\n");
            printf("Фамилия: %s\n", vec.at(i).Surname);
            printf("Группа: %s\n", vec.at(i).Group);
            printf("Физика: %d\n", vec.at(i).MarkPhysics);
            printf("Информатика: %d\n", vec.at(i).MarkInformatic);
            printf("История: %d\n", vec.at(i).MarkHistory);
            times++;
        }
    }
    printf("Всего отличников по физике: %d\n", times);
}

int main() {
    int N;
    srand(time(NULL));
    vector <MyStruct> vec; //Вектор vec содержит структуры типа MyStruct
    CreateArray(vec, N); //Записали данные в одну структуру
    ListSort(vec, N);
    StudentsList(vec, N); //Вывод списка студентов
    GPAinHistory(vec, N); //Вычисление среднего балла по истории
    NicePhysics(vec, N); //Список отличников по физике и их количество
}