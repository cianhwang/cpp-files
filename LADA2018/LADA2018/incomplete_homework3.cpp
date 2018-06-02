// 0 1 0 2 0 5 1 2 1 3 3 0 3 2 4 2 4 6 5 0 6 4 6 3 - Strong Connected Component
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Node {
public:
	vector<short> neighbors;
};

void DFSsweep(Node *List, short n, short v, stack<short> &s);
void DFS(Node *List, char *color, short v, stack<short> &s);
void DFSsweep2(Node *List, short n, short v, vector<short> &vec);
void DFS2(Node *List, char *color, short v, vector<short> &vec);
void DFSsweep3(Node *List, short n, short v, stack<short> &s, short &count);
void DFS3(Node *List, char *color, short v, stack<short> &s, short &count);

int main()
{
	vector<Node> *vec = new vector<Node>;
	string str;
	while (getline(cin, str)) {
		Node *Vertex = new Node;
		for (auto i = 0; i < str.length(); ++i)
			if (str[i] != ' ') {
				Vertex->neighbors.push_back(str[i] - '0');
			}
		vec->push_back(*Vertex);
		delete Vertex;
	}
	short n = vec->size();
	Node *List = new Node[n];
	for (short i = n - 1; i >= 0; --i) {
		List[i].neighbors = vec->back().neighbors;
		vec->pop_back();
	}
	delete vec;
	cout << "I have read the rules about plagiarism punishment" << endl;
	stack<short> s;
	DFSsweep(List, n, 0, s);

	short count = 0, Temp = 0;
	short VVV = 0;
	vector<short> vec2;
	while (!s.empty()) {
		int v = s.top();
		DFSsweep3(List, n, v, s, count);
		if (count > Temp) {
			VVV = v;
			Temp = count;
		}
	}
	Node *List2 = new Node[n];
	for (short i = n - 1; i >= 0; --i) {
		for (auto j = 0; j < List[i].neighbors.size(); ++j) {
			List2[(List[i].neighbors[j])].neighbors.push_back(i);
		}
	}
	delete[]List;
	DFSsweep2(List2, n, VVV, vec2);
	cout << Temp-1 << endl;
	sort(vec2.begin(), vec2.end());
	for (auto it = vec2.cbegin(); it != vec2.cend(); ++it) {
		cout << *it << ' ';
	}

	system("pause");
	return 0;
}

void DFSsweep(Node *List, short n, short v, stack<short> &s) {
	char *color = new char[n];
	for (short i = 0; i < n; ++i) { color[i] = 'w'; }
	for (short i = 0; i < n; ++i) {
		if (color[(v + i) % n] == 'w')
			DFS(List, color, v + i, s);
	}
	return;
}

void DFS(Node *List, char *color, short v, stack<short> &s) {
	short w;
	vector<short> remAdj;
	// Pre Processing

	color[v] = 'g';
	remAdj = List[v].neighbors;
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

void DFSsweep2(Node *List, short n, short v, vector<short> &vec) {
	char *color = new char[n];
	for (short i = 0; i < n; ++i) { color[i] = 'w'; }

	DFS2(List, color, v, vec);
	return;
}

void DFS2(Node *List, char *color, short v, vector<short> &vec) {
	short w;
	vector<short> remAdj;
	// Pre Processing
	vec.push_back(v);
	color[v] = 'g';
	remAdj = List[v].neighbors;
	while (remAdj.size() != 0) {
		w = remAdj.front();
		if (color[w] == 'w') {
			DFS2(List, color, w, vec);
			// backtrack

		}
		else {
			;
		}
		remAdj.erase(remAdj.begin());
	}
	// Post Processing
	color[v] = 'b';
	return;
}

void DFSsweep3(Node *List, short n, short v, stack<short> &s, short &count) {
	char *color = new char[n];
	for (short i = 0; i < n; ++i) { color[i] = 'w'; }

	DFS3(List, color, v, s, count);
	return;
}

void DFS3(Node *List, char *color, short v, stack<short> &s, short &count) {
	short w;
	vector<short> remAdj;
	// Pre Processing

	color[v] = 'g';
	remAdj = List[v].neighbors;
	while (remAdj.size() != 0) {
		w = remAdj.front();
		if (color[w] == 'w') {
			DFS3(List, color, w, s, count);
			// backtrack

		}
		else {
			;
		}
		remAdj.erase(remAdj.begin());
	}
	// Post Processing
	s.pop(); ++count;
	color[v] = 'b';
	return;
}
