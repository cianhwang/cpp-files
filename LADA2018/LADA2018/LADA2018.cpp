// 0 1 0 2 0 5 1 2 1 3 3 0 3 2 4 2 4 6 5 0 6 4 6 3 - Strong Connected Component
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

class Node {
public:
	vector<int> neighbors;
};

class Elem {
public:
	int count;
	vector<int> index;
};

void DFSsweep(vector<Node> *List, int n, int v, stack<int> *s);
void DFSsweep(vector<Node> *List, int n, int v, stack<int> *s, Elem &e);
void DFSsweep2(vector<Node> *List, int n, int v, vector<int> &vec);
void DFS(vector<Node> *List, char *color, int v, stack<int> *s, bool inORout, int &count);
void DFS2(vector<Node> *List, char *color, int v, vector<int> &vec);

int main()
{
	vector<Node> *vec = new vector<Node>;
	string str;
	while (getline(cin, str)) {
		Node Vertex;
		istringstream is(str);
		int aa = 0;
		while (is >> aa) {
			Vertex.neighbors.push_back(aa);
		}
		vec->push_back(Vertex);
	}
	int n = vec->size();
	vector<Node> *vec2 = new vector<Node>(n);
	for (auto i = 0; i < vec->size(); ++i) {
		vector<int> &vv = (*vec)[i].neighbors;
		while (!vv.empty()) {
			(*vec2)[vv.back()].neighbors.push_back(i);
			vv.pop_back();
		}
	}
	cout << "I have read the rules about plagiarism punishment" << endl;

	stack<int> *s = new stack<int>;
	DFSsweep(vec, n, 0, s);
	Elem e;
	DFSsweep(vec, n, s->top(), s, e);
	cout << e.count - 1 << endl;

	vector<int> vvv;
	for (auto i = 0; i < e.index.size(); ++i)
		DFSsweep2(vec2, n, e.index[i], vvv);
	sort(vvv.begin(), vvv.end());
	for (auto i = 0; i < vvv.size(); ++i) {
		cout << vvv[i] << ' ';
	}
	system("pause");
	return 0;
}

void DFSsweep(vector<Node> *List, int n, int v, stack<int> *s) {
	char *color = new char[n];
	for (int i = 0; i < n; ++i) { color[i] = 'w'; }
	int count = 0;
	for (int i = 0; i < n; ++i) {
		if (color[(v + i) % n] == 'w')
			DFS(List, color, v + i, s, true, count);
	}
	return;
}

void DFSsweep(vector<Node> *List, int n, int v, stack<int> *s, Elem &e) {
	char *color = new char[n];
	for (int i = 0; i < n; ++i) { color[i] = 'w'; }
	int Temp = 0;
	vector<int> idx;
	while (!s->empty()) {
		int count = 0;
		v = s->top();
		DFS(List, color, v, s, false, count);
		if (count > Temp) {
			Temp = count;
			idx.clear();
			idx.push_back(v);
		}
		else if (count == Temp)
			idx.push_back(v);
	}
	e.count = Temp; e.index = idx;
	return;
}


void DFSsweep2(vector<Node> *List, int n, int v, vector<int> &vec) {
	char *color = new char[n];
	for (int i = 0; i < n; ++i) { color[i] = 'w'; }
	DFS2(List, color, v, vec);
	return;
}

void DFS(vector<Node> *List, char *color, int v, stack<int> *s, bool inORout, int &count) {
	int w;
	vector<int> remAdj;
	// Pre Processing

	color[v] = 'g';
	remAdj = (*List)[v].neighbors;
	while (remAdj.size() != 0) {
		w = remAdj.back();
		if (color[w] == 'w') {
			DFS(List, color, w, s, inORout, count);
			// backtrack

		}
		else {
			;
		}
		remAdj.pop_back();
	}
	// Post Processing
	if (inORout) s->push(v); else { s->pop(); }
	++count;
	color[v] = 'b';
	return;
}

void DFS2(vector<Node> *List, char *color, int v, vector<int> &vec) {
	int w;
	vector<int> remAdj;
	// Pre Processing

	color[v] = 'g';
	remAdj = (*List)[v].neighbors;
	while (remAdj.size() != 0) {
		w = remAdj.back();
		if (color[w] == 'w') {
			DFS2(List, color, w, vec);
			// backtrack

		}
		else {
			;
		}
		remAdj.pop_back();
	}
	// Post Processing
	vec.push_back(v);

	color[v] = 'b';
	return;
}