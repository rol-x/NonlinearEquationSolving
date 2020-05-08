/// Karol Latos & Kamila Kwieciñska
#include <utility>
#include <iomanip>
#include "Function.h"

constexpr auto accuracy = 0.000001;
int numberOfIterations = 0;

// Start at [-10, -1] / [1, 10], lower a and b until stop condition.
pair<double, double> chooseStartingPoints(Function f)
{
	pair<double, double> ab;
	ab.first = 1;
	ab.second = 10;

	while (f.of(ab.first) * f.doublePrimeOf(ab.first) <= 0)
		ab.first += (ab.second - ab.first) / 100.0;
	while (f.of(ab.second) * f.doublePrimeOf(ab.second) <= 0)
		ab.second -= (ab.second - ab.first) / 100.0;

	return ab;
}

// Calculate c use it as new boundary or return it when accuracy is obtained.
double approximateRootRegulaFalsi(pair<double, double> ab, Function f)
{
	numberOfIterations++;

	double c = (f.of(ab.first)*ab.second - f.of(ab.second)*ab.first) / (f.of(ab.first) - f.of(ab.second));
	cout << "c: " << c << "\tin interval (" << ab.first << ", " << ab.second << ")" << endl;

	if (abs(f.of(c)) <= accuracy)
		return c;
	else if (f.of(ab.first) * f.of(c) < 0)
		ab.second = c;
	else
		ab.first = c;

	return approximateRootRegulaFalsi(ab, f);
}

// Start at 1, oscillate outwards until stop condition.
double chooseStartingPoint(Function f)
{
	double x = 1;

	while (f.of(x) * f.doublePrimeOf(x) <= 0)
		x *= -1.1;

	return x;
}

// Calculate new approximation until accuracy is obtained.
double approximateRootNewton(double x, Function f)
{
	cout << "x: " << x << endl;
	numberOfIterations++;

	x -= f.of(x) / f.primeOf(x);

	if (abs(f.of(x)) <= accuracy)
		return x;

	return approximateRootNewton(x, f);
}

int main()
{
	// The output precision is set to 6 digits after the decimal place.
	cout << setprecision(6) << fixed;
	
	// Class Function holds needed functions f_i(x) with their derivatives.
	Function f(1);

	// Regula falsi.
	cout << "Regula Falsi" << endl;
	pair<double, double> ab = chooseStartingPoints(f);
	double root = approximateRootRegulaFalsi(ab, f);
	cout << endl << "The approximated root of f: " << root << endl;
	cout << "Numer of iterations: " << numberOfIterations << endl << endl;
	system("pause");
	cout << endl;

	// Resetting global varaibles.
	numberOfIterations = 0;

	// Newton method.
	cout << "Newthon method" << endl;
	double x = chooseStartingPoint(f);
	root = approximateRootNewton(x, f);
	cout << endl << "The approximated root of f: " << root << endl;
	cout << "Numer of iterations: " << numberOfIterations << endl << endl;
	system("pause");
	cout << endl;

	return 0;
}