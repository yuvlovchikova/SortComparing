#include "Sorts.h"

void Sorts::BubbleSort(int* values, int n) {
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (values[j + 1] < values[j]) {
				int swapped = values[j];
				values[j] = values[j + 1];
				values[j + 1] = swapped;
			}
		}
	}
}