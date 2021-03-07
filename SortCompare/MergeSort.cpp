#include "Sorts.h"

void Merge(int* arr, int left, int bound, int right) {
	int i_left = left;
	int j_right = bound;
	int k_res = 0;
	int* res = new int[right - left];
	while (i_left < bound || j_right < right) {
		if (arr[i_left] <= arr[j_right]) {
			res[k_res] = arr[i_left];
			k_res++;
			i_left++;
		}
		else {
			res[k_res] = arr[j_right];
			k_res++;
			j_right++;
		}
		if (i_left == bound) {
			for (size_t x = k_res; x < right - left; x++)
			{
				res[k_res] = arr[j_right];
				k_res++;
				j_right++;
			}
		}
		if (j_right == right) {
			for (size_t x = k_res; x < right - left; x++)
			{
				res[k_res] = arr[i_left];
				k_res++;
				i_left++;
			}
		}
	}
	for (size_t i = 0; i < right - left; i++)
	{
		arr[i] = res[i];
	}
	delete[] res;
}

void Sorts::MergeSort(int* arr, int n)
{
	if (n > 1) {
		int left = n / 2;
		int right = n - n / 2;
		MergeSort(arr, left);
		MergeSort(&arr[left], right);
		Merge(arr, 0, left, n);
	}
}