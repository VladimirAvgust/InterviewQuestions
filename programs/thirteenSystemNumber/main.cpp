#include <iostream>

using namespace std;

int main() {
    // максимальная сумма 
    int base = 13;
    int maxSumm = 72;
    
    
    int partElement = 6;
    // массив в котором будем хранить суммы для кол-ва цифр
    unsigned long long **mass = new unsigned long long *[partElement + 1];
    for (int i = 0; i <= partElement; i++){
        mass[i] = new unsigned long long [maxSumm + 1];
    }
    for (int i = 0; i <= partElement; i++)
        for(int j = 0; j <= maxSumm; j++)
            mass[i][j] =0;
        
    //для первого и последнего набора должно быть по 1 варианту
    mass[0][0] = 1;
    // для всех остальнйх 
    // будем получать колличество сумм из определенного количества цифр
    for (int i = 1; i <= partElement; i++){
        for(int j = 0; j <= maxSumm; j++){
            for (int k = 0; k < base; k++){
                if (j >= k){
                    mass[i][j] += mass[i - 1][j - k];
                }
            }
        }
    }
    /*
    for (int i = 0; i <= partElement; i++){
        cout << i << "     ";
        for(int j = 0; j <= 25; j++){
            cout << mass[i][j] << " ";
        }
        cout << endl;
    }*/
    
    //теперь можно посчитать общее колическтво красивых чисел т.к. для каждой суммы слева их будет в раз больше как и справа
    unsigned long long summNumber = 0;
    for (int i = 0; i <= maxSumm; i++){
        summNumber += mass[partElement][i] * mass[partElement][i];
    }
    //учтем что число по середине не поменяется и все будет суппер гуд
    cout << summNumber * base << endl;

     for (int i = 0; i <= partElement; i++) {
        delete[] mass[i];
    }
    delete[] mass;

    return 0;
}