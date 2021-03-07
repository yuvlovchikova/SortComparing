#include "Sorts.h"

void Sorts::CountingSort(int* numbers, int array_size)
{
	int max_val = -1;
	int min_val = 1000001;
	for (size_t i = 0; i < array_size; i++)
	{
		if (numbers[i] > max_val)
			max_val = numbers[i];
		if (numbers[i] < min_val)
			min_val = numbers[i];
	}

	int  counts_size = max_val - min_val + 1;
	int* counts = new int[counts_size];
	for (size_t i = 0; i < counts_size; i++)
	{
		counts[i] = 0;
	}
	for (size_t i = 0; i < array_size; i++)
	{
		counts[numbers[i] - min_val]++;
	}
	for (size_t i = 1; i < counts_size; i++)
	{
		counts[i] += counts[i - 1];
	}
	int* res = new int[array_size];
	for (size_t i = array_size - 1; i > 0; --i)
	{
		counts[numbers[i] - min_val]--;
		res[counts[numbers[i] - min_val]] = numbers[i];
	}
	counts[numbers[0] - min_val]--;
	res[counts[numbers[0] - min_val]] = numbers[0];
	for (size_t i = 0; i < array_size; i++)
	{
		numbers[i] = res[i];
	}
	delete[] counts;
	delete[] res;
}
