// 0 1 0 2 0 5 1 2 1 3 3 0 3 2 4 2 4 6 5 0 6 4 6 3 - Undirected DFS
// 0 3 3 5 5 0 5 4 4 1 1 2 2 4 1 6 6 8 8 1 5 7 7 0 5 9 9 3 --Slice 3
//
//���� A : �������
//ʱ������ : 1 Sec  �ڴ����� : 5 MB
//	�ύ : 624  ��� : 54
//
//	��Ŀ����
//	����һ��������ͨͼ���ҵ����еĸ�����
//	����
//	��һ�У���ĸ���������������n�����ǵı��Ϊ0 ~n - 1
//
//	���µ��У�ÿ�д���һ���ߣ��硰0 2��������0�Ͷ���2��һ����(һ����ֻ����һ�Σ�����֡�0 2���򲻻���֡�2 0��)
//
//
//	���
//	�����Ҫ��������һ���ַ��������ǡ������Ķ����ڳ�Ϯ��˵�����ĺ���ƴ��.������е��ύ���ǽ���Ϊ�Ѿ���ȫ�Ķ����˽��ˡ����ڳ�Ϯ��˵��������.
//
//	���еĸ������е��ţ����������������
//
//	��㰴����������У��Ű��ߵ��������У��硰0 2��С�ڡ�0 3������1 5��С�ڡ�2 3�����ߵ�������������ǰ�С�����ǰ�棬����������ǡ�0 2�����ǡ�2 0����
//
//	��������
//	5
//	1 2
//	1 3
//	2 4
//	0 1
//	0 2
//	�������
//	wo yi yue du guan yu chao xi de shuo ming
//	1
//	2
//	1 3
//	2 4
//	��ʾ
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Node {
public:
	int weight;
	vector<int> neighbors;
};

class Edge {
public:
	int a;
	int b;
};

void DFSsweep(Node *List, int n, int v, vector<int> &vertexSet, vector<Edge> &EdgeSet);
void DFS(Node *List, char *color, int v, int parent, int &Time, int *discoverTime, int &back, vector<int> &vertexSet, vector<Edge> &EdgeSet);
int Min(const int &a, const int &b){
	return (a < b) ? a : b;
}
bool cmp(Edge A, Edge B) {
	if (A.a != B.a)
		return A.a < B.a;
	else
		return A.b < B.b;
}

int main()
{
	int n = 0; cin >> n;
	Node *List = new Node[n];
	int idx = 0;
	while(cin >> idx) {
		int val = 0; cin >> val;
		List[idx].neighbors.push_back(val); //...
		List[val].neighbors.push_back(idx); //...
	}
	vector<int> vertexSet;
	vector<Edge> EdgeSet;
	DFSsweep(List, n, 0, vertexSet, EdgeSet);

	// output
	cout << "wo yi yue du guan yu chao xi de shuo ming" << endl;
	sort(vertexSet.begin(), vertexSet.end());
	for (int i = 0; i < vertexSet.size(); ++i) {
		cout << vertexSet[i] << endl;
	}
	sort(EdgeSet.begin(), EdgeSet.end(), cmp);
	for (int i = 0; i < EdgeSet.size(); ++i) {
		cout << EdgeSet[i].a << ' ' << EdgeSet[i].b << endl;
	}
	system("pause");
	return 0;
}

void DFSsweep(Node *List, int n, int v, vector<int> &vertexSet, vector<Edge> &EdgeSet) {
	char *color = new char[n];
	for (int i = 0; i < n; ++i) { color[i] = 'w'; }
	int *discoverTime = new int[n];
	int Time = 0;
	int back = 0;
	for (int i = 0; i < n; ++i) {
		if (color[(v + i) % n] == 'w')
			DFS(List, color, v + i, -1, Time, discoverTime, back, vertexSet, EdgeSet);
	}
	return;
}

void DFS(Node *List, char *color, int v, int parent, int &Time, int *discoverTime, int &back,
	vector<int> &vertexSet, vector<Edge> &EdgeSet) {
	int w;
	vector<int> remAdj;
	// Pre Processing
	++Time; discoverTime[v] = Time; back = Time;
	int Count = 0;
	color[v] = 'g';
	remAdj = List[v].neighbors;
	while (remAdj.size() != 0) {
		w = remAdj.front();
		if (color[w] == 'w') {
			// ...
			if (parent == -1) ++Count; // justify whether start point is a articulated point

			int wback = 0;
			DFS(List, color, w, v, Time, discoverTime, wback, vertexSet, EdgeSet);
			// backtrack
			if (wback >= discoverTime[v] && parent != -1)
				vertexSet.push_back(v);
			if (wback > discoverTime[v]) {
				Edge e; e.a = (v < w) ? v : w; e.b = v + w - e.a;
				EdgeSet.push_back(e);
			}
			back = Min(back, wback);
		}
		else if(color[w] = 'g' && w != parent){
			back = Min(back, discoverTime[w]);
		}
		remAdj.erase(remAdj.begin());
	}
	// Post Processing
	if (parent == -1 && Count > 1)
		vertexSet.push_back(v);
	color[v] = 'b';
	return;
}