//���� A : �����޻�ͼ�е��·��
//ʱ������ : 1 Sec  �ڴ����� : 16 MB
//	�ύ : 595  ��� : 83
//
//	��Ŀ����
//	����ǰ�����Ķ���ҳ���ڳ�Ϯ��˵����
//	����һ����Ȩ����ͼ�޻�ͼG����ĳһ�㵽�������е���·����
//
//	����
//	��һ��Ϊһ������n����ʾ�ܵ�����֮���ı��Ϊ��0��n - 1��
//
//	֮���ÿһ�У���ʽΪ3�����֣��Կո�������ֱ�Ϊ������������ı�ţ����ǵıߵ�Ȩֵ��
//
//	ע������Ϊ����ͼ����������ˡ�0 1 50����ʾ��0����1֮����һ���ߣ�ȨֵΪ50��
//
//	���
//
//	���������Ҫ������һ���ַ����������ǡ������Ķ����ڳ�Ϯ��˵������Ӣ�ķ��룬����"I have read the rules about plagiarism punishment"��������е��ύ���ǽ���Ϊ�Ѿ���ȫ�Ķ����˽��ˡ����ڳ�Ϯ��˵�������沢ͬ����ڳ�Ϯ�ĳͷ���ʩ��
//
//	��0���������е���·�����Կո������ע����0���������е㶼�ǿɴ�ġ�
//
//	��������
//	6
//	0 1 1
//	0 3 2
//	1 2 6
//	2 4 1
//	2 5 2
//	3 4 3
//	3 1 4
//	4 5 1
//	�������
//	I have read the rules about plagiarism punishment
//	6 12 2 13 14
//	��ʾ
//
//	����ʱ�临�Ӷ�O(m + n)
//	��ʡʱ�䡢�ռ���Գ��Խ�cin���뻻��scanf���룬�����ʹ����cin�Ļ���
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
