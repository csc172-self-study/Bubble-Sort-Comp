/*
 * BubbleSortComp.cpp
 *
 *  Created on: Aug 28, 2019
 *      Author: alex
 */

#include "BubbleSort.h"
#include <ctime>
#include <random>
#include <iostream>
using std::cout;

int main() {
	const int SIZE = 100000;

	clock_t start;

	std::random_device rd;
	std::mt19937 eng(rd());

	std::uniform_int_distribution<> posDistr(0,SIZE);

	int array[SIZE]; int array1[SIZE]; int array2[SIZE];
	for (int i = 0; i < SIZE; ++i) {
		array[i] = posDistr(eng);
		array1[i] = array[i];
		array2[i] = array[i];
	}

	start = clock();
	BubbleSort<int>(array1, SIZE);
	double orig_sort_time = (clock() - start)/ (double) CLOCKS_PER_SEC;

	start = clock();
	BubbleSort2<int>(array2, SIZE);
	double new_sort_time = (clock() - start)/ (double) CLOCKS_PER_SEC;

	for (int i = 1; i < SIZE; ++i) {
		if (array1[i] < array1[i-1]) {
			cout << "Array1 was sorted incorrectly.\n";
		}
		if (array2[i] < array2[i-1]) {
			cout << "Array2 was sorted incorrectly.\n";
		}

		//		cout << "Arrays were not sorted the same. Something wrong.\n";
		//					cout << sortedArray1[i] << " != " << sortedArray2[i] << "\n";
	}

	cout << "Original method took " << orig_sort_time << " s.\n";
	cout << "New short-circuit method took " << new_sort_time << " s.\n";
}





