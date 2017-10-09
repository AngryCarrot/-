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
		if (a == nullptr || b == nullptr)
		{
			return false;
		}
		if (a == b)
		{
			return true;
		}
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
			m[c] = 1;
			for (auto item : c->neighbors)
			{
				if (b == item)
				{
					return true;
				}
				if (m[item] != 1)
				{
					q.push(item);
				}
			}
		}
		return false;
	}
};