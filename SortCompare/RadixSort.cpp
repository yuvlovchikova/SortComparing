#include "Sorts.h"

union Union {
	unsigned int num;
	unsigned char digits[4];
};

void countingSort(int* numbers, int array_size, int iteration)
{
	Union union_digits;
	int counts_size = 256;
	int* counts = new int[counts_size];
	for (size_t i = 0; i < counts_size; i++)
	{
		counts[i] = 0;
	}
	for (size_t i = 0; i < array_size; i++)
	{
		union_digits.num = numbers[i];
		counts[union_digits.digits[iteration]]++;
	}
	for (size_t i = 1; i < counts_size; i++)
	{
		counts[i] += counts[i - 1];
	}
	int* res = new int[array_size];
	for (size_t i = array_size - 1; i > 0; --i)
	{
		union_digits.num = numbers[i];
		counts[union_digits.digits[iteration]]--;
		res[counts[union_digits.digits[iteration]]] = numbers[i];
	}
	union_digits.num = numbers[0];
	counts[union_digits.digits[iteration]]--;
	res[counts[union_digits.digits[iteration]]] = numbers[0];
	for (size_t i = 0; i < array_size; i++)
	{
		numbers[i] = res[i];
	}
}

void Sorts::RadixSort(int* numbers, int array_size)
{
	for (size_t j = 0; j < 4; j++)
	{
		countingSort(numbers, array_size, j);
	}
}