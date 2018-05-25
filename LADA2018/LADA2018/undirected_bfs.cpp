// 0 3 3 5 5 0 5 4 4 1 1 2 2 4 1 6 6 8 8 1 5 7 7 0 5 9 9 3 --Slice 3
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
		List[idx].neighbors.push_back(val);
		List[val].neighbors.push_back(idx);
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
	q.push(v);
	// Pre Processing

	color[v] = 'g';
	while (!q.empty()) {
		w = q.front(); q.pop();
		remAdj = List[w].neighbors;
		while (!remAdj.empty()) {
			int x = remAdj.front();
			if (color[x] == 'w') {
				q.push(x); color[x] = 'g';
			}
			else if (color[x] == 'g') // MOST CRUCIAL PART!!!!
				cout << w << ' ' << x << endl;
			remAdj.erase(remAdj.begin());
		}
		// Post Processing

		color[w] = 'b';
	}
	return;
}