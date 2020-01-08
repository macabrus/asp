# include <iostream>

using namespace std;

struct Cvor {
	double val = 0;
	Cvor* nxt = nullptr;
	Cvor(double val) : val(val), nxt(nxt) {}
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
	Red r;
	double broj;
	while (cin >> broj) {
		r.dodaj(broj);
	}
	while(r.skini(&broj)) {
		cout << broj << " ";
	}
}
