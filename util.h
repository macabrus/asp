#ifndef UTIL_H
#define UTIL_H

#include <iostream>

using namespace std;

template <class T>
void printArr(T* arr, int size) {
	cout << "[ ";
	for (int i = 0; i < size; i++ ) {
		cout << *(arr + i) << ((i+1==size)?" ]\n":", ");
	}
}

template <class T>
void inputArr(T* arr, int size) {
	for (int i = 0; i < size; i++) {
		cin >> *(arr + i);
	}
}

#endif
