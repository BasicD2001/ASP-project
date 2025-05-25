#ifndef _GraphAdjNode_h
#define _GraphAdjList_h
#include "GraphList.h"
#include <iostream>
#include <sstream>
using namespace std;
struct GraphAdjNode {
	GraphList data;
	GraphAdjNode* next;
	GraphAdjNode(GraphList gl);
};


#endif // !