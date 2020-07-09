#pragma once

#include <string>

// ========================= Basic Functions ========================= 

inline void Swap(int& x, int& y);
inline void Swap(std::string& x, std::string& y);

// ========================= Mathematics ========================= 

bool IsPrime(int number);
int CompareDoubles(double x, double y);	// returns "1" if x > y, "0" if x = y, "-1" if x < y

// ========================= String Manipulation Functions ========================= 

void Upper(std::string &str);
void Lower(std::string &str);
void Capitalize(std::string &str);
void Alphabetize(std::string *str, int length);	//	modifies each word to lower case letters, then alphabetizes the array


// ========================= Array Manipulation Functions ========================= 

void ReadArray(int* arr, int length);
void ReadArray(std::string* arr, int length);
void PrintArray(int* arr, int length);
void PrintArray(std::string* arr, int length);

int MaxElement(int* arr, int length);
int MinElement(int* arr, int length);

bool ascending(int x, int y);
bool descending(int x, int y);
void BubbleSort(int* arr, int length, bool(*order)(int, int));	/*	you can choose to sort in ascending order or descending order 
																	by passing "ascending" or "descending" as a third parameter	*/
void Reverse(int* arr, int length);
int* Merge(int* arr1, int length1, int* arr2, int length2, int &lengthOut);
int* RemoveDuplicates(int* arr, int lengthIn, int &lengthOut); /*	two options are provided, to sort the array then remove the duplicated elements
																	 or to remove duplicates directly */
