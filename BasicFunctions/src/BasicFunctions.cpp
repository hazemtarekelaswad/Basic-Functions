#include <cmath>
#include <iostream>
#include "BasicFunctions.h"
using namespace std;
//#define SORT_AND_REMOVEDUP


// Basic Functions

void Swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}


// Mathematics

bool IsPrime(int number) {

	if (number == 1)
		return false;
	
	if (number == 2)
		return true;
	
	for (int i = 2; i < number; ++i) {
		if (!(number % i))
			return false;
	}
	return true;
}

int CompareDoubles(double x, double y){
	if (fabs(x - y) <= 1e-10)
		return 0;
	return(x > y ? 1 : -1);
}

// String Basic Manipulation


 // Arrays Manipulation

void ReadArray(int* arr, int length) {
	for (int i = 0; i < length; ++i)
		cin >> arr[i];
}

void PrintArray(int* arr, int length) {
	for (int i = 0; i < length; ++i)
		cout << arr[i] << ' ';
	cout << endl;
}

int MaxElement(int* arr, int length) {
	if (length == 1)
		return arr[0];

	int max = arr[0];
	for (int i = 1; i < length; ++i) {
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

int MinElement(int* arr, int length) {
	if (length == 1)
		return arr[0];

	int min = arr[0];
	for (int i = 1; i < length; ++i) {
		if (arr[i] < min)
			min = arr[i];
	}
	return min;
}


bool ascending(int x, int y) {
	return x < y;
}

bool descending(int x, int y) {
	return x > y;
}

void BubbleSort(int* arr, int length, bool(*order)(int , int)) {
	for (int i = 0; i < length - 1; ++i) {
		for (int j = i + 1; j < length; ++j) {
			if (order(arr[j], arr[i]))
				Swap(arr[i], arr[j]);
		}
	}
}

void Reverse(int* arr, int length){
	for (int i = 0; i < length / 2; ++i) {
		if(arr[i] != arr[length - 1 - i])
			Swap(arr[i], arr[length - 1 - i]);
	}
}

int* RemoveDuplicates(int* arrIn, int lengthIn, int &lengthOut){

	lengthOut = 0;

#ifdef SORT_AND_REMOVEDUP

	BubbleSort(arrIn, lengthIn, ascending);

	for (int i = 0; i < lengthIn - 1; ++i) {
		if (arrIn[i] != arrIn[i + 1])
			++lengthOut;
	}
	++lengthOut;

	int *arrOut = new int[lengthOut];

	int j = 0;
	for (int i = 0; i < lengthIn - 1; ++i) {
		if (arrIn[i] != arrIn[i + 1])
			arrOut[j++] = arrIn[i];
	}
	arrOut[lengthOut - 1] = arrIn[lengthIn - 1];

	return arrOut;
	
#else

	for (int i = 0; i < lengthIn - 1; ++i) {
		bool check = true;
		for (int j = i + 1; j < lengthIn; ++j) {
			if (arrIn[i] == arrIn[j]) {
				check = false;
				break;
			}
		}
		if (check)
			++lengthOut;
	}
	++lengthOut;

	int *arrOut = new int[lengthOut];

	int k = 0;
	for (int i = 0; i < lengthIn - 1; ++i) {
		bool check = true;
		for (int j = i + 1; j < lengthIn; ++j) {
			if (arrIn[i] == arrIn[j]) {
				check = false;
				break;
			}
		}
		if (check)
			arrOut[k++] = arrIn[i];
	}
	arrOut[lengthOut - 1] = arrIn[lengthIn - 1];
	return arrOut;

#endif // SORT_AND_REMOVEDUP
}



