#include <iostream>
#include <string>
#include "BasicFunctions.h"
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {

	int arr[] = {2, 0, 1, 3, 1, 5, 4 };
	PrintArray(arr, 7);
	//InsertionSort(arr, 6, ascending);
	InsertionSort(arr, 7, descending);
	PrintArray(arr, 7);
	
	
	return 0;
}