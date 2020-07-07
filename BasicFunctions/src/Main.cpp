#include <iostream>
#include <string>
#include "BasicFunctions.h"
using namespace std;

int main() {
	string str;
	cin >> str;

	Capitalize(str);
	cout << str << endl;

	Lower(str);
	cout << str << endl;

	Upper(str);
	cout << str << endl;
	return 0;
}