#include "Function.h"

// Constructor.
Function::Function(int function)
{
	_function = function;
}

// Returns the value of f(x).
// f(x) = (x - 1)^3 + e^sin(x^2) - 1
double Function::of(double x)
{
	switch (_function)
	{
	case 1:
		return pow(x, 4) - 625;
		break;
	case 2:
		return pow(x, 4) + 13 * pow(x, 3) + 16 * pow(x, 2) - 228 * x - 432;
		break;
	case 3:
		return pow(x, 5) - 23 * pow(x, 4) + 177 * pow(x, 3) - 433 * pow(x, 2) - 514 * x - 2520;
		break;
	default:
		return 0;
		break;
	}
}

// Returns the value of f'(x).
// f'(x) = 3(x - 1)^2 + e^sin(x^2) * cos(x^2) * 2x
double Function::primeOf(double x)
{
	switch (_function)
	{
	case 1:
		return 4*pow(x, 3);
		break;
	case 2:
		return 4*pow(x, 3) + 39 * pow(x, 2) + 32 * x - 228;
		break;
	case 3:
		return 5*pow(x, 4) - 92 * pow(x, 3) + 531 * pow(x, 2) - 866 * x - 514;
		break;
	default:
		return 0;
		break;
	}
}

// Returns the value of f''(x).
// f''(x) = 6(x - 1) + 2*e^sin(x^2)*cos(x^2) + 4 e^sin(x^2) x^2 cos^2(x^2) - 4 e^sin(x^2) x^2 sin(x^2)
double Function::doublePrimeOf(double x)
{
	switch (_function)
	{
	case 1:
		return 12*pow(x, 2);
		break;
	case 2:
		return 12 * pow(x, 2) + 78 * x + 32;
		break;
	case 3:
		return 20 * pow(x, 3) - 276 * pow(x, 2) + 1062 * x - 866;
		break;
	default:
		return 0;
		break;
	}
}

// Destructor.
Function::~Function()
{ }