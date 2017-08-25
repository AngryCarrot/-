#pragma once

#include "header.h"

struct UndirectedGraphNode {
	int label;
	vector<struct UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) { }
};

class Path {
public:
	bool checkPath(UndirectedGraphNode* a, UndirectedGraphNode* b) {
		// write code here
		// ¿Ó
		return checkPathHelper(a, b) || checkPathHelper(b, a);
	}
private:
	bool checkPathHelper(UndirectedGraphNode* a, UndirectedGraphNode* b)
	{
		map<UndirectedGraphNode*, int> m;
		queue<UndirectedGraphNode*> q;
		q.push(a);
		while (!q.empty())
		{
			auto c = q.front();
			q.pop();
			for (auto item : c->neighbors)
			{
				if (b == item)
				{
					return true;
				}
				if (0 == m.count(item))
				{
					q.push(item);
					m[c] = 1;
				}
			}
		}
		return false;
	}
};