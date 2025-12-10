#include "vector.h"

template <typename Type>
vector<Type>::vector(unsigned int size){
    this->lenght = size;
    this->data = new Type [this->lenght];
    for (int i =0; i < this->lenght; i++){
        this->data[i]= 0;
    }
}

template <typename Type>
Type& vector<Type>::operator [](Type i){
    return this->data[i];
}


