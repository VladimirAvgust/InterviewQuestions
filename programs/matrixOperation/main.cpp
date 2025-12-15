#include <iostream>
#include <Windows.h> 

#include "matrix.h"
using namespace std;



int main(){
    SetConsoleOutputCP(CP_UTF8);
    //для умножения матрицы на вектор нужно строку умножить на столбец
    cout << "Start" << endl;
    int strok = 0;
    int stolb = 0;
    const int max = 5;
    const int min = 1;

    cout << "Введите кол-во строк: ";
    cin >> strok;
    cout << "Введите кол-во столбцов: ";
    cin >> stolb;
    
    Matrix m1(strok, stolb);
    m1.createRandomMatrix(1, 5);
    cout << m1 << endl;

    Matrix m2(strok, stolb);
    m2.createRandomMatrix(1, 5);
    cout << m2 << endl;

    cout << "Сложение" << endl;
    Matrix m3 = m1 + m2;
    cout << m3 << endl;


    cout << "Умножение" << endl;
    Matrix m4 = m1 * m2;
    cout << m4 << endl;



    cout << "End" << endl;

    return 0;
}

