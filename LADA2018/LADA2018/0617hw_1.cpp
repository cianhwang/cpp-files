//���� B : ������������
//ʱ������ : 1 Sec  �ڴ����� : 18 MB
//	�ύ : 591  ��� : 68
//
//	��Ŀ����
//	����һͨ���㣬С��ͬѧ����ǹԹ�������Ļ��ɵ��˱�������ʼ�������ֵ��ó̡��ڱ�������һ��֮���������⳵ȥ����ʡ�����Լ��Σ��ٻص�������ȥ�����ĳ��С�
//
//	С�״Ӱְ����ϵõ���һ�ݶ���ʡ�ĵ�ͼ������������ɳ��У�����֮���ɸ��ٹ�·���ӡ��������Ϲ�ذ���ݵ�ͼ�ϵĳ��к͹�·������ͼ�����˽�ģ��ÿ������Ϊͼ�е�һ������v����ÿ����·e����ͼ���������������һ���ߣ�������ݵ�ͼ�ͱ��������ͼG = (V, E)�����ӡ����ݵ�ͼ�ϵ���Ϣ��ÿһ����e�ĳ���le����֪�ġ�
//
//	���ҵ��ǣ�С�׷���������Ŀ�������У�ֻ��ÿ�����н��м���վ�������ٹ�·��ȴû�У����������⳵��ʱ����Ҫ�úÿ������ó��͵�������������ô���ڵ������ǣ���������Խ��ĳ����Խ��С��ϣ���ܾ����ܵ�ʡǮ�������������ĳ������s��������һ������t������Ҫȷ��·����ÿ��·e�ĳ���le��С�ڵ������������L�������Ϊ�˷���Ƚϣ���������L�ĵ�λ��װ���������ܵĹ�������ʾ����
//
//	ͬѧ�ǣ��������ٰ�С��һ�Σ��������Ҫ�ڵ�ͼ�ϵĳ���֮������Լ����Σ��������������ٵ�Ǯ�⵽����ʵĳ������ֲ��������������м���ʻʱ��Ϊû�Ͷ��޷������������������������ó�����С��������L����
//
//
//
//	����
//	��һ�������ǳ��и���n���Լ�s��t�ı�š����б�Ŵ�0��ʼ��
//
//	����ÿһ�е�һ�����Ǹ��ٹ�·���ȣ����ȷǸ������������Ǹ��ٹ�·���ӵĳ��б�š�
//
//	s��t�Ǵ���ͨ·�ġ�
//
//	���
//	���������Ҫ������һ���ַ����������ǡ������Ķ����ڳ�Ϯ��˵������Ӣ�ķ��룬����"I have read the rules about plagiarism punishment"��������е��ύ���ǽ���Ϊ�Ѿ���ȫ�Ķ����˽��ˡ����ڳ�Ϯ��˵�������沢ͬ����ڳ�Ϯ�ĳͷ���ʩ��
//
//	�ڶ��������С��Ҫ���������ܹ��ľ���L��
//
//	��������
//	6 1 5
//	5 0 1
//	1 1 2
//	2 2 3
//	2 0 4
//	2 1 4
//	2 2 5
//	4 3 5
//	1 4 5
//	�������
//	I have read the rules about plagiarism punishment
//	2
//	��ʾ
//	ʹ�� O((| V | +| E | ��log | V | �����㷨���㡣

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
