#ifndef  _Myqueue_h
#define _Myqueue_h
#include "Struct.h"
using namespace std;


class Myqueue {
public:
	struct Red {
		Node* info;
		Red* next = nullptr;
		Red(Node* info, Red* next = nullptr) : info(info), next(next) {}
	};
	Red* GetRed(Node* info) { return new Red{ info }; }
	Red* front = nullptr;
	Red* rear = nullptr;

	void Insert(Node* novi);

	Node* Delete();

	bool QueueEmpty();

};
#endif // ! _Queue_h

