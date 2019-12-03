#include <iostream>
#include "../util.h"
#include <algorithm>
#include<sstream>

using namespace std;

struct zapis {
    zapis(int sifra, string naziv) : sifra(sifra), naziv(naziv) {}
    int sifra;
    string naziv;
    bool operator > (zapis& z) {return sifra > z.sifra;}
    string toString() {
        std::stringstream ss;
        ss << "(" << sifra << ", " << naziv << ")";
        return ss.str();
    }
};

ostream& operator << (ostream& os, zapis& z) {
    os << z.toString();
    return os;
}

void obicanBubbleSort (zapis A[], int n, char smjer) {
    bool not_all = true;
    while (not_all) {
        not_all = false;
        for ( int i = 0; i < n-1; i++ ) {
            if (A[i] > A[i + 1]) {
                zapis tmp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = tmp;
                not_all = true;
            }
        }
    }
    if (smjer) reverse(A, &A[n]);
}

int main () {
    zapis arr[4] = {{4,"a"},{3,"b"},{2,"c"},{1,"d"}};
    printArr(arr,4);
    obicanBubbleSort(arr,4,1);
    printArr(arr,4);
}
