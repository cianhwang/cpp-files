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

void BFSsweep(vector<Node> List, int n, int v);
void BFS(vector<Node> List, char *color, int v, int parent, queue<int> &q);

int main()
{
	vector<Node> vec;
	Node Vertex;
	string str;
	while (getline(cin, str)) {
		for (auto i = 1; i < str.length(); ++i)
			if (str[i] != ' ') {
				Vertex.neighbors.push_back(str[i] - '0');
			}
		vec.push_back(Vertex);
	}
	cout << "wo yi yue du guan yu chao xi de shuo ming" << endl;
	BFSsweep(vec, vec.size(), 0);
	// output

	system("pause");
	return 0;
}

void BFSsweep(vector<Node> List, int n, int v) {
	char *color = new char[n];
	for (int i = 0; i < n; ++i) { color[i] = 'w'; }
	queue<int> q;
	for (int i = 0; i < n; ++i) {
		if (color[(v + i) % n] == 'w')
			BFS(List, color, v + i, 0, q);
	}
	return;
}

void BFS(vector<Node> List, char *color, int v, int parent, queue<int> &q) {
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
				;
			remAdj.erase(remAdj.begin());
		}
		// Post Processing
		parent = 1 - parent;//...................
		color[w] = 'b';
	}
	return;
}