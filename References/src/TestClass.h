/*
 * TestClass.h
 *
 *  Created on: 21.02.2016
 *      Author: John
 */
#include <string>

#ifndef TESTCLASS_H_
#define TESTCLASS_H_

using namespace std;

class TestClass {
	private:
	static string myString;

public:
	TestClass();
	virtual ~TestClass();
	int& SomeFunction(int a);
	void printString();


};


#endif /* TESTCLASS_H_ */
