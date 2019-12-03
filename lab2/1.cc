#include <iostream>
#include <sstream>
#include "../util.h"

using namespace std;

struct Zapis {
    
    Zapis(int broj, string mjesto) : broj(broj), mjesto(mjesto) {};
    
    int broj;
    string mjesto;
    
    bool operator < (Zapis& z2) {
        return broj < z2.broj;
    }
    
    bool operator > (Zapis& z2) {
        return broj > z2.broj;
    }

    string toString() {
        std::stringstream ss;
        ss << "Zapis ( Broj: " << broj << ", " << "Mjesto: " << mjesto;
        return ss.str();
    }
};

std::ostream& operator << (std::ostream& os, Zapis& z) {
    os << z.toString();
    return os;
}

void insertionSort (Zapis A[], int n, char smjer) {
    for ( int i = 1; i < n; i++ ) {
        int j = i;
        while( --j > 0) { 
            if ( A[i] > A[j] ) {
                break;
            }
        }
        Zapis tmp = A[i];
        memmove( &A[j +  1], &A[j], ( i - j ) * sizeof(Zapis) );
        A[j] = tmp;
    }
}

int main () {
    Zapis arr [5] = {{5,"a"},{3,"b"},{3,"c"},{3,"d"},{3,"e"}};
    printArr(arr,5);
    insertionSort(arr, 5, 0);
    printArr(arr,5);
}
