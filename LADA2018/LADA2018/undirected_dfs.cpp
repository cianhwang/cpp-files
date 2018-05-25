#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Node {
public:
	int weight;
	vector<int> neighbors;
};

void DFSsweep(Node *List, int n, int v);
void DFS(Node *List, char *color, int v, int parent);

int main()
{
	int n = 0; cin >> n;
	Node *List = new Node[n];
	int idx = 0;
	while(cin >> idx) {
		int val = 0; cin >> val;
		List[idx].neighbors.push_back(val); //...
		List[val].neighbors.push_back(idx); //...
	}
	DFSsweep(List, n, 0);

	// output

	system("pause");
	return 0;
}

void DFSsweep(Node *List, int n, int v) {
	char *color = new char[n];
	for (int i = 0; i < n; ++i) { color[i] = 'w'; }
	for (int i = 0; i < n; ++i) {
		if (color[(v + i) % n] == 'w')
			DFS(List, color, v + i, -1);
	}
	return;
}

void DFS(Node *List, char *color, int v ,int parent) {
	int w;
	vector<int> remAdj;
	// Pre Processing

	int Count = 0;
	color[v] = 'g';
	remAdj = List[v].neighbors;
	while (remAdj.size() != 0) {
		w = remAdj.front();
		if (color[w] == 'w') {
			// ...
			DFS(List, color, w, v);
			// backtrack
		}
		else if(color[w] = 'g' && w != parent){
			;
		}
		remAdj.erase(remAdj.begin());
	}
	// Post Processing

	color[v] = 'b';
	return;
}