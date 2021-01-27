#pragma once

#include <string>

// ========================= Basic Functions ========================= 

void Swap(int& x, int& y);
void Swap(std::string& x, std::string& y);

// ========================= Mathematics ========================= 

bool IsPrime(int number);
int CompareDoubles(double x, double y);	// returns "1" if x > y, "0" if x = y, "-1" if x < y
long long Factorial(int number);
long long ConsecutiveSum(int num);	// Computes the sum of numbers from 1 to the passed argument. e.g. 6 + 5 + 4 + 3 + 2 + 1
long long Fibonacci(int num);
long long GCD(long long x, long long y); //Uses Euclidian's algorithims recursively to compute greatest common divisor of two numbers

// ========================= String Manipulation Functions ========================= 

void Upper(std::string &str);
void Lower(std::string &str);
void Capitalize(std::string &str);
void Alphabetize(std::string *str, int length);	//	modifies each word to lower case letters, then alphabetizes the array
bool IsLower(char letter);


// ========================= Array Manipulation Functions ========================= 

void ReadArray(int* arr, int length);
void ReadArray(std::string* arr, int length);
void PrintArray(int* arr, int length);
void PrintArray(std::string* arr, int length);

int MaxElement(int* arr, int length);
int MaxElement(int* arr, int first, int last);
int MinElement(int* arr, int length);

long long SumArray(int* arr, int n);
long long Multiply(int* arr, int n);

void Reverse(int* arr, int length);
int* Merge(int* arr1, int length1, int* arr2, int length2, int &lengthOut);
int* RemoveDuplicates(int* arr, int lengthIn, int &lengthOut); // two options are provided, to sort the array then remove the duplicated elements or to remove duplicates directly


// ========================= Sorting and Searching Algorithms ========================= 

int BinarySearch(int* arr, int first, int last, int target);

//	you can choose to sort in ascending order or descending order 
//	by passing "ascending" or "descending" as a third parameter

bool ascending(int x, int y);
bool descending(int x, int y);

void SelectionSort(int* arr, int length, bool(*order)(int, int));

void BubbleSort(int* arr, int length, bool(*order)(int, int));	

void InsertionSort(int* arr, int length, bool(*order)(int, int));

void ShellSort(int* arr, int length, bool(*order)(int, int));

void Merge(int* arr, int first, int mid, int last, bool(*order)(int, int));
void MergeSort(int* arr, int first, int last, bool(*order)(int, int));

int Partition(int* arr, int first, int last, bool(*order)(int, int));
void QuickSort(int* arr, int first, int last, bool(*order)(int, int));

void Heapify(int* arr, int length, bool(*order)(int, int));
void HeapSort(int* arr, int length, bool(*order)(int, int));