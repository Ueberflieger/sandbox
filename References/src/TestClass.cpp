/*
 * TestClass.cpp
 *
 *  Created on: 21.02.2016
 *      Author: John
 */

#include "TestClass.h"
#include <string>
#include <iostream>

using namespace std;

string TestClass::myString ("this is a test");

TestClass::TestClass() {
	// TODO Auto-generated constructor stub
}

TestClass::~TestClass() {
	// TODO Auto-generated destructor stub
}

int& TestClass::SomeFunction(int a)
{
	if (a == 1)
	{
		static int i = 12;
		return i;
	}
}

void TestClass::printString()
{
	cout << "myString: "<< myString << endl;
}
