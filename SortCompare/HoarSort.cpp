#include "Sorts.h"
#include <iostream>

void HoarSort_(int* numbers, int left, int right)
{
	int i = left;
	int j = right;
	int pivot = numbers[(i + j) / 2];
	do {
		while (numbers[i] < pivot)
			i++;
		while (numbers[j] > pivot)
			j--;
		if (i <= j) {
			std::swap(numbers[i], numbers[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (left < j)
		HoarSort_(numbers, left, j);
	if (right > i)
		HoarSort_(numbers, i, right);
}

void Sorts::HoarSort(int* numbers, int array_size) {
	HoarSort_(numbers, 0, array_size - 1);
}