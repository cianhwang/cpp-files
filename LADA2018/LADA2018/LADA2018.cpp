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

void Dijkstra(Graph &G, int n, int v, int endPoint);
void updateFringe(vector<Edge> &pq, Graph G, int v, int vWgt, char *color, int *hashTable);
void Insert(vector<Edge> &pq, int v, int weight, int *hashTable);
Edge getMin(vector<Edge> &pq, int *hashTable); //get and delete
Edge getPriority(vector<Edge> &pq, int w, int *hashTable);
void decreaseKey(vector<Edge> &pq, int w, int Wgt, int *hashTable);
int Max(int a, int b) { return (a > b) ? a : b; }
int Min(int a, int b) { return (a < b) ? a : b; }
void Swap(Edge &a, Edge &b, int *hashTable) {
	int tmp = hashTable[a.w]; hashTable[a.w] = hashTable[b.w]; hashTable[b.w] = tmp;
	Edge temp = a; a = b; b = temp; 
}
void fixHeap(vector<Edge> &pq, int *hashTable);
void extractHeapHead(vector<Edge> &pq, int *hashTable);

int main()
{
	// input
	Graph G;
	int n = 0; cin >> n;
	int s, t; cin >> s >> t;
	G.nodeList = new Node[n];
	int V, W, WEIGHT;

	while (scanf_s("%d %d %d", &WEIGHT, &V, &W) != EOF) {
		Edge e1; e1.w = W; e1.weight = WEIGHT;
		Edge e2; e2.w = V; e2.weight = WEIGHT;
		G.nodeList[V].neighbors.push_back(e1);
		G.nodeList[W].neighbors.push_back(e2);
	}

	cout << "I have read the rules about plagiarism punishment" << endl;
	Dijkstra(G, n, s, t);

	system("pause");
	return 0;
}

void Dijkstra(Graph &G, int n, int v, int endPoint) {
	int *hashTable = new int[n]; for (int i = 0; i < n; ++i) { hashTable[i] = -1; }
	vector<Edge> pq;
	char *color = new char[n];
	for (int i = 0; i < n; ++i) { color[i] = 'w'; }
	int vWgt = 0;
	Insert(pq, v, 0, hashTable);
	color[v] = 'g';
	while (!pq.empty()) {
		Edge e = getMin(pq, hashTable); // and deleteMin(pq);
		v = e.w; vWgt = e.weight;
		// add edge
		//cout << v << ' ' << vWgt << endl;
		if (v == endPoint) {
			cout << vWgt << endl; return;
		}
		color[v] = 'b';
		updateFringe(pq, G, v, vWgt, color, hashTable);
	}
	return;
}

void updateFringe(vector<Edge> &pq, Graph G, int v, int vWgt, char *color, int *hashTable) {
	vector<Edge> remAdj = G.nodeList[v].neighbors;
	while (!remAdj.empty()) {
		int w = remAdj.back().w;
		int wWgt = Max(remAdj.back().weight, vWgt);
		if (color[w] == 'w') {
			// add edge
			Insert(pq, w, wWgt, hashTable);
			color[w] = 'g';
		}
		else if (color[w] == 'g') {
			Edge eee = getPriority(pq, w, hashTable);
			if (wWgt < eee.weight) {
				decreaseKey(pq, w, wWgt, hashTable);
			}
		}
		remAdj.pop_back();
	}
}

void Insert(vector<Edge> &pq, int v, int weight, int *hashTable) {
	Edge e; e.w = v; e.weight = weight;
	pq.push_back(e);
	hashTable[v] = pq.size() - 1;
	fixHeap(pq, hashTable);
	return;
}

Edge getMin(vector<Edge> &pq, int *hashTable) {
	//int Min = pq.front().weight;
	//int wMin = pq.front().w;
	//int Idx = 0;
	//for (int i = 0; i < pq.size(); ++i) {
	//	if (pq[i].weight < Min) {
	//		Min = pq[i].weight;
	//		wMin = pq[i].w;
	//		Idx = i;
	//	}
	//}
	//pq.erase(pq.begin() + Idx);
	//Edge e; e.w = wMin; e.weight = Min;
	//pop_heap(pq.begin(), pq.end(), cmp);
	//Edge e = pq.back(); pq.pop_back();
	Edge e = pq.front();
	extractHeapHead(pq, hashTable);
	return e;
}

Edge getPriority(vector<Edge> &pq, int w, int *hashTable) {
	return pq[hashTable[w]];
}

void decreaseKey(vector<Edge> &pq, int w, int Wgt, int *hashTable) {
	pq.erase(pq.begin() + hashTable[w]);	
	hashTable[w] = -1;
	Edge eTmp; eTmp.w = w; eTmp.weight = Wgt;
	Insert(pq, w, Wgt, hashTable);
}

void fixHeap(vector<Edge> &pq, int *hashTable) {
	int n = pq.size();
	while (n > 1 && pq[n - 1].weight < pq[n / 2 - 1].weight) {
		Swap(pq[n - 1], pq[n / 2 - 1], hashTable);
		n = n / 2;
	}
}

void extractHeapHead(vector<Edge> &pq, int *hashTable) {
	int i = 0;
	pq[0] = pq.back();
	hashTable[pq[0].w] = 0;
	pq.pop_back();

	while (2 * i + 2 < pq.size() &&
		pq[i].weight > Min(pq[2 * i + 1].weight, pq[2 * i + 2].weight)) {
		if (pq[2 * i + 1].weight > pq[2 * i + 2].weight) {
			Swap(pq[i], pq[2 * i + 2], hashTable);
			i = i * 2 + 2;
		}
		else {
			Swap(pq[i], pq[2 * i + 1], hashTable);
			i = i * 2 + 1;
		}
	}
	if (2 * i + 1 < pq.size() && pq[i].weight > pq[2 * i + 1].weight) {
		Swap(pq[i], pq[2 * i + 1], hashTable);
	}
}
