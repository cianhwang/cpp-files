// MST
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
	int v;
	vector<Edge> neighbors;
};
class Graph {
public:
	Node *nodeList;
};

void primMST(Graph G, int n);
void updateFringe(vector<int> pq, Graph G, int v, char *color);
void Insert(vector<Edge> pq, int v, int weight);
Edge getMin(vector<Edge> &pq); //get and delete
int getPriority(vector<Edge> pq, int w);
void decreaseKey(vector<Edge> pq, int w, int Wgt);


int main()
{
	// input

	// output

	system("pause");
	return 0;
}

void primMST(Graph G, int n) {
	vector<Edge> pq;
	char *color = new char[n];
	for (int i = 0; i < n; ++i) { color[i] = 'w'; }
	int v = 0;
	// add edge

	Insert(pq, v, 0);
	color[v] = 'g';
	while (!pq.empty()) {
		v = getMin(pq).w; // and deleteMin(pq);
		// add edge

		color[v] = 'b';
		updateFringe(pq, G, v, color);
	}
}

void updateFringe(vector<Edge> pq, Graph G, int v, char *color) {
	vector<Edge> remAdj = G.nodeList[v].neighbors;
	while (!remAdj.empty()) {
		int w = remAdj.back().w;
		int Wgt = remAdj.back().weight;
		if (color[w] == 'w') {
			// add edge

			Insert(pq, w, Wgt);
			color[w] = 'g';
		}
		else {
			if (Wgt < getPriority(pq, w)) {
				// revise edge
				
				decreaseKey(pq, w, Wgt);
			}
		}
		remAdj.pop_back();
	}
}

void Insert(vector<Edge> pq, int v, int weight) {
	Edge e; e.w = v; e.weight = weight;
	pq.push_back(e);
	return;
}

Edge getMin(vector<Edge> &pq) {
	int Max = 0;
	int wMax = 0;
	int Idx = 0;
	for (int i = 0; i < pq.size(); ++i) {
		if (pq[i].weight > Max) {
			Max = pq[i].weight;
			wMax = pq[i].w;
			Idx = i;
		}
	}
	pq.erase(pq.begin() + Idx);
	Edge e; e.w = wMax; e.weight = Max;
	return e;
}

int getPriority(vector<Edge> pq, int w) {
	int i;
	for (i = 0; i < pq.size(); ++i) {
		if (pq[i].w == w)
			return pq[i].weight;
	}
}

void decreaseKey(vector<Edge> pq, int w, int Wgt) {
	int i;
	for (i = 0; i < pq.size(); ++i) {
		if (pq[i].w == w) {
			pq[i].weight = Wgt;
			return;
		}
	}
}