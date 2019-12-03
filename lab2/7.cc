#include <iostream>
#include "../util.h"

using namespace std;

struct cvor {
	cvor(string data) : data(data) {}
	string data;
	cvor* prev;
	cvor* next;
};

template <class T>
class Lista {
	
	cvor* head = nullptr; 

public:

	~Lista() {
	    delete head;
	}
	
	bool upis(string element) {
	    if (head == nullptr) {
		head = new (nothrow) cvor(element);
		if (head == nullptr) return false;
		return true;
	    }
	    cvor* tmp = head;
	    while(tmp->next != nullptr) {
		tmp = tmp->next;
	    }
	    tmp->next = new (nothrow) cvor(element);
	    if(tmp->next == nullptr) return false;
	    return true;
	}

	void ispis() {
	    cvor* iter = head;
	    while (iter != nullptr) {
		cout << iter->data << " ";
		iter = iter->next;
	    }
	    cout << endl;
	}
 
};

int main () {
    Lista<string> l = Lista<string>();
    l.upis("a");
    l.upis("b");
    l.upis("c");
    l.ispis();
}
