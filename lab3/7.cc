#include <iostream>
#include <sstream>
#include "../util.h"

using namespace std;

template <class T>
struct Cvor {
	T data;
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
	Cvor* prt;
	Cvor* lch;
	Cvor* rch;
	int which(T data) {
		if ( lch != nullptr && lch->data == data)
			return 0;
		if (rch != nullptr && rch->data == data)
			return 1;
		return -1;
	}
};

template <class T>
ostream& operator << (ostream& os, Cvor<T>& c) {
	os << "Cvor(" << c.data << ")";
	return os;
}

template <class T>
class BinarnoStablo {
	
	Cvor<T>* root = nullptr;
	
	public:
	
	bool add(T data) {
		Cvor<T>* c = new Cvor<T>(data);
		if(root == nullptr) {
			root = c;
			return true;
		}
		Cvor<T>* tmpRoot = root;
		while (true) {
			if(data == tmpRoot->data) {
				delete c;
				return false;
			}
			if(data < tmpRoot->data){
				if (tmpRoot->lch == nullptr) {
					tmpRoot->lch = c;
					break;
				}
				tmpRoot = tmpRoot->lch;
				continue;
			}
			if(data > tmpRoot->data) {
				if ( tmpRoot->rch == nullptr ) {
					tmpRoot->rch = c;
					break;
				}
				tmpRoot = tmpRoot->rch;
			}
		}
		c->prt = tmpRoot;
		return true;
	}

	bool pop(T data) {
		Cvor<T>* tmpRoot = root;
		if(root == nullptr) {
			return false; // tree empty
		}
		while ( tmpRoot->data != data &&
				(tmpRoot->lch != nullptr ||
				 tmpRoot->rch != nullptr) ) {
			tmpRoot = (tmpRoot->data > data) ? tmpRoot->lch : tmpRoot->rch;
		}
		// not found
		if ( tmpRoot->data != data ) {
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
		Cvor<T>* tmp = minSubnode(tmpRoot);
		cout << "GOT HERE";
		replaceSubnode(tmpRoot, tmp);
		return true;
	}

	// vraca cvor s najmanjom vrijednosti u podstablu
	Cvor<T>* minSubnode(Cvor<T>* cvor) {
		while(cvor->lch != nullptr) {
			cvor = cvor->lch;
		}
		return cvor;
	}

	// brise cvor iz stabla
	void deleteSubnode(Cvor<T>* cvor) {
		if (cvor != nullptr && cvor->prt != nullptr) {
			if (cvor->prt->which(cvor->data) == 0) {
				cvor->prt->lch = nullptr;
			}
			else if (cvor->prt->which(cvor->data) == 1) {
				cvor->prt->rch = nullptr;
			}
			delete cvor;
		}
	}
	// replaces first node with second node by replacing
	// all refs inside them
	void replaceSubnode(Cvor<T>* c1, Cvor<T>* c2) {
		if ( c1->prt != nullptr ) {
			if (c1->prt->which(c1->data) == 0) {
				c1->prt->lch = c2;
			}
			else if (c1->prt->which(c1->data) == 1) {
				c1->prt->rch = c2;
			}
		}
		c2->lch = c1->lch;
		c2->rch = c1->rch;
		if ( c1->rch != nullptr ) {
			c1->rch->prt = c2;
		}
		if (c1->lch != nullptr ) {
			c1->lch->prt = c2;
		}
		delete c1;
	}

	void print(const std::string& prefix, const Cvor<T>* node, bool isLeft) {
		if( node != nullptr ) {
			std::cout << prefix;
			std::cout << (isLeft ? "├─" : "└─" );
			std::cout << node->data << std::endl;
			print( prefix + (isLeft ? "│ " : "  "), node->lch, true);
			print( prefix + (isLeft ? "│ " : "  "), node->rch, false);
		}
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
	bs.print();
}
