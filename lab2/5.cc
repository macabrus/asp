#include "4.cc"
#include "../util.h"

int main () {
    string s1 = "dcba";
    string s2 = "dcba";
    string Rez[8];
    spojiPolja(s1, s2, Rez, 5, 5);
    printArr(Rez, 10);
}
