#include <iostream>
#include "BasicFunctions.h"
using namespace std;

int main() {
	int length1 = 7;
	int* arr1 = new int[length1];

	int length2 = 10;
	int* arr2 = new int[length2];

	ReadArray(arr1, length1);
	ReadArray(arr2, length2);

	int lengthB = 0;
	int* res = Merge(arr1, length1, arr2, length2, lengthB);

	PrintArray(res, lengthB);

	delete[] res;
	delete[] arr1;
	delete[] arr2;
	return 0;
}