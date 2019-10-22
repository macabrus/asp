#include <iostream>
#include <algorithm>
#include <ctime>
#include "../util.h"

using namespace std;

int* getSquaredArr(int* arr, int size) {
	for(int i = 0; i < size; i++)
		*(arr + i) = *(arr + i) * *(arr + i);
	random_shuffle(arr, arr + size);
	return arr;
}


int main () {
	srand(time(0));
	int n;
	cin >> n;
	int* arr = new int[n];
	for(int i = 0; i < n; i++)
		cin >> *(arr + i);
	printArr(arr, n);
	printArr(getSquaredArr(arr, n), n);
}
