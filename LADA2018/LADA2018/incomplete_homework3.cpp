#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

class Node {
public:
	int idx;
	vector<int> neighbors;
};

enum Color { White, Gray, Black};

void BFSsweep(vector<Node> *List, int n, int v);
bool BFS(vector<Node> *List, Color *color, int v, bool *twoColor);
bool Comp(Node i, Node j) { return (i.idx < j.idx); }

int main()
{
	vector<Node> *vec = new vector<Node>;
	string str;
	while (getline(cin, str)) {
		Node Vertex;
		Vertex.idx = str[0] - '0';
		for (auto i = 1; i < str.length(); ++i) {
			if (str[i] != ' ') {
				Vertex.neighbors.push_back(str[i] - '0');
			}
		}
		vec->push_back(Vertex);
	}
	sort(vec->begin(), vec->end(), Comp);
	int n = vec->size();

	cout << "wo yi yue du guan yu chao xi de shuo ming" << endl;
	BFSsweep(vec, n, 0);
	// output
	system("pause");
	return 0;
}

void BFSsweep(vector<Node> *List, int n, int v) {
	Color *color = new Color[n];
	bool *twoColor = new bool[n];

	for (int i = 0; i < n; ++i) { color[i] = White; twoColor[i] = false; }
	int flag = 1;
	for (int i = 0; i < n; ++i) {
		if (color[(v + i) % n] == 'w')
			flag *= (int)(BFS(List, color, v + i, twoColor));
	}
	if (flag == 1) {
		for (int i = 0; i < n; ++i) {
			if (twoColor[i])
				cout << i << endl;
		}
	}
	return;
}

bool BFS(vector<Node> *List, Color *color, int v, bool *twoColor) {
	vector<int> remAdj;
	queue<int> q;
	q.push(v);
	// Pre Processing
	twoColor[v] = true;
	color[v] = Gray;
	while (!q.empty()) {
		int w = q.front(); q.pop();
		remAdj = (*List)[w].neighbors;
		while (!remAdj.empty()) {
			int x = remAdj.back();
			if (color[x] == White) {
				q.push(x); color[x] = Gray; 
				twoColor[x] = !(twoColor[w]);
			}
			else {// MOST CRUCIAL PART!!!!
				if (twoColor[w] == twoColor[x])
					return false;
 			}
			remAdj.pop_back();
		}
		// Post Processing
		color[w] = Black;
	}
	return true;
}