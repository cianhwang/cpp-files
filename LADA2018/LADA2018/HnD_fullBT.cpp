//���� B : �������������ĸ߶���ֱ��
//ʱ������ : 2 Sec  �ڴ����� : 3 MB
//	�ύ : 103  ��� : 53
//
//	��Ŀ����
//	��TΪһ�ö����������й���n���ڵ㡣
//
//	������ڵ�����Ϊ0������ڵ�����Ϊ�丸�ڵ����ȼ�1��T�ĸ߶ȶ���Ϊ��Ҷ�ڵ���ȵ����ֵ��
//
//	����������������a��b֮��ľ���Ϊ�����̼�·���ĳ��ȡ�T��ֱ������ΪT�����е�Լ��������ֵ��
//
//	����һ�ö�����T����������ĸ߶Ⱥ�ֱ����
//
//	����
//	���빲���С�
//
//	��һ������n��ֵ����ʾ���н����ܸ�����
//
//	�ڶ���Ϊ����ǰ�������ʾ��ÿ���ڵ�֮���ÿո������
//
//	������Ϊ�������������ʾ��ÿ���ڵ�֮��Ҳ�ÿո������
//
//	���
//	��������С�
//	��һ����Ҫ������һ���ַ��������ǡ������Ķ����ڳ�Ϯ��˵������Ӣ�ķ��룬����"I have read the rules about plagiarism punishment"��������е��ύ���ǽ���Ϊ�Ѿ���ȫ�Ķ����˽��ˡ����ڳ�Ϯ��˵�������沢ͬ����ڳ�Ϯ�ĳͷ���ʩ��
//	�ڶ���������ĸ߶ȡ�
//	�������������ֱ����
//
//
//
//	��������
//	10
//	0 1 9 3 8 4 2 7 5 6
//	3 9 8 1 2 4 0 5 7 6
//	�������
//	I have read the rules about plagiarism punishment
//	3
//	5
//	��ʾ
//	�����㷨������O(n)��ʱ���������Ӧ�ļ��㡣

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int treeDiameter(int* ahead, int* bhead, int *arear, int* brear, int &height);
int searchRear(int *arr, int value);
int Max(int, int, int);

int main()
{
	int n = 0; cin >> n;
	int *a = new int[n];
	int *b = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		cin >> b[i];

	int height = 0;
	int diameter = treeDiameter(a, b, a + n, b + n, height);
	cout << "I have read the rules about plagiarism punishment" << endl;
	cout << height << endl;
	cout << diameter;

	system("PAUSE");
	return 0;
}

int treeDiameter(int* ahead, int* bhead, int *arear, int* brear, int &height) {
	if (arear - ahead == 0 || arear - ahead == 1) {
		height = 0;
		return 0;
	}
	int idx = searchRear(bhead, ahead[0]);
	int hLeft, hRight;
	hLeft = hRight = 0;
	int leftDiameter = treeDiameter(ahead + 1, bhead, ahead + idx, bhead + idx - 1, hLeft);
	int rightDiameter = treeDiameter(ahead + idx, bhead + idx, arear, brear, hRight);
	height = Max(hLeft, hRight, 0) + 1;
	return Max(leftDiameter, rightDiameter, hLeft + hRight + 2);
}

//find the next postion of given value
int searchRear(int *arr, int value) {
	int i = 0;
	while (arr[i] != value)
		++i;
	return ++i;
}

int Max(int a, int b, int c) {
	if (a > b) {
		if (c > a)
			a = c;
	}
	else {
		if (b < c)
			a = c;
		else
			a = b;
	}
	return a;
}



