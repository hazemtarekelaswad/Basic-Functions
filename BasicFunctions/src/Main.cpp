#include <iostream>
#include <string>
#include "BasicFunctions.h"
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {

	int arr[] = {2, 0, 1, 3, 1, 5, 4, 4, 5, 4, 23, 45, 78, 100, 32, 12, 12, 0, 3, 49 };
	PrintArray(arr, 20);
	//InsertionSort(arr, 7, descending);
	ShellSort(arr, 20, descending);
	PrintArray(arr, 20);
	
	
	return 0;
}