#include <iostream>
#include "BasicFunctions.h"
using namespace std;

int main() {
	int length = 6;
	int* arr = new int[length];

	ReadArray(arr, length);
	BubbleSort(arr, length, ascending);
	PrintArray(arr, length);

	BubbleSort(arr, length, descending);
	PrintArray(arr, length);
	return 0;
}