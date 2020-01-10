#include <iostream>
#include <sstream>
#include "../util.h"

using namespace std;

template <class T>
struct Cvor {
	Cvor(int data) :
		data(data),
		lch(nullptr),
		rch(nullptr) {
		cout << "Creating " << *this << "\n";
	}
	~Cvor() {
		cout << "Deleting " << *this << "\n";
	}
	T data;
	shared_ptr<Cvor> lch;
	shared_ptr<Cvor> rch;
};

template <class T>
ostream& operator << (ostream& os, Cvor<T>& c) {
	os << "Cvor(" << c.data << ")";
	return os;
}

template <class T>
class BinarnoStablo {
	
	private:

	shared_ptr<Cvor<T>> root = nullptr;
	
	// O(log(n))
	bool add(T data, shared_ptr<Cvor<T>>& n) {
		if(data == n->data) {
			return false;
		}
		if(data < n->data) {
			if(n->lch == nullptr) {
				n->lch = shared_ptr<Cvor<T>>(new Cvor<T>(data));
				return true;
			}
			return add(data, n->lch);
		}
		if (n->rch == nullptr) {
			n->rch = shared_ptr<Cvor<T>>(new Cvor<T>(data));
			return true;
		}
		return add(data, n->rch);
	}
	
	// O(log(n))
	bool pop(T data, shared_ptr<Cvor<T>>& n) {
		cout<<"HERE " <<n->data << "\n";
		if(n) {
			if ( n->data < data ) {
				return pop(data, n->rch);
			}
			else if (n->data > data) {
				return pop(data, n->lch);
			}
			else {
				if (!n->lch) {
					n = n->rch;
				}
				else if (!n->rch) {
					n = n->lch;
				} else {
					shared_ptr<Cvor<T>> prev = nullptr, tmp = n->lch;
					while(tmp->rch) {
						prev = tmp;
						tmp = tmp->rch;
					}
					n->data = tmp->data;
					if(prev) {
						prev->rch = tmp->lch;
					}
					else {
						n->lch = tmp->lch;
					}
					return true;
				}
			}
		}
		return false;
	}

	void print(const std::string& prefix, const shared_ptr<Cvor<T>> node, bool isLeft) {
		if( node != nullptr ) {
			std::cout << prefix;
			std::cout << (isLeft ? "├" : "└" );
			std::cout << node->data << std::endl;
			print( prefix + (isLeft ? "│" : " "), node->lch, true);
			print( prefix + (isLeft ? "│" : " "), node->rch, false);
		}
	}

	public:

	bool insert(T data) {
		if(root == nullptr) {
			root = shared_ptr<Cvor<T>>(new Cvor<T>(data));
			return true;
		}
		return add(data, root);
	}
	// O(log(n))
	bool remove(T data) {
		if(root == nullptr) {
			return false;
		}
		return pop(data, root);
	}

	void print() {
		print("", root, false);
	}

};

int main () {
	BinarnoStablo<int> bs;
	bs.insert(3);
	bs.insert(1);
	bs.insert(4);
	bs.insert(5);
	bs.insert(6);
	bs.insert(2);
	bs.insert(0);
	bs.print();
	bs.remove(3);
	bs.print();
}
