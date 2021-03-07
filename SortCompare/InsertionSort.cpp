#include "Sorts.h"
#include <iostream>

void Sorts::InsertionSort(int* values, int n) {
	for (size_t i = 1; i < n; i++)
	{
		for (size_t j = i; j > 0; j--)
		{
			if (values[j - 1] > values[j]) {
				std::swap(values[j - 1], values[j]);
			}
		}
	}
}
