#include "matrix.h"
#include <iostream>
#include <random>

Matrix::Matrix(){}
Matrix::Matrix(const int lenX, const int lenY){
    this->lenX = lenX;
    this->lenY = lenY;
    this->matrix = new int *[lenX];
    for(int i = 0; i< lenX; i++){
        matrix[i] = new int [lenY];
    }
    for(int i =0; i < lenX; i++){
        for(int j = 0; j < lenY; j++){
            this->matrix[i][j] = 0;
        }
    }
}

void Matrix::createRandomMatrix(const int min, const int max){
    std::random_device rd; // Источник энтропии
    std::mt19937 gen(rd()); // Mersenne Twister, seed из random_device
    std::uniform_int_distribution<> distrib(min, max);
    for(int i =0; i < this->lenX; i++){
        for(int j = 0; j < this->lenY; j++){
            this->matrix[i][j] = distrib(gen);
        }
    }
}


std::ostream& operator << (std::ostream &os, const Matrix &matrix){
    for(int i = 0; i < matrix.lenX; i++){
        for(int j = 0; j < matrix.lenY; j++){
            std::cout << matrix.matrix[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}
Matrix operator + (Matrix const  &matrix1, Matrix const & matrix2){
    if(matrix1.lenX == matrix2.lenX && matrix2.lenY == matrix2.lenY){
        Matrix summ(matrix1.lenX, matrix1.lenY);
        summ.matrix = matrix1.matrix;
        for(int i = 0; i < matrix1.lenX; i++){
            for(int j = 0; j < matrix1.lenY; j++){
                summ.matrix[i][j] += matrix2.matrix[i][j];
            }
        }
        return summ;
    }
    return Matrix();
}

Matrix operator * (Matrix const &matrix1, Matrix const &matrix2){
    //для умножение важно, чтобы количество столбцов первой матрицы было равно кличеству строк второй матрицы 
   
    if(matrix1.lenX == matrix2.lenY){
        Matrix product = Matrix(matrix1.lenX, matrix2.lenY);
        for (int i = 0; i < product.lenX; i++){
            for (int j = 0; j < product.lenY; j++){
                for (int k =0; k < matrix2.lenY; k++){
                    product.matrix[i][j] += (matrix1.matrix[i][k] + matrix2.matrix[k][j]); 
                }
            }
        }
        return product;
    }
    return Matrix();
}

Matrix::~Matrix(){
    for(int i =0; i < this->lenX; i++){
        delete [] this->matrix[i];
    }
    delete [] this->matrix;
    this->lenX = 0;
    this->lenY = 0;
}