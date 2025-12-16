#pragma once
#include <iostream>
class Matrix{
    private:
        int **matrix = nullptr;
        int lenX =0;
        int lenY =0;
    public:
        Matrix();
        Matrix(const Matrix& m); //конструктор копирования
        Matrix(const int lenX, const int lenY);
        void createRandomMatrix(const int min, const int max);
        
        friend std::ostream& operator << (std::ostream& os, const Matrix &matrix);
        friend Matrix operator + (Matrix const  &matrix1, Matrix const & matrix2);
        friend Matrix operator * (Matrix const  &matrix1, Matrix const & matrix2);

        ~Matrix();

};