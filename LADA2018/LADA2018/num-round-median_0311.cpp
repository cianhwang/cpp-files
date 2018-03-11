// Quicksort should be practiced more.
// ��λ������2k+1����
//��Ŀ����
//����һ�������� A1, A2, ..., AN �Լ�һ����С�ĳ��� K���ҳ��⴮������λ�� M ����ӽ� M ��С�ڵ��� M �� K �������Լ���ӽ� M �Ĵ��ڵ��� M �� K ���������� 2K + 1 ��������������������
//
//
//��λ�����壺��������Ĵ�С��ż�� 2J����λ���Ǵ�С�������еĵ� J ��������������Ĵ�С������ 2J + 1����λ���Ǵ�С�������еĵ� J + 1 ������
//
//����
//��һ���� K ��ֵ�������ĳ��� N��
//
//�ڶ������Կո������ N �������������һ���������пո�
//
//���
//���������е� 2K + 1 �������Կո�ֿ������һ��������û�пո񡣽�����ܳ����ظ�������
//��������
//2 10
//7 2 5 7 2 10 7 7 13 15
//�������
//5 7 7 7 7

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

void Swap(int &a, int &b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int main()
{
	int k, n;
	cin >> k >> n;
	int *p = new int[n];
	for (int i = 0; i < n; ++i){
		cin >> *(p + i);
	}
	// bubble: REVIEW
	//for (int i = 1; i < n; ++i){
	//	for (int j = i; j > 0; --j){
	//		if (p[j] < p[j - 1])
	//			Swap(p[j], p[j - 1]);
	//	}
	//}
	sort(p, p + n);
	// output
	int m = (n + 1) / 2;
	for (int i = 0; i < 2 * k; ++i) {
		cout << p[i + m - k -1] << ' ';
	}
	cout << p[m + k -1] << endl;
	system("pause");
    return 0;
}

