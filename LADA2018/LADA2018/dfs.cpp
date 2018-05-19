#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	int value;
	vector<int> neighbors;
};

void cnctComp(Node *List, int n, int *cc);
void ccDFS(Node *List, char *color, int v, int ccNum, int *cc);

int main()
{
	int n = 0; cin >> n;
	Node *List = new Node[n];
	for (int i = 0; i < n; ++i) {
		List[i].value = i;
	}
	for (int i = 0; i < n; ++i) {
		int idx = 0; cin >> idx;
		int val = 0; cin >> val;
		List[idx].neighbors.push_back(val);
	}
	int *cc = new int[n];
	cnctComp(List, n, cc);
	cout << endl;
	for (int i = 0; i < n; ++i) {
		cout << cc[i] << ' ';
	}
	system("PAUSE");
	return 0;
}

void cnctComp(Node *List, int n, int *cc) {
	char *color = new char [n];
	int v;
	for (v = 0; v < n; ++v) { color[v] = 'w'; }
	for (v = 0; v < n; ++v) {
		if (color[v] == 'w')
			ccDFS(List, color, v, v, cc);
	}
	return;
}

void ccDFS(Node *List, char *color, int v, int ccNum, int *cc) {
	int w;
	vector<int> remAdj;
	color[v] = 'g';
	cc[v] = ccNum;
	remAdj = List[v].neighbors;
	while (remAdj.size() != 0) {
		w = remAdj.back();
		if (color[w] == 'w') {
			ccDFS(List, color, w, ccNum, cc);
		}
		remAdj.pop_back();
	}
	cout << v << ' ';
	color[v] = 'b';
	return;
}
