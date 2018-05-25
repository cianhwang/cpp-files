// 7 0 1 0 2 0 5 1 2 1 3 3 1 3 2 4 2 4 6 5 0 6 4 6 3 -- Slice 1
// 
#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	int value;
	vector<int> neighbors;
};

void DFSsweep(Node *List, int n, int *discoverTime, int *finishTime);
void DFS(Node *List, char *color, int v, int *discoverTime, int *finishTime, int &Time);

int main()
{
	int n = 0; cin >> n;
	Node *List = new Node[n];
	for (int i = 0; i < n; ++i) {
		List[i].value = i;
	}
	int idx = 0;
	while(cin >> idx) {
		int val = 0; cin >> val;
		List[idx].neighbors.push_back(val);
	}
	int *discoverTime = new int[n];
	int *finishTime = new int[n];

	DFSsweep(List, n, discoverTime, finishTime);

	cout << endl;
	system("pause");
	return 0;
}

void DFSsweep(Node *List, int n, int *discoverTime, int *finishTime) {
	char *color = new char [n];
	int v;
	for (v = 0; v < n; ++v) { color[v] = 'w'; }
	int Time = 0;
	for (v = 0; v < n; ++v) {
		if (color[v] == 'w')
			DFS(List, color, v, discoverTime, finishTime, Time);
	}
	return;
}

void DFS(Node *List, char *color, int v, int *discoverTime, int *finishTime, int &Time) {
	int w;
	vector<int> remAdj;
	// Pre Processing
	++Time; discoverTime[v] = Time;
	color[v] = 'g';
	remAdj = List[v].neighbors;
	while (remAdj.size() != 0) {
		w = remAdj.front();
		if (color[w] == 'w') {
			DFS(List, color, w, discoverTime, finishTime, Time);
		}
		else {
			;
		}
		remAdj.erase(remAdj.begin());
	}
	cout << v << ' ';
	// Post Processing
	Time++; finishTime[v] = Time;
	color[v] = 'b';
	return;
}
