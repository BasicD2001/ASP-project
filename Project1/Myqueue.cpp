#include "Myqueue.h"

void Myqueue::Insert(Node* novi) {
	Red* p = GetRed(novi);
	
	if (rear == nullptr)
		front = p;
	else
		rear->next = p;
	rear = p;

}

Node* Myqueue::Delete() {
	if (front == nullptr) exit(-1);
	else {
		Red* red = new Red(front->info,front->next);
		Node* vrati = red->info;
		front = red->next;
		if (front == nullptr) rear = nullptr;
		delete red;
		return vrati;
	}
}

bool Myqueue::QueueEmpty() {
	if (front == nullptr) return true;
	else return false;
}