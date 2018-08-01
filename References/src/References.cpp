//============================================================================
// Name        : References.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "TestClass.h"
using namespace std;

int main() {
	TestClass test;
	int& number = test.SomeFunction(1);

	if (number == NULL)
	{
		cout << "number is null" << endl;
	}

	cout << number << endl;

	test.printString();
}
