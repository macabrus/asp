#include <iostream>
#include <cmath>
using namespace std;

int zbrojiKvadrate (int* polje, int n) {
    if ( n < 0) return 0;
    float korijen = sqrt(*(polje + n));
    if (trunc(korijen) == korijen) return *(polje + n) + zbrojiKvadrate(polje, n - 1);
    else return zbrojiKvadrate(polje, n - 1);
}

int main() {
    int n;
    cin >> n;
    int* arr = (int*) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i ++)
        cin >> (*(arr + i));
    cout << zbrojiKvadrate(arr, n);
    free(arr);
}
