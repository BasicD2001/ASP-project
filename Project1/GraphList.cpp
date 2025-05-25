#include "GraphList.h"

GraphList::GraphList() {
	head = nullptr;
}

GraphList::GraphList(GraphNode* gn) {
	head = gn;
}
