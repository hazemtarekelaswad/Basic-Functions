#include <iostream>
#include <string>
#include "src/BasicFunctions.h"
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {

	int arr[] = { 2, 0, 1, 3, 1, 5, 4, 4, 5, 4, 23, 45, 78, 100, 32, 12, 12, 0, 3, 49 };
	cout << BinarySearch(arr, 0, 19, 4);
	
	return 0;
}