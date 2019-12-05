#include <iostream>
#include "../util.h"

using namespace std;

class Vozilo {
    string name;
    int year;
    public:
    Vozilo(string name, int year) : name(name), year(year) {}
    string getName() {return name;}
    int getYear() {return year;}
    void setName(string name) {this->name = name;}
    void setYear(int year) {this->year = year;}
    bool operator < (Vozilo& v) {
        if(name.compare(v.name) < 0) return true;
        if(name.compare(v.name) > 0) return false;
        if(year > v.year) return true;
        return false;
    }
};

template <class T>
void SelectionSort(T A[], int N) {
    for(int i = 0; i < N; i++) {
        Vozilo* min = &A[i];
        for(int j = i + 1; j < N; j++) {
            if (A[j] < *min) {
                min = &A[j];
            }
        }
        Zamijeni(*min, A[i]);
    }
}

void Zamijeni(Vozilo& prvi, Vozilo& drugi){
    Vozilo tmp = prvi;
    prvi = drugi;
    drugi = tmp;
}

ostream& operator << (ostream& os, Vozilo& v) {
    os << "("<<v.getName() << ", " << v.getYear() <<")";
    return os;
}

int main () {
    Vozilo vozila [] = {{"Pauegot",1981}, {"Pauegot",1983}, {"Ranulet",1967}, {"Fait",1972}, {"BWM",1985}, {"Merdesec",1983}};
    printArr(vozila, 6);
    SelectionSort(vozila, 6);
    printArr(vozila, 6);
}
