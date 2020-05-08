#pragma once
#include <iostream>
#include <math.h>

constexpr auto e = 2.71828182846;

using namespace std;

class Function
{
public:
	// Constructor.
	Function(int function);

	// Returns the value of f(x).
	double of(double x);

	// Returns the value of f'(x).
	double primeOf(double x);

	// Returns the value of f''(x).
	double doublePrimeOf(double x);

	// Destructor.
	~Function();

private:
	// Function choosing variable; one instance = one function.
	int _function;
};

