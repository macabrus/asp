#include <iostream>
#include "../util.h"
#include <cstring>
#include <algorithm>

using namespace std;

struct Osoba {
    Osoba(string ime, int dob) : ime(ime), dob(dob) {}
    string ime;
    int dob;
    bool operator < ( Osoba& o ) {
        if (dob > o.dob) return false;
        if (dob < o.dob) return true;
        if (ime.compare(o.ime) < 0) return true;
        return false;
    }
};

std::ostream& operator << (std::ostream& os, Osoba& o) {
    os << "( " << o.ime << ", " << o.dob << " )";
    return os;
}

template <typename T>
void insertionSort (T A[], int n, char smjer) {
    for ( int i = 1; i < n; i++ ) {
        int j = i - 1;
        while( j >= 0 && A[i] < A[j]) {
            j--;
        }
        cout << i << " " << j << endl;
        T tmp = A[i];
        if (i - j - 1 != 0) {
            cout << &A[j+2] - &A[j+1] << endl;
            memmove( &A[j + 2], &A[j + 1], ( i - j - 1) * sizeof(T) );
        }
        A[j + 1] = tmp;
    }
    if (smjer) reverse(A, &A[n]);
}

int main () {
    cout << sizeof(Osoba);
    Osoba osobe [3] = {{"MARKO",13},{"IVAN",13},{"Derek",24}};
    //Osoba osobe [10] = {{"Ivo",17},{"Marko",34},{"Ivan",11},{"Derek",24},{"Smith",54},{"Jack",32},{"Penny",99},{"Idiot",24},{"Prick",24},{"Debil",12}};
    printArr(osobe,3);
    insertionSort(osobe,3,0);
    printArr(osobe,3);
}
