#ifndef _GraphList_h
#define _GraphList_h
#include "GraphNode.h"
#include <iostream>
#include <sstream>
using namespace std;
struct GraphList {
	GraphNode* head;
	GraphList();
	GraphList(GraphNode* gn);
};


#endif // !_Struct_h