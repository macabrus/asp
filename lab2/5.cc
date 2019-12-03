#include "../util.h"
#include "4.cc"

int main () {
    
    int arr1 [5] = {9,8,7,6,5};
    int arr2 [5] = {4,3,2,1,0};
    int Rez1 [10];
    spojiPolja(arr1,arr2,Rez1,5,5);
    printArr(Rez1, 10);

    string s1 = "dcba";
    string s2 = "dcba";
    char Rez2[8];
    spojiPolja((char*)s1.c_str(), (char*)s2.c_str(), Rez2, 4, 4);
    printArr(Rez2, 8);
}
