#include "BasicFunctions.h"
#include <iostream>
using namespace std;


// Basic Functions

void Swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

// Mathematics

bool isPrime(int number) {

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

int MaxElement(int * arr, int length)
{
	if (length == 1)
		return arr[0];

	int max = arr[0];
	for (int i = 1; i < length; ++i) {
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

int MinElement(int * arr, int length)
{
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

void BubbleSort(int * arr, int length, bool(*order)(int , int))
{
	for (int i = 0; i < length - 1; ++i) {
		for (int j = i + 1; j < length; ++j) {
			if (order(arr[j], arr[i]))
				Swap(arr[i], arr[j]);
		}
	}
}



