#include <iostream>
#include "../util.h"
#include <algorithm>

using namespace std;

void selection2Sort (int A[], int n, char smjer) {
    for ( int i = 0 ; i < n/2 ; i++ ) {
        int mx = A[i], mxi = i;
        int mn = A[i + 1], mni = i + 1;
        for ( int j = i ; j < n - i ; j++ ) {
            if (A[j] > mx) {
                mx = A[j];
                mxi = j;
            }
            if (A[j] < mn) {
                mn = A[j];
                mni = j;
            }
        }
        int lower = min(mxi,mni);
        int upper = max(mxi,mni);
        memmove( &A[i+1], &A[i], (lower - i ) * sizeof(int) );
        memmove( &A[upper], &A[upper + 1], (n - upper - i - 1 ) * sizeof(int) );
        A[i] = mn; A[n - i - 1] = mx;
        printArr(A,n);
    }
    if (smjer) reverse(A, &A[n - 1]);
}

int main () {
    int arr[3] = {4,1,3};
    printArr(arr,3);
    selection2Sort(arr,3,0);
    printArr(arr,3);
}
