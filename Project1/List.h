#ifndef _List_h
#define _List_h
#include <iostream>
#include <sstream>
using namespace std;

struct ListString {
	string name;
	ListString* next;
	ListString(string name, ListString* next = nullptr) :name(name), next(next) {}
};

ListString* CreateStringList(string line);

void PrintStr(ListString* start);
void DeleteList(ListString* start);
#endif // !_List_h
