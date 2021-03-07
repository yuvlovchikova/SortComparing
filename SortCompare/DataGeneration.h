#pragma once
#include <stdlib.h>
#include <time.h>

class Generation {
public:
	int size = 4100;
	void Generation1(int* arr) {
		srand(time(0));
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = rand() % 6;
		}
	}

	void Generation2(int* arr) {
		srand(time(0));
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = rand() % 4001;
		}
	}

	void Generation3(int* arr) {
		for (size_t i = 0; i < size; i++)
		{
			if (i < 300) {
				if (i % 50 == 18)
					arr[i] = i + 19;
				else if (i % 50 == 37)
					arr[i] = i - 19;
				else
					arr[i] = i;
			}
			else {
				if (i % 1000 == 333)
					arr[i] = i + 333;
				else if (i % 1000 == 666)
					arr[i] = i - 333;
				else if (i % 1000 == 500)
					arr[i] = i + 200;
				else if (i % 1000 == 700)
					arr[i] = i - 200;
				else
					arr[i] = i;
			}
		}
	}

	void Generation4(int* arr) {
		srand(time(0));
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = 4100 - i;
		}
	}
};