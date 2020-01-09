# include <iostream>
# include <random>
# include <ctime>
# include "../util.h"
using namespace std;

struct Cvor {
	int val = 0; // piše u zadatku int makar to nema smisla
	Cvor* nxt = nullptr;
	Cvor(double val) : val(val) {}
	~Cvor() {
		if (nxt != nullptr) {
			delete nxt;
		}
	}
};

struct Red {
	
	Cvor* ulaz;
	Cvor* izlaz;
	
	Red() {
		izlaz = new Cvor(0);
		ulaz = izlaz;
	}
	
	~Red() {
		delete izlaz; // briše rekurzivno
	}

	bool dodaj(double broj) {
		ulaz->val = broj;
		ulaz->nxt = new (nothrow) Cvor(0);
		ulaz = ulaz->nxt;
		if(ulaz == nullptr) {
			return false;
		}
		return true;
	}

	bool poljeURed(const int polje[], const int n) {
		for (int i = n - 1; i >= 0; i--) {
			if (!dodaj(polje[i])) return false;
		}
		return true;
	}

	bool skini(double* broj) {
		if (ulaz == izlaz || izlaz == nullptr) {
			return false;
		}
		Cvor* tmp = izlaz->nxt;
		izlaz->nxt = nullptr;
		*broj = izlaz->val;
		delete izlaz;
		izlaz = tmp;
		return true;
	}
};


int main() {
	srand(time(NULL));
	Red r;
	double broj;
	while (cin >> broj) {
		r.dodaj(broj);
	};
	int arr [10];
	int min = 0, max = 10;
	for(int i = 0; i < 10; i++) {
		arr[i] = min + (rand() % static_cast<int>(max - min + 1));
	}
	printArray(arr, 10);
	r.poljeURed(arr, 10);
	while(r.skini(&broj)) {
		cout << broj << " ";
	}
}
