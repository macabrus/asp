#include <iostream>

using namespace std;

void ispis (float* polje, int n) {
   if (*polje < 0) printf("%.2f ", *polje);
   if (n != 0) ispis(++polje, --n);
}

int main() {
   int n;
   cin >> n;
   float* arr = (float*) malloc(sizeof(float)*n);
   for (int i = 0; i < n; i ++) {
       cin >> (*(arr + i));
   }
   ispis(arr, n);
   free(arr);
}
