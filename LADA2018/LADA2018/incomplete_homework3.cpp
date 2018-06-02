<<<<<<< HEAD
// 0 1 0 2 0 5 1 2 1 3 3 0 3 2 4 2 4 6 5 0 6 4 6 3 - Strong Connected Component
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>
=======
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
>>>>>>> ec693eb810f33bb300a6934685a7b8d7aeff0bf4
#include <string>
#include <algorithm>
using namespace std;

class Node {
public:
<<<<<<< HEAD
	vector<short> neighbors;
};

void DFSsweep(Node *List, short n, short v, stack<short> &s);
void DFS(Node *List, char *color, short v, stack<short> &s);
void DFSsweep2(Node *List, short n, short v, vector<short> &vec);
void DFS2(Node *List, char *color, short v, vector<short> &vec);
void DFSsweep3(Node *List, short n, short v, stack<short> &s, short &count);
void DFS3(Node *List, char *color, short v, stack<short> &s, short &count);
=======
	int idx;
	vector<int> neighbors;
};

enum Color { White, Gray, Black};

void BFSsweep(vector<Node> *List, int n, int v);
bool BFS(vector<Node> *List, Color *color, int v, bool *twoColor);
bool Comp(Node i, Node j) { return (i.idx < j.idx); }
>>>>>>> ec693eb810f33bb300a6934685a7b8d7aeff0bf4

int main()
{
	vector<Node> *vec = new vector<Node>;
	string str;
	while (getline(cin, str)) {
<<<<<<< HEAD
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

=======
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
>>>>>>> ec693eb810f33bb300a6934685a7b8d7aeff0bf4
	system("pause");
	return 0;
}

<<<<<<< HEAD
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
=======
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
>>>>>>> ec693eb810f33bb300a6934685a7b8d7aeff0bf4
