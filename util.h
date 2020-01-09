#ifndef UTIL_H
#define UTIL_H

# include <iostream>
# include <queue>
# include <set>
# include <stack>
# include <fstream>
# include <iostream>
# include <list>
# include <map>
# include <string>

using namespace std;


template <typename T> class Point {
	public:
		T x;
		T y;
		Point() : x(0), y(0) {}
		Point(T x, T y) : x(x), y(y) {}
		friend ostream &operator << (ostream& left, const Point& right) {
			left << "(" << right.x << ", " << right.y << ")";
			return left;
		}
};

template <typename T>
void printArray(const T arr [], const int size) {
	cout << "[ ";
	for ( int i = 0; i < size; i++ ) {
		cout << arr[i] << ((size != i + 1) ? ", " : " ");
	}
	cout << "]\n";
}

template <typename T>
void printVector(const vector<T>& vec) {
	cout << "[ ";
	int i = 0;
	for (T e : vec) {
		cout << e << ((vec.size() != i + 1) ? ", " : " ");
		i++;
	}
	cout << "]\n";
}

template <typename T>
void printList(const list<T>& l) {
	cout << "[ ";
	int i = 0;
	for (T e : l) {
		cout << e << ((l.size() != i + 1) ? ", " : " ");
		i++;
	}
	cout << "]\n";
}

template <typename K, typename V>
void printMap(const map<K,V>& m) {
	cout << "{ ";
	int i = 0;
	for (auto e : m) {
		cout << e.first << " : " << e.second << ((m.size() != i + 1) ? ", " : " ");
		i++;
	}
	cout << "}\n";
}

template <typename T>
void printSet(const set<T>& s) {
	cout << "{ ";
	int i = 0;
	for (T e : s) {
		cout << e << ((s.size() != i + 1) ? ", " : " ");
		i++;
	}
	cout << "}\n";
}

#endif
