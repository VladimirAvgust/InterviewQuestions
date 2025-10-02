#pragma once

template <typename Type>
class vector
{
private:
    unsigned int lenght = 0;
    Type *data = nullptr;

public:
    vector(unsigned int size);
    
};

#include "vector.cpp"
