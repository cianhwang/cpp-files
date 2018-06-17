//问题 A : 有向无环图中的最长路径
//时间限制 : 1 Sec  内存限制 : 16 MB
//	提交 : 595  解决 : 83
//
//	题目描述
//	做题前请先阅读首页关于抄袭的说明。
//	给定一个带权有向图无环图G，求某一点到其他所有点的最长路径。
//
//	输入
//	第一行为一个数字n，表示总点数。之后点的标号为从0到n - 1。
//
//	之后的每一行，格式为3个数字，以空格隔开，分别为相连的两个点的编号，它们的边的权值。
//
//	注：输入为有向图。如果出现了“0 1 50”表示点0到点1之间有一条边，权值为50。
//
//	输出
//
//	这次依旧需要大家输出一行字符串，它还是“我已阅读关于抄袭的说明”的英文翻译，即："I have read the rules about plagiarism punishment"。输出此行的提交我们将认为已经完全阅读并了解了“关于抄袭的说明”公告并同意关于抄袭的惩罚措施。
//
//	点0到其他所有点的最长路径，以空格隔开。注：点0到其他所有点都是可达的。
//
//	样例输入
//	6
//	0 1 1
//	0 3 2
//	1 2 6
//	2 4 1
//	2 5 2
//	3 4 3
//	3 1 4
//	4 5 1
//	样例输出
//	I have read the rules about plagiarism punishment
//	6 12 2 13 14
//	提示
//
//	线性时间复杂度O(m + n)
//	节省时间、空间可以尝试将cin输入换成scanf输入，如果你使用了cin的话。
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
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

enum Color { White, Gray, Black };

void DFSsweep(Node *List, int n, int v, int *finishTime);
void DFS(Node *List, Color *color, int v, int *finishTime, int &Time);
void CalcMaxPath(Node *List2, int *hahaha, int i);

int main()
{
	int n = 0; cin >> n;
	Node *List = new Node[n];	Node *List2 = new Node[n];
	int v, w, wgt;
	while (scanf_s("%d %d %d", &v, &w, &wgt) != EOF) {
		Edge e; e.w = w; e.weight = wgt;
		Edge e2; e2.w = v; e2.weight = wgt;
		//List[v].neighbors.push_back(e);
		List2[w].neighbors.push_back(e2);
	}

	//int *finishTime = new int[n];
	//DFSsweep(List, n, 0, finishTime);
	int *hahaha = new int[n];
	for (int i = 0; i < n; ++i) { hahaha[i] = -1; }

	for (int i = 0; i < n; ++i) {
		if (hahaha[i] == -1) {
			CalcMaxPath(List2, hahaha, i);
		}
	}
	cout << "I have read the rules about plagiarism punishment" << endl;
	for (int i = 1; i < n; ++i) {
		cout << hahaha[i] << ' ';
	}

	// output

	system("pause");
	return 0;
}

void DFSsweep(Node *List, int n, int v, int *finishTime) {
	Color *color = new Color[n];
	for (int i = 0; i < n; ++i) { color[i] = White; }
	int Time = 0;
	for (int i = 0; i < n; ++i) {
		if (color[(v + i) % n] == White)
			DFS(List, color, v + i, finishTime, Time);
	}
	return;
}

void DFS(Node *List, Color *color, int v, int *finishTime, int &Time) {
	int w;
	vector<Edge> remAdj;
	// Pre Processing

	color[v] = Gray;
	remAdj = List[v].neighbors; 
	while (remAdj.size() != 0) {
		w = remAdj.back().w;
		if (color[w] == White) {
			// ...
			DFS(List, color, w, finishTime, Time);
			// backtrack
		}
		else { // in DAG, no BE.
			;
		}
		remAdj.pop_back();
	}
	// Post Processing
	Time++; finishTime[v] = Time;
	color[v] = Black;
	return;
}

void CalcMaxPath(Node *List2, int *hahaha, int i) {
	vector<Edge> remAdj;
	remAdj = List2[i].neighbors;
	int TmpMax = 0;
	while (!remAdj.empty()) {
		Edge ee = remAdj.back();
		if (hahaha[ee.w] == -1)
			CalcMaxPath(List2, hahaha, ee.w);
		if (hahaha[ee.w] + ee.weight > TmpMax)
			TmpMax = hahaha[ee.w] + ee.weight;
		remAdj.pop_back();
	}
	hahaha[i] = TmpMax;
}
