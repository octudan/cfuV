#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include <math.h>

using namespace std;

void CreateArray (vector<vector<int> >&vec) {
    
    for (int i=0; i<vec.size(); i++){
        for (int j=0; j<vec[i].size(); j++){
            vec[i][j] = rand()%30;
            printf ("%d\t", vec[i][j]);
        }
        printf("\n");
    }
    
}

void TaskA (int W, vector<vector<int> >&vec){
    int times=0;
    for (int i=0; i<W; i++){
        if (vec[i][1] > 10)
            times+=vec[i][1];
    }
    printf("Сумма элементов второго столбца массива, больших 10 = %d\n", times);
}

void TaskB (int H, vector<vector<int> >&vec){
    int times=0;
    for (int i=0; i<H; i++){
        if(vec[2][i] < 25)
            times+=vec[2][i];
    }
    printf("Сумма элементов третьей строки массива, не превышающих 25 = %d\n", times);
}
void TaskC (int H, vector<vector<int> >&vec){
    int times=0;
    for (int i=0; i<H; i++){
        if(vec[0][i] != 0)
            times++;
    }
    printf("Количество ненулевых элементов первой строки массива = %d\n", times);
}
void TaskD (int W, vector<vector<int> >&vec){
    int times=0;
    for (int i=0; i<W; i++){
        if (vec[i][1] > 15)
            times++;
    }
    printf("Количество элементов второго столбца массива, больших 15 = %d", times);
}

int main() {
    srand((unsigned int)time(NULL));
    int W = rand()%10+2, H = rand()%10+2;
    vector< vector<int>> vec(W, vector<int>(H));
    printf("Сгенерирован следующий массив:\n");
    CreateArray(vec);             //Заполнение вектора
    TaskA(W, vec);                      //Задача А
    TaskB(H, vec);                      //Задача Б
    TaskC(H, vec);                      //Задача В
    TaskD(W, vec);                      //Задача Г
}