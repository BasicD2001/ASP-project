#ifndef _Graph_h
#define _Graph_h
#include "GraphAdjNode.h"
#include "Tree.h"
#include <iostream>
#include <sstream>
using namespace std;
class Graph {
public:
	GraphAdjNode* head;
	Graph(Tree t);
	Graph();
	void AddElement(string s, string t);

	void Ispis();

	void LevelOrder();
};


#endif // !_Struct_h