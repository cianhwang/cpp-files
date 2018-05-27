#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class Node {
public:
	vector<int> neighbors;
};

void BFSsweep(vector<Node> List, int n, int v, bool *twoColor);
void BFS(vector<Node> List, char *color, int v, bool *twoColor, queue<int> &q);

int main()
{
	vector<Node> vec;
	string str;
	while (getline(cin, str)) {
		Node Vertex;
		for (auto i = 1; i < str.length(); ++i)
			if (str[i] != ' ') {
				Vertex.neighbors.push_back(str[i] - '0');
			}
		vec.push_back(Vertex);
	}
	int n = vec.size();
	bool *twoColor = new bool[n];
	BFSsweep(vec, n, 0, twoColor);
	// output
	cout << "wo yi yue du guan yu chao xi de shuo ming" << endl;
	for (int i = 0; i < n; ++i) {
		if (twoColor[i])
			cout << i << endl;
	}
	system("pause");
	return 0;
}

void BFSsweep(vector<Node> List, int n, int v, bool *twoColor) {
	char *color = new char[n];
	for (int i = 0; i < n; ++i) { color[i] = 'w'; }
	queue<int> q;
	for (int i = 0; i < n; ++i) {
		if (color[(v + i) % n] == 'w')
			BFS(List, color, v + i, twoColor, q);
	}
	return;
}

void BFS(vector<Node> List, char *color, int v, bool *twoColor, queue<int> &q) {
	vector<int> remAdj;
	q.push(v);
	// Pre Processing
	twoColor[v] = true;
	color[v] = 'g';
	while (!q.empty()) {
		int w = q.front(); q.pop();
		remAdj = List[w].neighbors;
		while (!remAdj.empty()) {
			int x = remAdj.back();
			if (color[x] == 'w') {
				q.push(x); color[x] = 'g'; twoColor[x] = !(twoColor[w]);
			}
			//else if (color[x] == 'g') // MOST CRUCIAL PART!!!!
			//	;
			remAdj.pop_back();
		}
		// Post Processing
		color[w] = 'b';
	}
	return;
}