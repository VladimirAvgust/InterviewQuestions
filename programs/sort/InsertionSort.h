#pragma once
class InsertionSort
{
private:
	int* mass = nullptr;
	int lenght = 0;
	double time = 0;

	
public:
	InsertionSort(const int* mass, const int lenght);

	void sort();

	int* getMass() const;
	int getLenght() const;
	double getTime() const;

	~InsertionSort();
};

