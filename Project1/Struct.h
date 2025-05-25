#ifndef _Struct_h
#define _Struct_h
#include <iostream>
#include <sstream>
using namespace std;
struct Node {
	string name;
	Node* firstChild = nullptr;
	bool flag;
	Node* nextSibling = nullptr;
	Node(string ime, bool flag = false) :name(ime), flag(flag) {}
};


#endif // !_Struct_h

