#include <iostream>
#include <sstream>
#include "../util.h"

using namespace std;

template<class T>
struct cvor {
    cvor() {cout << "Gen " << toString() << endl;}
    cvor(T dat) : dat(dat) {cout << "Gen " << toString() << endl;}
    ~cvor() {
        delete nxt;
        cout << "Dest " << toString() << endl;
    }
    T dat;
    cvor* nxt = nullptr;
    string toString() {
        stringstream ss;
        ss << "( Address: " << this << ", " << dat << ", " << nxt << " )";
        return ss.str();
    }
};

template <class T>
class List {

    int size = 0;
    cvor<T>* head = new cvor<T>();

public:

    bool upis (T element) {
        cvor<T>* novi = new cvor<T>(element);
        if(novi == nullptr) return false;
        cvor<T>* iter = head->nxt;
        cvor<T>* prev = head;
        while( iter != nullptr && iter->dat < element) {
            prev = iter;
            iter = iter->nxt;
        }
        novi->nxt = iter;
        prev->nxt = novi;
        size++;
        return true;
    }

    void ispis() {
        cvor<T>* iter = head->nxt;
        for ( int i = 0; i < size; i++ ) {
             cout << iter->toString() << " ";
             iter = head->nxt;
        }
        cout << endl;
    }
    
};

int main () {
    List<int> l = List<int>();
    l.upis(3);
    l.upis(5);
    l.upis(1);
    l.upis(4);
    l.ispis();
}
