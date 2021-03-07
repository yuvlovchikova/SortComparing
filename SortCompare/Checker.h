#pragma once

class Checker {
public:
	bool CheckArray(int* arr, int n) {
		for (size_t i = 0; i < n - 1; i++)
		{
			if (arr[i] > arr[i + 1])
				return false;
		}
		return true;
	}
};