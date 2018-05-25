#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
	int weight;
	vector<int> neighbors;
};

void BFSsweep(Node *List, int n, int v);
void BFS(Node *List, char *color, int v, queue<int> &q);

int main()
{
	int n = 0; cin >> n;
	Node *List = new Node[n];
	int idx = 0;
	while(cin >> idx) {
		int val = 0; cin >> val;
		List[idx].neighbors.push_back(val); //...
	}
	BFSsweep(List, n, 0);
	// output

	system("pause");
	return 0;
}

void BFSsweep(Node *List, int n, int v) {
	char *color = new char[n];
	for (int i = 0; i < n; ++i) { color[i] = 'w'; }
	queue<int> q;
	for (int i = 0; i < n; ++i) {
		if (color[(v + i) % n] == 'w')
			BFS(List, color, v + i, q);
	}
	return;
}

void BFS(Node *List, char *color, int v, queue<int> &q) {
	int w;
	vector<int> remAdj;
	// Pre Processing
	q.push(v);

	color[v] = 'g';
	while (!q.empty()) {
		w = q.front(); q.pop();
		remAdj = List[w].neighbors;
		while (!remAdj.empty()) {
			int x = remAdj.front();
			if (color[x] == 'w') {
				q.push(x); color[x] = 'g';
			}
			remAdj.erase(remAdj.begin());
		}
		// Post Processing
		cout << w << endl;
		color[w] = 'b';
	}
	return;
}