#include <iostream>
#include <algorithm>
#include "../util.h"

using namespace std;

void Zamijeni(string *prvi, string *drugi) {
    string tmp = *prvi;
    *prvi = *drugi;
    *drugi = tmp;
}

void BubbleSortPoboljsani(string A[], int N, int smjer){
    bool flag = true;
    while(flag) {
        flag = false;
        for (int i = 0; i < N - 1; i++) {
            if (A[i].compare( A[i+1] ) > 0 ){
                Zamijeni(&A[i],&A[i+1]);
                flag = true;
            }
        }
    }
    if (smjer) reverse(A, &A[N]);
}

int main () {
    string arr[] = {"Ivo", "Marko", "Juraj", "Pero"};
    printArr(arr,4);
    BubbleSortPoboljsani(arr,4,1);
    printArr(arr,4);
}


