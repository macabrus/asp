#include <iostream>
#include <cmath>
#include "../util.h"

using namespace std;

int fact(int n) {
	if (n <= 0)
		return 1;
	return n * fact(n - 1);
}

int sgn(int n, int p) {
	return (p % 2 == 0 ) ? n : -n;
}

double f (double z, int k) {
	cout << "Factorial: " << fact(2 * k + 1) << "\n";
	cout << "Power of Z: " << pow(z, 2 * k + 1) << "\n";
	cout << "Sign: " << sgn(1, k) << "\n";
	return sgn(1, k) * pow(z, 2 * k + 1) / fact(2 * k + 1);
}

int main () {
	int n; cin >> n;
	float z = 0.5;
	double* arr = new double[n];
	for (int i = 0; i < n; i++)
		*(arr + i) = f(z, i);
	printArr(arr, n);
	delete [] arr;
}
