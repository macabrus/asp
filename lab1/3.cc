#include <iostream>
#include <cmath>
#include "../util.h"

using namespace std;

double pi (int n) {
	if (n <= 0) return 0.;
	return (n % 2 == 0 ? -1. : 1.) * 4. / (2. * n - 1.) + pi(n - 1);
}

int main () {
	int n;
	cin >> n;
	double* arr = (double*) malloc(sizeof(double) * n);	
	for( int i = 1; i <= n; i++ )
		*(arr + i) = pi(i);
	printArr(arr, n);
	free(arr);
}
