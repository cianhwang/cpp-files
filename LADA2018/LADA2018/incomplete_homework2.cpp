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
	vector<int> neighbors;
};

void DFSsweep(Node *List, int n, int v, stack<int> &s);
void DFS(Node *List, char *color, int v, stack<int> &s);
void DFSsweep2(Node *List, int n, int v, stack<int> &s);
void DFS2(Node *List, char *color, int v, stack<int> &s, vector<int> &vec);


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
	int n = vec->size();
	Node *List = new Node[n];
	for (int i = n - 1; i >= 0; --i) {
		List[i].neighbors = vec->back().neighbors;	
		vec->pop_back();
	}
	delete vec;
	Node *List2 = new Node[n];
	for (int i = n - 1; i >= 0; --i) {
		for (auto j = 0; j < List[i].neighbors.size(); ++j) {
			List2[(List[i].neighbors[j])].neighbors.push_back(i);
		}
	}

	//for (int i = 0; i < n; ++i) {
	//	for (int j = 0; j < List2[i].neighbors.size(); ++j) {
	//		cout << List2[i].neighbors[j] << ' ';
	//	}
	//	cout << endl;
	//}
	cout << "I have read the rules about plagiarism punishment" << endl;
	stack<int> s;
	DFSsweep(List, n, 0, s);
	delete[]List;
	cout << n-1 << endl;

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

	vector<int> vec;
	//while (!s.empty()) {
	DFS2(List, color, v, s, vec);
	//	if (!s.empty())	v = s.top();
	//}
	sort(vec.begin(), vec.end());
	for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
		cout << *it << ' ';
	}
	return;
}

void DFS2(Node *List, char *color, int v, stack<int> &s, vector<int> &vec) {
	int w;
	vector<int> remAdj;
	// Pre Processing
	vec.push_back(v);
	color[v] = 'g';
	remAdj = List[v].neighbors;
	while (remAdj.size() != 0) {
		w = remAdj.front();
		if (color[w] == 'w') {
			DFS2(List, color, w, s, vec);
			// backtrack

		}
		else {
			;
		}
		remAdj.erase(remAdj.begin());
	}
	// Post Processing
	s.pop();
	color[v] = 'b';
	return;
}

