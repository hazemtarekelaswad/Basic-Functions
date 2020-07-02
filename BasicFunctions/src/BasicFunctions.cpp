#include "BasicFunctions.h"
#include <iostream>
using namespace std;

bool isPrime(int number) {

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