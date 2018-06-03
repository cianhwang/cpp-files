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
	vector<unsigned short> neighbors;
};

class Elem {
public:
	unsigned short count;
	vector<unsigned short> index;
};

void DFSsweep(vector<Node> *List, unsigned short n, unsigned short v, stack<unsigned short> *s);
void DFSsweep(vector<Node> *List, unsigned short n, unsigned short v, stack<unsigned short> *s, Elem &e);
void DFSsweep2(vector<Node> *List, unsigned short n, unsigned short v);
void DFS(vector<Node> *List, char *color, unsigned short v, stack<unsigned short> *s, bool inORout, unsigned short &count);
void DFS2(vector<Node> *List, char *color, unsigned short v, vector<unsigned short> &vec);

int main()
{
	vector<Node> *vec = new vector<Node>;
	string str;
	while (getline(cin, str)) {
		Node Vertex;
		for (auto i = 0; i < str.length(); ++i) {
			if (str[i] != ' ') {
				Vertex.neighbors.push_back(str[i] - '0');
			}
		}
		vec->push_back(Vertex);
	}
	unsigned short n = vec->size();
	cout << "I have read the rules about plagiarism punishment" << endl;

	stack<unsigned short> *s = new stack<unsigned short>;
	DFSsweep(vec, n, 0, s);
	Elem e;
	DFSsweep(vec, n, s->top(), s, e);
	cout << e.count - 1 << endl;

	vector<Node> *vec2 = new vector<Node>(n);
	for (auto i = 0; i < vec->size(); ++i) {
		vector<unsigned short> &vv = (*vec)[i].neighbors;
		while (!vv.empty()) {
			(*vec2)[vv.back()].neighbors.push_back(i);
			vv.pop_back();
		}
	}
	delete vec;
	for (auto i = 0; i < e.index.size(); ++i)
		DFSsweep2(vec2, n, e.index[e.index.size()-1-i]);

	system("pause");
	return 0;
}

void DFSsweep(vector<Node> *List, unsigned short n, unsigned short v, stack<unsigned short> *s) {
	char *color = new char[n];
	for (unsigned short i = 0; i < n; ++i) { color[i] = 'w'; }
	unsigned short count = 0;
	for (unsigned short i = 0; i < n; ++i) {
		if (color[(v + i) % n] == 'w')
			DFS(List, color, v + i, s, true, count);
	}
	return;
}

void DFSsweep(vector<Node> *List, unsigned short n, unsigned short v, stack<unsigned short> *s, Elem &e) {
	char *color = new char[n];
	for (unsigned short i = 0; i < n; ++i) { color[i] = 'w'; }
	unsigned short Temp = 0;
	vector<unsigned short> idx;
	while (!s->empty()) {
		unsigned short count = 0;
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


void DFSsweep2(vector<Node> *List, unsigned short n, unsigned short v) {
	char *color = new char[n];
	for (unsigned short i = 0; i < n; ++i) { color[i] = 'w'; }
	vector<unsigned short> vec;
	DFS2(List, color, v, vec);
	sort(vec.begin(), vec.end());
	for (auto i = 0; i < vec.size(); ++i) {
		cout << vec[i] << ' ';
	}
	return;
}

void DFS(vector<Node> *List, char *color, unsigned short v, stack<unsigned short> *s, bool inORout, unsigned short &count) {
	unsigned short w;
	vector<unsigned short> remAdj;
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

void DFS2(vector<Node> *List, char *color, unsigned short v, vector<unsigned short> &vec) {
	unsigned short w;
	vector<unsigned short> remAdj;
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