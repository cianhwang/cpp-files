// Dijkstra
//8 
//0 1 2 0 2 7 0 3 1 0 5 3
//1 3 2 1 4 5 1 5 1
//2 3 8 2 6 2 2 7 4
//3 4 7 3 6 4
//4 5 3 4 6 3 4 7 4
//5 7 6
//6 7 5

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

class Edge {
public:
	int w;
	int weight;
};
class Node {
public:
	vector<Edge> neighbors;
};
class Graph {
public:
	Node *nodeList;
};

void Dijkstra(Graph G, int n, int v);
void updateFringe(vector<Edge> &pq, Graph G, int v, int vWgt, char *color);
void Insert(vector<Edge> &pq, int v, int weight);
Edge getMin(vector<Edge> &pq); //get and delete
int getPriority(vector<Edge> pq, int w);
void decreaseKey(vector<Edge> &pq, int w, int Wgt);


int main()
{
	// input
	Graph G;
	int n = 0; cin >> n;
	G.nodeList = new Node[n];
	int V, W, WEIGHT;

	while (cin >> V >> W >> WEIGHT) {
		Edge e1; e1.w = W; e1.weight = WEIGHT;
		Edge e2; e2.w = V; e2.weight = WEIGHT;
		G.nodeList[V].neighbors.push_back(e1);
		G.nodeList[W].neighbors.push_back(e2);
	}
	int startPoint = 3;
	Dijkstra(G, n, startPoint);

	system("pause");
	return 0;
}

void Dijkstra(Graph G, int n, int v) {
	vector<Edge> pq;
	char *color = new char[n];
	for (int i = 0; i < n; ++i) { color[i] = 'w'; }
	int vWgt = 0;
	Insert(pq, v, 0);
	color[v] = 'g';
	while (!pq.empty()) {
		Edge e = getMin(pq); // and deleteMin(pq);
		v = e.w; vWgt = e.weight;
		// add edge
		cout << v << ' ' << vWgt << endl;
		color[v] = 'b';
		updateFringe(pq, G, v, vWgt, color);
	}
}

void updateFringe(vector<Edge> &pq, Graph G, int v, int vWgt, char *color) {
	vector<Edge> remAdj = G.nodeList[v].neighbors;
	while (!remAdj.empty()) {
		int w = remAdj.back().w;
		int wWgt = remAdj.back().weight + vWgt;
		if (color[w] == 'w') {
			// add edge
			Insert(pq, w, wWgt);
			color[w] = 'g';
		}
		else if (color[w] == 'g'){
			if (wWgt < getPriority(pq, w)) {
				// revise edge
				decreaseKey(pq, w, wWgt);
			}
		}
		remAdj.pop_back();
	}
}

void Insert(vector<Edge> &pq, int v, int weight) {
	Edge e; e.w = v; e.weight = weight;
	pq.push_back(e);
	return;
}

Edge getMin(vector<Edge> &pq) {
	int Min = pq.front().weight;
	int wMin = pq.front().w;
	int Idx = 0;
	for (int i = 0; i < pq.size(); ++i) {
		if (pq[i].weight < Min) {
			Min = pq[i].weight;
			wMin = pq[i].w;
			Idx = i;
		}
	}
	pq.erase(pq.begin() + Idx);
	Edge e; e.w = wMin; e.weight = Min;
	return e;
}

int getPriority(vector<Edge> pq, int w) {
	int i;
	for (i = 0; i < pq.size(); ++i) {
		if (pq[i].w == w)
			return pq[i].weight;
	}
}

void decreaseKey(vector<Edge> &pq, int w, int Wgt) {
	int i;
	for (i = 0; i < pq.size(); ++i) {
		if (pq[i].w == w) {
			pq[i].weight = Wgt;
			return;
		}
	}
}