#include <iostream>
#include "../util.h"
#include <cstring>
#include <algorithm>

using namespace std;

struct Osoba {
    Osoba(string ime, int dob) : ime(ime), dob(dob) {}
    string ime;
    int dob;
    bool operator > ( Osoba& o ) {
        if (dob > o.dob) return true;
        if (dob < o.dob) return false;
        if (ime.compare(o.ime) > 0) return true;
        return false;
    }
}

ostream& operator << (ostream& os, Osoba& o) {
    os << "( " << o.ime << ", " << o.dob << " )";
    return os;
}

template <class T>
void insertionSort (T A[], int n, char smjer) {
    for ( int i = 1; i < n; i++ ) {
        int j = i;
        while( --j > 0) { 
            if ( A[i] > A[j] ) {
                break;
            }
        }
        T tmp = A[i];
        memmove( &A[j +  1], &A[j], ( i - j ) * sizeof(T) );
        A[j] = tmp;
    }
    if (smjer) reverse(A, &A[n]);
}


int main () {
    Osoba osobe [10] = {{"Ivo",17},{"Marko",34},{"Ivan",11},{"Derek",24},{"Smith",54},{"Jack",32},{"Penny",99},{"Idiot",24},{"Prick",24},{"Debil",12}};
    printArr(osobe,10);
    insertionSort(osobe,10,0);
    printArr(osobe,10);
}
