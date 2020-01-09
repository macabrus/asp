#include <iostream>
#include "../util.h"

using namespace std;

template <class T>
struct Cvor {
	T data;
	Cvor(int data) : data(data), prt(nullptr), lch(nullptr), rch(nullptr) {}
	Cvor* prt;
	Cvor* lch;
	Cvor* rch;
};

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
			if(c->data == tmpRoot->data) {
				return false;
			}
			if(c->data < tmpRoot->data){
				if (tmpRoot->lch == nullptr) {
					tmpRoot->lch = c;
					break;
				}
				tmpRoot = tmpRoot->lch;
				continue;
			}
			if(c->data > tmpRoot->data) {
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
		while ( tmpRoot->data != data ||
				tmpRoot->lch == nullptr &&
				tmpRoot->rch == nullptr ) {
				if ( tmpRoot == root ) {
					delete tmpRoot;
					root = nullptr;
				}
				if (tmpRoot->prt->rch == data) {
					tmpRoot->prt->rch = nullptr;
				}
				if (tmpRoot->prt->lch == data) {
					tmpRoot->prt->lch = nullptr;
				}
				delete tmpRoot;
			}
			if( tmpRoot->rch == nullptr ) {

			}
		}
	}

	Cvor* minSubnode(Cvor* cvor) {
		while(cvor->lch != nullptr) {
			cvor = cvor->lch;
		}
		return cvor;
	}

	void print(const std::string& prefix, const Cvor<T>* node, bool isLeft) {
		if( node != nullptr ) {
			std::cout << prefix;
			std::cout << (isLeft ? "├──" : "└──" );
			std::cout << node->data << std::endl;
			print( prefix + (isLeft ? "│   " : "    "), node->lch, true);
			print( prefix + (isLeft ? "│   " : "    "), node->rch, false);
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
	bs.print();
}
