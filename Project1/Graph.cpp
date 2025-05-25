#include "Graph.h"

Graph::Graph(Tree t) {
	if (t.GetRoot() == nullptr) {
		cout << "Stablo je prazno." << endl;
		return;
	}
	t.red.Insert(t.root);
	while (!t.red.QueueEmpty()) {
		Node* current = t.red.Delete();	
		string currentName = current->name;
		Node* child = current->firstChild;
		Node* prevChild = nullptr;

		while (child != nullptr) {
			t.red.Insert(child);
			string childName = child->name;
			bool recursion = false;
			if (prevChild != nullptr) {
				recursion = prevChild->name == childName;
			}

			if (recursion) {
				AddElement(childName, currentName);
			}
			else {
				AddElement(currentName, childName);
			}
			
			prevChild = child;
			child = child->nextSibling;
		}


	}
	cout << endl;
}


Graph::Graph() {
	head = nullptr;
}

// add t to adj list of s
void Graph::AddElement(string s, string t) {
	GraphAdjNode* temp = head;
	GraphAdjNode* prevTemp = nullptr;
	GraphNode* newNodeT = new GraphNode(t);

	bool foundFirst = false;

	if (temp == nullptr) {
		GraphNode* newNodeS = new GraphNode(s);
		newNodeS->next = newNodeT;
		GraphList* gl = new GraphList(newNodeS);
		GraphAdjNode* gan = new GraphAdjNode(*gl);
		head = gan;

	}

	else {

		while (temp != nullptr && !foundFirst) {
			GraphNode* tempListHead = temp->data.head;

			if (tempListHead->name == s) {
				foundFirst = true;
				bool found = false;
				GraphNode* tempListValue = tempListHead;
				while (tempListValue->next != nullptr && !found) {
					if (tempListValue->next->name == t) {
						found = true;
					}
					tempListValue = tempListValue->next;
				}
				if (!found) {
					tempListValue->next = newNodeT;
				}
			}

			prevTemp = temp;
			temp = temp->next;
		}

		if (!foundFirst) {
			GraphNode* newNodeS = new GraphNode(s);
			newNodeS->next = newNodeT;
			GraphList* gl = new GraphList(newNodeS);
			GraphAdjNode* gan = new GraphAdjNode(*gl);
			prevTemp->next = gan;
		}
	}

}

void Graph::Ispis() {
	GraphAdjNode* temp = head;
	while (temp!=nullptr) {
		GraphNode* tempListHead = temp->data.head;
		
		while (tempListHead != nullptr) {
			cout << tempListHead->name<<" ";
			tempListHead = tempListHead->next;
		}

		temp = temp->next;
		cout << endl;
	}
}

void Graph::LevelOrder(){}
