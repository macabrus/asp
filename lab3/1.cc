# include <iostream>

using namespace std;

struct Red {
	
	double* arr;
	int head;
	int tail;
	int size;
	
	Red(int size) : size(size) {
		arr = new double[size];
		head = -1;
		tail = 0;
	}
	
	~Red() {
		delete[] arr;
	}

	bool dodaj (double broj) {
		if (tail == size) {
			return false;
		}
		*(arr + tail++) = broj;
		return true;
	}

	bool skini (double* broj) {
		if (head == size - 1 || head + 1 == tail) {
			return false;
		}
		*broj = *(arr + (++head));
		return true;
	}
};

int main() {
	Red r(10);
	double num;
	while (cin >> num) {
		r.dodaj(num);
	}
	while (r.skini(&num)) {
		cout << num << " ";
	}
	cout << endl;
}
