#ifndef _GraphNode_h
#define _GraphNode_h
#include <iostream>
#include <sstream>
using namespace std;
struct GraphNode {

	string name;
	GraphNode* next;
	GraphNode(string s);
};


#endif // !_Struct_h