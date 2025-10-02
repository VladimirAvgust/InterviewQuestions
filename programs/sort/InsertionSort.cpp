#include "InsertionSort.h"
#include <iostream>
#include <time.h>

InsertionSort::InsertionSort(const int* mass, const int lenght)
{
	this->lenght = lenght;
	this->mass = new int[lenght];
	for (int i = 0; i < lenght; i++) {
		this->mass[i] = mass[i];
	}
}

void InsertionSort::sort()
{
	clock_t start, end;
	start = clock();
	for (int i = 1; i < this->lenght; i++) {
		int key = this->mass[i];
		int j = i - 1;
		while (j >= 0 && this->mass[j] > key) {
			this->mass[j + 1] = this->mass[j];
			j = j - 1;
		}
		mass[j + 1] = key;
	}
	end = clock();
	this->time = (double)(end - start) / (double)CLOCKS_PER_SEC;
}

int* InsertionSort::getMass() const
{
	return this->mass;
}

int InsertionSort::getLenght() const
{
	return this->lenght;
}

double InsertionSort::getTime() const
{
	return this->time;
}


InsertionSort::~InsertionSort()
{
	delete[] this->mass;
	this->lenght = 0;
}

