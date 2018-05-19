// 0 1 0 2 0 5 1 2 1 3 3 0 3 2 4 2 4 6 5 0 6 4 6 3 - Undirected DFS
// 0 3 3 5 5 0 5 4 4 1 1 2 2 4 1 6 6 8 8 1 5 7 7 0 5 9 9 3 --Slice 3
//
//问题 A : 割点与桥
//时间限制 : 1 Sec  内存限制 : 5 MB
//	提交 : 624  解决 : 54
//
//	题目描述
//	给出一个无向连通图，找到所有的割点和桥
//	输入
//	第一行：点的个数，如果点个数是n，他们的编号为0 ~n - 1
//
//	余下的行：每行代表一条边，如“0 2”代表顶点0和顶点2有一条边(一条边只出现一次，如出现“0 2”则不会出现“2 0”)
//
//
//	输出
//	这次需要大家先输出一个字符串，它是“我已阅读关于抄袭的说明”的汉语拼音.输出此行的提交我们将认为已经完全阅读并了解了“关于抄袭的说明”公告.
//
//	所有的割点和所有的桥，先输出割点再输出桥
//
//	割点按编号升序排列，桥按边的升序排列，如“0 2”小于“0 3”，“1 5”小于“2 3”（边的输出和排列总是把小顶点放前面，所以输出总是“0 2”而非“2 0”）
//
//	样例输入
//	5
//	1 2
//	1 3
//	2 4
//	0 1
//	0 2
//	样例输出
//	wo yi yue du guan yu chao xi de shuo ming
//	1
//	2
//	1 3
//	2 4
//	提示
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