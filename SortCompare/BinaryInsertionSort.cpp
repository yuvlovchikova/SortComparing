#include "Sorts.h"

void Sorts::BinaryInsertionSort(int* values, int n) {
	for (size_t i = 1; i < n; i++)
	{
		int key = values[i];
		if (key < values[i - 1]) {
			int left = 0;
			int right = i - 1;
			while (left < right) {
				if (key < values[(left + right) / 2]) {
					right = (left + right) / 2;
				}
				else {
					left = (left + right) / 2 + 1;
				}
			}
			for (size_t j = i; j > left; j--) {
				values[j] = values[j - 1];
			}
			values[left] = key;
		}
	}
}