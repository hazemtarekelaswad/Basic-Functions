#include <iostream>
#include "BasicFunctions.h"
using namespace std;

int main() {
	int length = 7;
	int* arr = new int[length];

	ReadArray(arr, length);

	int lengthB = 0;
	int * res = RemoveDuplicates(arr, length, lengthB);

	PrintArray(res, lengthB);

	delete[] res;
	delete[] arr;
	return 0;
}