#include <iostream>
#include <string>
#include "BasicFunctions.h"
using namespace std;

int main() {
	string str[5];
	ReadArray(str, 5);
	Alphabetize(str, 5);
	cout << endl;
	PrintArray(str, 5);
	
	return 0;
}