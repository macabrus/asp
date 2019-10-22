#include <iostream>
#include <cmath>
#include "../util.h"

using namespace std;

void f (int polje[], int n, int m) {
	*(polje + n) = pow(m, n);
	if(n > -1)
		f(polje, n - 1, m);
}

int main () {
	int n, m; cin >> n >> m;
	int* arr = new int[n];
	
	f(arr, n, m);

	printArr(arr, n);
	
	delete [] arr;
}
