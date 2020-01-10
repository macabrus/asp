#include <iostream>
#include <sstream>
#include "../util.h"

using namespace std;

template <class T>
struct Cvor {
	Cvor(int data) :
		data(data),
		prt(nullptr),
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
	bool add(T data, shared_ptr<Cvor> n) {
		if(data == n->data) {
			return false;
		}
		if(data < n->data) {
			if(n->lch == nullptr) {
				n->lch = new Cvor(data);
				return true;
			}
			return add(data, n->lch);
		}
		if (n->rch == nullptr) {
			n->rch = new Cvor(data);
			return true;
		}
		return add(data, n->rch);
	}
	
	// O(log(n))
	bool pop(T data, shared_ptr<Cvor> n) {
		shared_ptr<Cvor> tmp = parentOf(data);
		// not found
		if ( tmp->data != data ) {
			return false;
		}
		// leaf
		if( tmpRoot->lch == nullptr &&
			tmpRoot->rch == nullptr ) {
			deleteSubnode(tmpRoot);
			return true;
		}
		// single child
		if ( tmpRoot->lch == nullptr ) {
			replaceSubnode(tmpRoot->rch, tmpRoot);
			return true;
		}
		if ( tmpRoot->rch == nullptr ) {
			replaceSubnode(tmpRoot->lch, tmpRoot);
			return true;
		}
		// both children
		Cvor<T>* tmp = minVal(tmpRoot->rch);
		cout << "FOUND MIN SUBNODE " << tmp->data;
		replaceSubnode(tmpRoot, tmp);
		return true;
	}

	// vraca cvor s najmanjom vrijednosti u podstablu
	Cvor<T>* minVal(Cvor<T>* cvor) {
		while(cvor->lch != nullptr) {
			cvor = cvor->lch;
		}
		return cvor;
	}
	
	//returns parent of where data is or where data should go...
	Cvor<T>* parentOf(T data) {
		if(root == nullptr) {
			return nullptr;
		}
		shared_ptr<Cvor> tmp = root;
		while(true) {
			if ((tmp->lch == nullptr && tmp->rch == nullptr)) {
				break;
			}
			if( (tmp->lch != nullptr && tmp->lch->data == data) ||
				(tmp->rch != nullptr && tmp->rch->data == data) ) {
				break;
			}
			tmp = (tmp->data > data) ? tmp->lch : tmp->rch;
		}
		return tmp;
	}

	Cvor<T>* find(T data) {
		shared_ptr<Cvor> tmp = root;
		while(tmp != nullptr && tmp->data != data) {
			tmp = (tmp->data > data) ? tmp->lch : tmp->rch;
		}
		return tmp;
	}

	// replaces first node with second node by replacing
	// all refs inside them

	void print(const std::string& prefix, const Cvor<T>* node, bool isLeft) {
		if( node != nullptr ) {
			std::cout << prefix;
			std::cout << (isLeft ? "├─" : "└─" );
			std::cout << node->data << std::endl;
			print( prefix + (isLeft ? "│ " : "  "), node->lch, true);
			print( prefix + (isLeft ? "│ " : "  "), node->rch, false);
		}
	}

	public:

	bool insert(T data) {
		if(root == nullptr) {
			root = new Cvor(data);
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
	bs.add(3);
	bs.add(1);
	bs.add(4);
	bs.add(5);
	bs.add(6);
	bs.add(2);
	bs.add(0);
	bs.pop(3);
	//bs.print();
}
