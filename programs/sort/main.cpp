#include <iostream>
#include <thread>
using namespace std;

#include "DataCreation.h"
#include "BubbleSort.h"
#include "InsertionSort.h"


int main() {
	

	DataCreation data(100000, 1, 100);
	//data.print();
	
	BubbleSort bubbleSort(data.getData(), data.getLenght());
	InsertionSort insertionSort(data.getData(), data.getLenght());

	DataCreation dataResultBubble(bubbleSort.getLenght(), bubbleSort.getMass());
	//dataResultBubble.print();
	DataCreation dataResultIncert(insertionSort.getLenght(), insertionSort.getMass());
	//dataResultIncert.print();
	/*if (dataResultBubble == dataResultIncert) {
		cout << "equals" << endl;
	}*/

	std::thread t1([&]() {
		bubbleSort.sort();
		cout << "bubbleSort = " << bubbleSort.getTime() << endl;
	});

	std::thread t2([&]() {
		insertionSort.sort();
		cout << "insertionSort = " << insertionSort.getTime() << endl;
	});
	t1.join();
	t2.join();
	return 0;
}