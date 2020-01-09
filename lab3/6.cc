#include <iostream>
#include <ctime>
#include <random>
#include "../util.h"

using namespace std;

class Stog {

	int* mem;
	int size;
	int cap;

	public:

	Stog(int cap) : cap(cap), size(0) {
		mem = new int[cap];
	}

	~Stog() {
		delete[] mem;
	}

	bool add(int num) {
		if ( size >= cap ) {
			return false;
		}
		*(mem + size++) = num;
		return true;
	}

	int pop(int* dest) {
		if( size <= 0 ) {
			return false;
		}
		*dest = *(mem + --size);
		return true;
	}

	void print() {
		for( int i = 0; i < size; i++ ) {
			cout << *(mem + i) << " | ";
		}
		cout << "\n";
	}
};

int main () {
	srand(time(NULL));
	Stog s(10);
	int min = 0, max = 10;
	for( int i = 0; i < 11; i++ ) {
		int num = min + (rand() % static_cast<int>(max - min + 1));
		cout << "Dodajem element " << num << " na stog.\n";
		bool success = s.add(num);
		cout << (success ? "Element je uspješno dodan." : "Stog je popunjen!") << "\n";
		s.print();
	}
	for( int i = 0; i < 11; i++ ) {
		int num;
		bool success = s.pop(&num);
		cout << "Brišem element " << num << " sa stoga.\n";
		cout << (success ? "Element je uspješno obrisan." : "Stog je prazan!") << "\n";
		s.print();

	}
}
