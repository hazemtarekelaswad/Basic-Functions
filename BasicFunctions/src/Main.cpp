#include <iostream>
#include <string>
#include "BasicFunctions.h"
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {

	int arr[] = {2, 0, 1, 3, 1, 4, 5 };
	PrintArray(arr, 6);
	InsertionSort(arr, 6, ascending);
	PrintArray(arr, 6);
	
	
	return 0;
}