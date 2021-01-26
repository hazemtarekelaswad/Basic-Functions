#include <cmath>
#include <iostream>
#include <algorithm>
#include "BasicFunctions.h"
using namespace std;


// ========================= Basic Functions ========================= 

void Swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

void Swap(string& x, string& y) {
	string temp = x;
	x = y;
	y = temp;
}


// ========================= Mathematics ========================= 

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

int CompareDoubles(double x, double y) {
	if (fabs(x - y) <= 1e-10)
		return 0;
	return(x > y ? 1 : -1);
}

long long Factorial(int number) {
	if (!number)
		return 1;
	return number * Factorial(number - 1);
}

long long ConsecutiveSum(int num) {
	return (num + 1) * (num / 2) + (num % 2) * (1 + static_cast<double>(num) / 2);
}

long long Fibonacci(int num) {
	return static_cast<long long>(1.0 / sqrt(5.0) * (pow(1.0 / 2.0 + sqrt(5.0) / 2.0, num) - pow(1.0 / 2.0 - sqrt(5.0) / 2.0, num)));
}

long long GCD(long long x, long long y) {
	//long long max = (x > y) ? x : y;
	//long long min = (x < y) ? x : y;
	long long max = (x > y) * x + (x <= y) * y;
	long long min = (x < y) * x + (x >= y) * y;
	if (!min)
		return max;
	GCD(min, max % min);
}


// ========================= String Manipulation Functions =========================

void Upper(string& str) {
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	}
}

void Lower(string& str) {
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	}
}

void Capitalize(string& str) {
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 32;

	if (str.length() == 1)
		return;

	for (int i = 1; i < str.length(); ++i) {
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	}

}

void Alphabetize(string* str, int length) {

	for (int i = 0; i < length - 1; ++i) {
		Lower(str[i]);
		for (int j = i + 1; j < length; ++j) {
			if (j == length - 1)
				Lower(str[j]);

			for (int k = 0; k < str[str[i].length() < str[j].length() ? i : j].length(); ++k) {
				if (str[j][k] < str[i][k]) {
					Swap(str[i], str[j]);
					break;
				}
				if (str[j][k] > str[i][k])
					break;

				if (str[j].length() < str[i].length())
					Swap(str[i], str[j]);
			}
		}
	}
}

bool IsLower(char letter) {
	return (letter >= 'a' && letter <= 'z');
}


// ========================= Array Manipulation Functions ========================= 

void ReadArray(int* arr, int length) {
	for (int i = 0; i < length; ++i)
		cin >> arr[i];
}

void ReadArray(string* arr, int length) {
	for (int i = 0; i < length; ++i)
		cin >> arr[i];
}

void PrintArray(int* arr, int length) {
	for (int i = 0; i < length; ++i)
		cout << arr[i] << ' ';
	cout << endl;
}

void PrintArray(string* arr, int length) {
	for (int i = 0; i < length; ++i)
		cout << arr[i] << endl;
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

int MaxElement(int* arr, int first, int last) {
	if (first == last)
		return arr[first];

	int mid = first + (last - first) / 2;

	int leftMax = MaxElement(arr, first, mid);
	int rightMax = MaxElement(arr, mid + 1, last);

	return leftMax > rightMax ? leftMax : rightMax;

	//	return max(MaxElement(arr, first, mid), MaxElement(arr, mid + 1, last));
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

long long SumArray(int* arr, int n) {
	long long sum = 0;
	for (int i = 0; i < n; ++i)
		sum += arr[i];
	return sum;
}

long long Multiply(int* arr, int n) {
	long long prod = 1;
	for (int i = 0; i < n; ++i)
		prod *= arr[i];
	return prod;
}

void Reverse(int* arr, int length) {
	for (int i = 0; i < length / 2; ++i) {
		if (arr[i] != arr[length - 1 - i])
			Swap(arr[i], arr[length - 1 - i]);
	}
}

int* Merge(int* arr1, int length1, int* arr2, int length2, int& lengthOut) {

	lengthOut = length1 + length2;
	int* arrOut = new int[lengthOut];

	for (int i = 0; i < length1; ++i)
		arrOut[i] = arr1[i];

	int j = 0;
	for (int i = length1; i < lengthOut; ++i)
		arrOut[i] = arr2[j++];

	return arrOut;
}

//#define SORT_AND_REMOVEDUP
int* RemoveDuplicates(int* arrIn, int lengthIn, int& lengthOut) {

	lengthOut = 0;

#ifdef SORT_AND_REMOVEDUP

	BubbleSort(arrIn, lengthIn, ascending);

	for (int i = 0; i < lengthIn - 1; ++i) {
		if (arrIn[i] != arrIn[i + 1])
			++lengthOut;
	}
	++lengthOut;

	int* arrOut = new int[lengthOut];

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

	int* arrOut = new int[lengthOut];

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


// ========================= Sorting and Searching Algorithms ========================= 

int BinarySearch(int* arr, int first, int last, int target) {
	if (first > last)
		return -1;

	//int mid = (last + first) / 2;
	int mid = first + (last - first) / 2;	// Better calculation of mid in order to prevent any overflow to occur

	if (arr[mid] == target)
		return mid;

	if (target < arr[mid])
		BinarySearch(arr, first, mid - 1, target);
	else
		BinarySearch(arr, mid + 1, last, target);
}

bool ascending(int x, int y) {
	return x < y;
}

bool descending(int x, int y) {
	return x > y;
}

void SelectionSort(int* arr, int length, bool(*order)(int, int)) {
	if (length == 1 || length == 0)
		return;

	for (int i = 0; i < length - 1; ++i) {
		int Extremei = i;
		for (int j = i + 1; j < length; ++j)
			if (order(arr[j], arr[Extremei]))
				Extremei = j;
		Swap(arr[i], arr[Extremei]);
	}
}

void BubbleSort(int* arr, int length, bool(*order)(int, int)) {
	if (length == 1 || length == 0)
		return;

	for (int i = 0; i < length - 1; ++i)
		for (int j = 0; j < length - i - 1; ++j)
			if (order(arr[j + 1], arr[j]))
				Swap(arr[j + 1], arr[j]);
}

void InsertionSort(int* arr, int length, bool(*order)(int, int)) {
	if (length == 1 || length == 0)
		return;

	for (int i = 1; i < length; ++i) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && order(key, arr[j])) {
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
}

void ShellSort(int* arr, int length, bool(*order)(int, int)) {
	if (length == 1 || length == 0)
		return;

	for (int gap = length / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < length; ++i) {
			int key = arr[i];
			int j = i - gap;
			while (j >= 0 && order(key, arr[j])) {
				arr[j + gap] = arr[j];
				j -= gap;
			}
			arr[j + gap] = key;
		}
	}
}

void Merge(int* arr, int first, int mid, int last, bool(*order)(int, int)) {
	int leftSize = mid - first + 1;
	int* leftArr = new int[leftSize];

	int rightSize = last - mid;				// last - (mid + 1) + 1
	int* rightArr = new int[rightSize];

	for (int i = 0; i < leftSize; ++i)
		leftArr[i] = arr[first + i];
	for (int i = 0; i < rightSize; ++i)
		rightArr[i] = arr[mid + 1 + i];

	int leftIndex = 0;
	int rightIndex = 0;

	int i = first;
	while (leftIndex < leftSize && rightIndex < rightSize) {
		if (order(leftArr[leftIndex], rightArr[rightIndex]))
			arr[i++] = leftArr[leftIndex++];
		else
			arr[i++] = rightArr[rightIndex++];
	}

	while (leftIndex < leftSize)
		arr[i++] = leftArr[leftIndex++];

	while (rightIndex < rightSize)
		arr[i++] = rightArr[rightIndex++];

	delete[] leftArr;
	delete[] rightArr;
}

void MergeSort(int* arr, int first, int last, bool(*order)(int, int)) {
	if (first == last)
		return;
	int mid = first + (last - first) / 2;
	MergeSort(arr, first, mid, order);
	MergeSort(arr, mid + 1, last, order);
	Merge(arr, first, mid, last, order);
}

int Partition(int* arr, int first, int last, bool(*order)(int, int)) {
	int mid = first + (last - first) / 2;

	// Sort the first, mid and last elements to select a pivot in median-of-three pivot selection strategy
	if (arr[first] > arr[mid])
		Swap(arr[first], arr[mid]);
	if (arr[mid] > arr[last])
		Swap(arr[mid], arr[last]);
	if (arr[first] > arr[mid])
		Swap(arr[first], arr[mid]);

	// Keep the pivot on the right to before partitioning
	Swap(arr[mid], arr[last]);

	// Partition [with another pivot selection strategy]
	//int slowIndex = first;
	//int fastIndex = first /*last - 2*/;
	//while (fastIndex <= last - 1) {
	//	if (order(arr[fastIndex], arr[last]))
	//		Swap(arr[fastIndex], arr[slowIndex++]);
	//	++fastIndex;
	//}

	// Partition
	int leftIndex = first;
	int rightIndex = last - 1;
	while (true) {
		while (order(arr[leftIndex], arr[last]))
			++leftIndex;
		while (order(arr[last], arr[rightIndex]))
			--rightIndex;
		if (leftIndex < rightIndex)
			Swap(arr[leftIndex++], arr[rightIndex--]);
		else
			break;
	}

	// Return back the pivot and return its index
	Swap(arr[last], arr[leftIndex]);
	return leftIndex;
}

void QuickSort(int* arr, int first, int last, bool(*order)(int, int)) {
	if (first >= last)
		return;
	int pivotIndex = Partition(arr, first, last, order);
	QuickSort(arr, first, pivotIndex - 1, order);
	QuickSort(arr, pivotIndex + 1, last, order);
}
