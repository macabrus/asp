#include <iostream>
#include <sstream>
#include <algorithm>
#include "../util.h"
#include <cstring>

using namespace std;

struct Zapis {
    
    Zapis(int broj, string mjesto) : broj(broj), mjesto(mjesto) {};
    
    int broj;
    string mjesto;
    
    bool operator < (Zapis& z2) {
        return broj < z2.broj;
    }
    
    bool operator >= (Zapis& z2) {
        return broj >= z2.broj;
    }

    string toString() {
        std::stringstream ss;
        ss << "(" << broj << ", " << mjesto << ")";
        return ss.str();
    }
};

std::ostream& operator << (std::ostream& os, Zapis& z) {
    os << z.toString();
    return os;
}

void insertionSort (Zapis A[], int n, char smjer) {
    for ( int i = 1; i < n; i++ ) {
        int j = i - 1;
        while( j >= 0 && A[i] < A[j]) {
            j--;
        }
        cout << i << " " << j << endl;
        Zapis tmp = A[i];
        if (i - j - 1 != 0) {
            memmove( &A[j + 2], &A[j + 1], ( i - j - 1) * sizeof(Zapis) );
        }
        A[j + 1] = tmp;
    }
    if (smjer) reverse(A, &A[n]);
}

int main () {
    Zapis arr [4] = {{5,"a"},{3,"b"}, {1,"c"},{4,"d"}};
    printArr(arr,4);
    insertionSort(arr, 4, 0);
    printArr(arr,4);
}
