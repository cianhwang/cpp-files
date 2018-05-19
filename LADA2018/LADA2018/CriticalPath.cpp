//���� B : �����������
//ʱ������ : 1 Sec  �ڴ����� : 5 MB
//	�ύ : 196  ��� : 48
//
//	��Ŀ����
//
//	��������oj��֮ǰ����ϸ�Ķ����ڳ�Ϯ��˵��http ://www.bigoh.net/JudgeOnline/.
//
//�㷨����ʵ����̫æ�ˣ�ÿ����n������Ҫ�������������Լ�һ��һ������ʵ����̫���ˣ���������һЩ���ϵ�ͬѧ����æһ������Щ�¡�
//
//�ڷ�������Ĺ����������֣���n����������һЩ����Ŀ�ʼ��Ҫ������һЩ�������ɣ����磬��ֻ�����������㷨��ҵ����Ϊ�¼�A�������ܸ���ҵǼ���ҵ�ɼ�����Ϊ�¼�B������ʱ���ǾͿɳ��¼�B�������¼�A�����ǵ����������㷨���ϵ�֪ʶ����������ͼ�еĽڵ�����ʾ��Щ�¼�����������ͼ�еı�����ʾ��Щ�¼���������ϵ�����磬���¼�B�������¼�Aʱ��ͼ�оʹ���һ����Bָ��A�ıߡ����̻�������������ͼ�������������ýڵ��Ȩֵ��ʾ���ÿ���¼�����Ҫ��ʱ�䡣
//
//Ȼ������������֣�����ͼ��������ϵ�Ĵ��ڣ���ʹ�������Ӵ�Ĺ�ϵ��������������ͬѧ��������Щ�£���������¼������ʱ��Ҳ��ȷ���ġ���ô�������ˣ�����ÿ��Ҫ������ʱ����������n�������أ���ʱ�������������㷨����ѧ���Ĺؼ�·���Ķ����ƺ��ܹ��������������⡣������ͬѧ�ǣ������ܸ�����������ʹ�ҵ����֣�ÿ��������n���������Ҳ��Ҫ���೤ʱ����
//
//�������������Ѿ������ǰ���Щ���齨ģ������ͼ����������ʾ����
//
//
//
//����
//
//��һ��Ϊͼ�еĶ������n
//
//�ڶ�������n + 1��Ϊÿ�����������¼���ţ��¼����Ϊ1��n������ɸ��¼������ʱ�䡣 �磬��1 50����������¼�1��Ҫ50����λʱ�䡣
//
//���µ����У�ÿһ�б�ʾһ��������ϵ�����磬��1 3�� ��ʾ�¼�1������������¼�3����ɡ�
//
//
//
//���
//���������Ҫ������һ���ַ����������ǡ������Ķ����ڳ�Ϯ��˵������Ӣ�ķ��룬����"I have read the rules about plagiarism punishment"��������е��ύ���ǽ���Ϊ�Ѿ���ȫ�Ķ����˽��ˡ����ڳ�Ϯ��˵�������沢ͬ����ڳ�Ϯ�ĳͷ���ʩ��
//
//�ڶ���������������n������������̵�ִ��ʱ�䡣
//
//��������
//9
//1 10
//2 6
//3 5
//4 1
//5 2
//6 3
//7 4
//8 9
//9 1
//1 9
//2 1
//2 8
//3 5
//3 6
//3 7
//4 2
//4 3
//5 9
//6 9
//7 9
//8 9
//
//�������
//I have read the rules about plagiarism punishment
//18
//��ʾ
//�����Щ���������ѭ����������������ԶҲ������������Щ�£��ò� TAT������������Դ󵨼ٶ�������Ҫ������Щ�����в�������ѭ��������Ҳ����˵�������ͼһ����һ�������޻�ͼ��
#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	int weight;
	vector<int> neighbors;
};

void DFSsweep(Node *List, int n, int *est, int *critPath);
void DFS(Node *List, char *color, int v, int *eft, int *critPath);

int main()
{
	int n = 0; cin >> n;
	Node *List = new Node[n];
	for (int i = 0; i < n; ++i) {
		int val = 0;  cin >> val;
		cin >> List[val - 1].weight;
	}
	int idx = 0;
	while(cin >> idx) {
		int val = 0; cin >> val;
		List[idx - 1].neighbors.push_back(val - 1); //...
	}
	int *eft = new int[n];
	int *critPath = new int[n];

	DFSsweep(List, n, eft, critPath);
	int eftMax = 0;
	int eftMaxIdx = -1;
	for (int i = 0; i < n; ++i) {
		if (eft[i] > eftMax)
		{
			eftMax = eft[i];
			eftMaxIdx = i;
		}
	}
	cout << "I have read the rules about plagiarism punishment" << endl;
	cout << eftMax << endl;

	system("pause");
	return 0;
}

void DFSsweep(Node *List, int n, int *eft, int *critPath) {
	char *color = new char [n];
	int v;
	for (v = 0; v < n; ++v) { color[v] = 'w'; }
	int Time = 0;
	for (v = 0; v < n; ++v) {
		if (color[v] == 'w')
			DFS(List, color, v, eft, critPath);
	}
	return;
}

void DFS(Node *List, char *color, int v, int *eft, int *critPath) {
	int w;
	vector<int> remAdj;
	// Pre Processing
	critPath[v] = -1;
	color[v] = 'g';
	remAdj = List[v].neighbors;
	int Max = 0;
	while (remAdj.size() != 0) {
		w = remAdj.front();
		if (color[w] == 'w') {
			DFS(List, color, w, eft, critPath);
			// backtrack
			if (eft[w] > Max) {
				critPath[v] = w; Max = eft[w];
			}
		}
		else {// For DE and CE
			if (eft[w] > Max) {
				critPath[v] = w; Max = eft[w];
			}
		}
		remAdj.erase(remAdj.begin());
	}
	// Post Processing
	eft[v] = Max + List[v].weight;
	color[v] = 'b';
	return;
}
