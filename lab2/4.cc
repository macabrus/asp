#include <iostream>
#include "../util.h"

using namespace std;

template <class T>
void spojiPolja(T A[], T B[], T Rez[], int n1, int n2) {
    int i,j,k;
    i = j = k = 0;
    while(k < n1 + n2) {
        if (i < n1 && A[i] > B[j]) {
            Rez[k] = A[i];
            i++;
        }
        else if (j < n2) {
            Rez[k] = B[j];
            j++;
        }
        k++;
    }
}


