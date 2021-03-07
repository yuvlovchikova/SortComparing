#include "Sorts.h"
#include "DataGeneration.h"
#include "Checker.h"
#include <chrono>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

typedef void (Sorts::* sorts)(int* arr, int array_size);
int number = 0;

void MeasureTime(int  min_bound, int max_bound, int step) {
	number++;
	Generation generation_;
	Sorts sorts_;
	Checker checker_;
	sorts sorts_enum[8]{ &Sorts::BubbleSort, &Sorts::InsertionSort, &Sorts::BinaryInsertionSort, &Sorts::CountingSort, &Sorts::RadixSort, &Sorts::MergeSort,
		&Sorts::HoarSort, &Sorts::HeapSort };
	int** references = new int* [4];
	references[0] = new int[4100]; generation_.Generation1(references[0]);
	references[1] = new int[4100]; generation_.Generation2(references[1]);
	references[2] = new int[4100]; generation_.Generation3(references[2]);
	references[3] = new int[4100]; generation_.Generation4(references[3]);

	ofstream file("table" + to_string(number) + ".csv");
	file << "Array size;BubbleSort;InsertionSort;BinaryInsertionSort;CountingSort;RadixSort;MergeSort;HoarSort;HeapSort;BubbleSort;InsertionSort;BinaryInsertionSort;CountingSort;RadixSort;MergeSort;HoarSort;HeapSort;BubbleSort;InsertionSort;BinaryInsertionSort;CountingSort;RadixSort;MergeSort;HoarSort;HeapSort;BubbleSort;InsertionSort;BinaryInsertionSort;CountingSort;RadixSort;MergeSort;HoarSort;HeapSort;\n";
	for (int i = min_bound; i <= max_bound; i = i + step)
	{
		string row = "";
		row += to_string(i) + ";";
		int* arr = new int[i];
		for (int k = 0; k < 4; k++)
		{
			for (int j = 0; j < i; j++)
			{
				arr[j] = references[k][j];
			}
			for (int j = 0; j < 8; j++)
			{
				int average_time = 0;
				for (int t = 0; t < 33; t++)
				{
					auto start_point = chrono::high_resolution_clock::now();
					(sorts_.*sorts_enum[j])(arr, i);
					auto result = chrono::high_resolution_clock::now() - start_point;
					if (!checker_.CheckArray(arr, i))
						std::cout<< "Array incorrectly sorted";
					if (t > 2) {
						long long result_time = chrono::duration_cast<chrono::nanoseconds>(result).count();
						average_time += result_time;
					}
				}
				average_time /= 30;
				row += to_string(average_time) + ";";
			}
		}
		file << row + "\n";
		delete[] arr;
	}
	delete[] references[0];
	delete[] references[1];
	delete[] references[2];
	delete[] references[3];
	delete[] references;
}

int main()
{
		MeasureTime(50, 300, 50);
		MeasureTime(100, 4100, 1000);
}