#include "Tree.h"



void Tree::PrintLevelOrder() {
	if (root == nullptr) {
		cout << "Stablo je prazno." << endl;
		return;
	}
	red.Insert(root);
	while (!red.QueueEmpty()) {
		Node* current = red.Delete();
		if (current->name != "")
			cout << current->name << " ";

		Node* child = current->firstChild;
		while (child != nullptr) {
			red.Insert(child);
			child = child->nextSibling;
		}
	}
	cout << endl;

}


void Tree::EnterEmptyTree(ListString* list) {
	ListString* list1 = list;
	Node* tek = root;
	Node* novi = nullptr;
	if (list1->name != "main") exit(-1);
	root = GetNode(list1->name);
	tek = root;
	list1 = list1->next;
	while (list1) {
		novi = GetNode(list1->name);
		tek->firstChild = novi;
		tek = tek->firstChild;
		list1 = list1->next;
	}
}

void Tree::EnterTree(ListString* list) {
	ListString* list1 = list;
	Node* tek = root;
	Node* novi = nullptr;
	Node* lastChild = nullptr;
	if (list1->name != "main") exit(-1);
	list1 = list1->next;
	while (list1) {
		if (tek->firstChild == nullptr) {
			novi = GetNode(list1->name);
			tek->firstChild = novi;
			tek = tek->firstChild;
		}
		else {

			ListString* temp = list1->next;
			bool implicRecursion = false;
			if (temp != nullptr) {
				implicRecursion = tek->name == temp->name;
			}

			if (implicRecursion) {
				lastChild = tek->firstChild;

				novi = GetNode(list1->name);
				tek->firstChild = novi;
				novi->nextSibling = lastChild;
				tek = tek->firstChild;

				// napravi novi node
			}

			else {

				if (tek->firstChild->name == list1->name)
					tek = tek->firstChild;
				else {
					lastChild = tek->firstChild;
					while (lastChild->nextSibling != nullptr) {
						if (lastChild->nextSibling->name == list1->name) {
							tek = lastChild->nextSibling;
							break;
						}
						lastChild = lastChild->nextSibling;
					}
					if (lastChild->nextSibling == nullptr) {
						novi = GetNode(list1->name);
						lastChild->nextSibling = novi;
						tek = lastChild->nextSibling;

					}
				}

			}

		}
		list1 = list1->next;

	}
}

Tree::~Tree() {
	cout << "Ulazim u funkciju DeleteTree()" << endl;
	if (root == nullptr) {
		cout << "Stablo je prazno." << endl;
		return;
	}
	red.Insert(root);
	while (!red.QueueEmpty()) {
		Node* current = red.Delete();
        Node* child = current->firstChild;
		delete current;
		while (child != nullptr) {
			red.Insert(child);
			child = child->nextSibling;
		}
	}
	cout << endl;

}



void Tree::DeleteLine(ListString* list) {
	
	ListString* list1 = list;
	Node* tek = root;
	Node* tek2 = root;
	Node* stari = nullptr;
	Node* check = nullptr;
	
	Node* potential = nullptr;
	Node* lastChild = nullptr;
	Node** kraj;

	if (list1->name != "main") { exit(-1); }
	list1 = list1->next;
	while (list1) {
		
		check = tek;
		
		if (tek->firstChild->name == list1->name)
			tek = tek->firstChild;
		else {
			lastChild = tek->firstChild;
			while (lastChild->nextSibling != nullptr) {
				if (lastChild->nextSibling->name == list1->name) {
					tek = lastChild->nextSibling;
					break;
				}
				lastChild = lastChild->nextSibling;
			}

		}
		if (check->firstChild->nextSibling != nullptr) {
			potential = tek;
			


		}
		list1 = list1->next;
	}

	if (potential == nullptr) { kraj = &root; *kraj = nullptr; }
	else { potential->name = ""; potential->firstChild = nullptr; }
}
		

