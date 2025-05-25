#ifndef _Tree_h
#define _Tree_h
#include "List.h"
#include "Myqueue.h"
#include <queue>


class Tree {
private:
	
public:
	Myqueue red;
	Node* root = nullptr;
	void EnterEmptyTree(ListString* list);

	void EnterTree(ListString* list);

	void PrintLevelOrder();

	Node* GetNode(string ime,bool flag=false) {
		return new Node{ ime,flag };
	}

	Node* GetRoot() const {
		return root;
	}

	~Tree();

	void DeleteLine(ListString* list);

	

};

#endif // !Tree

