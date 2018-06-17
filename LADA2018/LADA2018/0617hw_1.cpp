//问题 B : 汽车旅行问题
//时间限制 : 1 Sec  内存限制 : 18 MB
//	提交 : 591  解决 : 68
//
//	题目描述
//	经过一通计算，小雷同学最后还是乖乖听叔叔的话飞到了北京，开始了他快乐的旅程。在北京玩了一番之后，他决定租车去东三省进行自驾游，再回到北京飞去其他的城市。
//
//	小雷从爸爸手上得到了一份东三省的地图，上面标有若干城市，城市之间由高速公路连接。他按照老规矩把这份地图上的城市和公路用无向图进行了建模，每个城市为图中的一个顶点v，而每条公路e则是图中连接两个顶点的一条边，这样这份地图就变成了无向图G = (V, E)的样子。根据地图上的信息，每一条边e的长度le是已知的。
//
//	不幸的是，小雷发现在他的目的区域中，只有每座城市建有加油站，而高速公路上却没有，所以他在租车的时候，需要好好考虑租用车型的油箱容量。那么现在的问题是，油箱容量越大的车租金越贵，小雷希望能尽可能的省钱，但是若他想从某个城市s开车到另一个城市t，他需要确保路径上每段路e的长度le都小于等于油箱的容量L（在这里，为了方便比较，油箱容量L的单位用装满油箱能跑的公里数表示）。
//
//	同学们，你们能再帮小雷一次，替他算出要在地图上的城市之间进行自驾旅游，怎样才能用最少的钱租到最合适的车，而又不至于在两个城市间行驶时因为没油而无法继续旅行嘛？（即算出所需租用车的最小油箱容量L）。
//
//
//
//	输入
//	第一行依次是城市个数n，以及s和t的编号。城市编号从0开始。
//
//	下面每一行第一个数是高速公路长度，长度非负。后两个数是高速公路连接的城市编号。
//
//	s和t是存在通路的。
//
//	输出
//	这次依旧需要大家输出一行字符串，它还是“我已阅读关于抄袭的说明”的英文翻译，即："I have read the rules about plagiarism punishment"。输出此行的提交我们将认为已经完全阅读并了解了“关于抄袭的说明”公告并同意关于抄袭的惩罚措施。
//
//	第二行输出最小需要的油箱能跑过的距离L。
//
//	样例输入
//	6 1 5
//	5 0 1
//	1 1 2
//	2 2 3
//	2 0 4
//	2 1 4
//	2 2 5
//	4 3 5
//	1 4 5
//	样例输出
//	I have read the rules about plagiarism punishment
//	2
//	提示
//	使用 O((| V | +| E | ）log | V | ）的算法计算。

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
			Edge eTemp = getPriority(pq, w, hashTable);
			if (wWgt < eTemp.weight) {
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
