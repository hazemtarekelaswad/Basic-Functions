#pragma once

// Basic Functions

void Swap(int& x, int& y);

// Mathematics

bool isPrime(int number);

// String Basic Manipulation Functions


// Arrays Manipulation Functions

void ReadArray(int* arr, int length);
void PrintArray(int* arr, int length);

int MaxElement(int* arr, int length);
int MinElement(int* arr, int length);

bool ascending(int x, int y);
bool descending(int x, int y);
void BubbleSort(int* arr, int length, bool(*order)(int, int));	/*	you can choose to sort in ascending order or descending order 
																	by passing "ascending" or "descending" as a third parameter	*/






