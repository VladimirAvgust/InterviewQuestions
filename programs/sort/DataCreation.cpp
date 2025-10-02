#include "DataCreation.h"

#include <cstdlib>
#include <time.h>
#include <iostream>

int* DataCreation::randomMass(int lenght, int min, int max)
{
	srand(time(NULL));
	int* mass = new int[lenght] {0};
	for (int i = 0; i < lenght; i++) {
		mass[i] = rand() % (max - min + 1) + min;
	}

	return mass;
}

DataCreation::DataCreation(int lenght)
{
	this->lenght = lenght;
	this->data = new int[lenght];
	this->data = randomMass(lenght, 0, 1);
}

DataCreation::DataCreation(int lenght, int min, int max)
{
	this->lenght = lenght;
	this->data = new int[lenght];
	this->data = randomMass(lenght, min, max);
}

DataCreation::DataCreation(const int lenght, const int* mass)
{
	this->lenght = lenght;
	this->data = new int[lenght];
	for (int i = 0; i < lenght; i++) {
		this->data[i] = mass[i];
	}
}

int DataCreation::getLenght() const
{
	return this->lenght;
}

int* DataCreation::getData() const 
{
	return this->data;
}

void DataCreation::print()
{
	for (int i = 0; i < this->lenght; i++) {
		std::cout << this->data[i] << " ";
	}
	std::cout << std::endl;
}

DataCreation::~DataCreation()
{
	delete[] this->data;
	lenght = 0;
}

bool operator==(const DataCreation &d1, const DataCreation &d2)
{
	if (d1.getLenght() != d2.getLenght()) return false;
	for (int i = 0; i < d1.getLenght(); i++) {
		if (d1.getData()[i] != d2.getData()[i]) {
			return false;
		}
	}
	return true;
}
