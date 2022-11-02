#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include <math.h>

using namespace std;

void CreateArray (vector<vector<int> >&vec) {
    
    for (int i=0; i<vec.size(); i++){
        for (int j=0; j<vec[i].size(); j++){
            vec[i][j] = rand()%10;
            printf ("%d\t", vec[i][j]);
        }
        printf("\n");
    }
    
}

void TaskA (int H, vector<vector<int> >&vec){
    int times=0;
    for (int i=0; i<H; i++){
        times+=pow(vec[1][i],2);
    }
    printf("Сумма квадратов элементов второй строки = %d\n", times);
}

void TaskB (int W, int C, vector<vector<int> >&vec){
    int times=0;
    for (int i=0; i<W; i++){
        times+=pow(vec[i][C-1],2);
    }
    printf("Сумма квадратов элементов %d-го столбца = %d", C, times);
}

int main() {
    srand((unsigned int)time(NULL));
    int W = 2+rand()%10, H = 2+rand()%10;
    int C = 1+rand()%H;
    vector< vector<int>> vec(W, vector<int>(H));
    printf("Сгенерирован следующий массив:\n");
    CreateArray(vec);             //Заполнение вектора
    TaskA(H, vec);                      //Задача А
    TaskB(W, C, vec);                   //Задача Б
}