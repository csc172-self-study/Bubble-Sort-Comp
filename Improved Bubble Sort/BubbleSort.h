/*
 * Bubble.h
 *
 *  Created on: Jul 22, 2019
 *      Author: alex
 */

#ifndef BUBBLESORT_H_
#define BUBBLESORT_H_

#include "ArrayOperations.h"

template <typename E>
void BubbleSort(E array[], int size) {
	for (int i = 0; i < size-1; ++i) {
		for (int j = size-1; j > i; --j) {
			if (array[j] < array[j-1]) {
				swap(array, j, j-1);
			}
		}
	}
}

template <typename E>
void BubbleSort2(E array[], int size) {
	for (int i = 0; i < size-1; ++i) {
		bool swapMade = false;
		for (int j = size-1; j > i; --j) {
			if (array[j] < array[j-1]) {
				swap(array, j, j-1);
				swapMade = true;
			}
		}
		if (!swapMade) return; // Short-circuit if no swap made on last iteration of inner loop
	}
}

#endif /* BUBBLESORT_H_ */
