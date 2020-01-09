#include <iostream>
#include <ctime>
#include <random>
#include "../util.h"

using namespace std;

struct Element {
	Element(int val) : val(val) {}
	int val;
	Element* prev;
};

class Stog {
	
	Element* top;
	int size;
	int cap;

	public:

	Stog(int cap) : cap(cap), size(0) {}

	~Stog() {
		while ( top != nullptr ) {
			Element* tmp = top->prev;
			delete top;
			top = tmp;
		}
	}

	bool add(int num) {
		if ( size >= cap ) {
			return false;
		}
		size++;
		Element* tmp = top;
		top = new (nothrow) Element(num);
		if ( top == nullptr ) {
			cout << "Nema mjesta u memoriji!";
			top = tmp;
			return false;
		}
		top->prev = tmp;
		return true;
	}

	bool pop(int* dest) {
		if( size <= 0 ) {
			return false;
		}
		size--;
		Element* tmp = top;
		*dest = tmp->val;
		top = top->prev;
		delete tmp;
		return true;
	}
};

int main () {
	srand(time(NULL));
	Stog s(100);
	int min = 0, max = 10;
	for( int i = 0; i < 101; i++ ) {
		int num = min + (rand() % static_cast<int>(max - min + 1));
		cout << "Dodajem element " << num << " na stog.\n";
		bool success = s.add(num);
		cout << (success ? "Element je uspješno dodan." : "Stog je popunjen!") << "\n";
	}
	for (int i = 0; i < 101; i++) {
		int num;
		bool success;
		success = s.pop(&num);
		cout << "Makivam " << num << " sa stoga.\n";
		cout << ( success ? "Uspješno uklanjanje." : "Stog je prazan!" ) << "\n";
	}

}
