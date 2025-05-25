#include "List.h"

ListString* CreateStringList(string line) {
	istringstream  stream(line);
	string word;
	ListString* start = nullptr;
	ListString* current = nullptr;
	ListString* novi = nullptr;

	while (stream >> word) {
		if (start == nullptr) {
			start = new ListString(word);
			current = start;

		}
		else {
			novi = new ListString(word);
			current->next = novi;
			current = novi;
		}

	}

	return start;
}

void PrintStr(ListString* start) {
	ListString* head = start;
	while (head) {
		cout << head->name << endl;
		head = head->next;
	}
}

void DeleteList(ListString* start) {
	ListString* head = start;
	ListString* stari = nullptr;

	while (head) {
		stari = head;
		head = head->next;
		delete stari;
	}

}


