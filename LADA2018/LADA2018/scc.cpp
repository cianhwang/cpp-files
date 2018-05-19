// 0 1 0 2 0 5 1 2 1 3 3 0 3 2 4 2 4 6 5 0 6 4 6 3 - Strong Connected Component
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Node {
public:
	int weight;
	vector<int> neighbors;
};

void DFSsweep(Node *List, int n, int v, stack<int> &s);
void DFS(Node *List, char *color, int v, stack<int> &s);
void DFSsweep2(Node *List, int n, int v, stack<int> &s);
void DFS2(Node *List, char *color, int v, stack<int> &s);


int main()
{
	int n = 0; cin >> n;
	Node *List = new Node[n];
	// Transpose
	Node *List2 = new Node[n];
	int idx = 0;
	while(cin >> idx) {
		int val = 0; cin >> val;
		List[idx].neighbors.push_back(val); //...
		List2[val].neighbors.push_back(idx); //Transpose
	}
	stack<int> s;
	DFSsweep(List, n, 0, s);
	//while (!s.empty()) {
	//	cout << s.top() << ' ';
	//	s.pop();
	//}
	DFSsweep2(List2, n, s.top(), s);

	system("pause");
	return 0;
}

void DFSsweep(Node *List, int n, int v, stack<int> &s) {
	char *color = new char[n];
	for (int i = 0; i < n; ++i) { color[i] = 'w'; }
	for (int i = 0; i < n; ++i) {
		if (color[(v + i) % n] == 'w')
			DFS(List, color, v + i, s);
	}
	return;
}

void DFS(Node *List, char *color, int v, stack<int> &s) {
	int w;
	vector<int> remAdj;
	// Pre Processing

	color[v] = 'g';
	remAdj = List[v].neighbors;
	int Max = 0;
	while (remAdj.size() != 0) {
		w = remAdj.front();
		if (color[w] == 'w') {
			DFS(List, color, w, s);
			// backtrack

		}
		else {
			;
		}
		remAdj.erase(remAdj.begin());
	}
	// Post Processing
	s.push(v);
	color[v] = 'b';
	return;
}

void DFSsweep2(Node *List, int n, int v, stack<int> &s) {
	char *color = new char[n];
	for (int i = 0; i < n; ++i) { color[i] = 'w'; }
	while (!s.empty()) {
		DFS2(List, color, v, s);
		cout << "| ";
		if (!s.empty())	v = s.top();
	}
	return;
}

void DFS2(Node *List, char *color, int v, stack<int> &s) {
	int w;
	vector<int> remAdj;
	// Pre Processing

	color[v] = 'g';
	remAdj = List[v].neighbors;
	int Max = 0;
	while (remAdj.size() != 0) {
		w = remAdj.front();
		if (color[w] == 'w') {
			DFS2(List, color, w, s);
			// backtrack

		}
		else {
			;
		}
		remAdj.erase(remAdj.begin());
	}
	// Post Processing
	cout << s.top() << ' ';
	s.pop();
	color[v] = 'b';
	return;
}

