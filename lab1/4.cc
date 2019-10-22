#include <iostream>
#include <cmath>
#include "../util.h"

using namespace std;

double exp(int i, double x, int n, int* fakt, double* xpot ) {
	if ( i > n ) return 0;
	*xpot = (*xpot == 0) ? x : (x * (*xpot));
	*fakt = (i == 0) ? 1 : (i * (*fakt));
	return (*xpot) / (*fakt) + exp(i + 1, x, n, fakt, xpot);
}

//
// zadatak se ne može riješiti u O(n)
// ako ne koristimo dodatni parametar
// za informaciju o trenutnoj vrijednosti
// kojom množimo međurezultat faktorijela
//

int main () {
	int n;
	int x;
	cin >> n >> x;
	double* arr = (double*) malloc(sizeof(double) * n);
	for (int i = 0; i < n; i++) {
		int* fakt = new int(1);
		double* xpot = new double(1);
		*(arr + i) = exp(0, 1, i, fakt, xpot);
		delete fakt, xpot;
	}
	printArr(arr, n);
	free(arr);
}
