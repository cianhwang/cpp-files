//���� B : ����֮��
//ʱ������ : 1 Sec  �ڴ����� : 2 MB
//	�ύ : 124  ��� : 59
//
//	��Ŀ����
//	һ��û���ظ�Ԫ�ص��������飬����ĳ���������ҵ�����triple֮�͵��ڸ������ĸ���������triple�������еĲ�ͬ��3������
//	����
//	���鳤�ȣ��Լ�Ҫ�������֮�ͣ�
//
//	û���ظ�Ԫ�ص����顣
//
//	���
//	���Ķ���Ϯ��˵����
//
//	����triple�ĸ�����
//
//	��������
//	6 3
//	8 0 - 5 - 2 6 - 1
//	�������
//	wo yi yue du guan yu chao xi de shuo ming
//	2
//
#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

int existTempSum(int *head, int n, int Sum);

int main()
{
	int n = 0; cin >> n;
	int tripleSum = 0; cin >> tripleSum;
	int *arr = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	// O(nlogn + n^2)
	sort(arr, arr + n);
	int count = 0;
	for (int i = 0; i < n - 2; ++i) {
		int tempSum = tripleSum - arr[i];
		count += existTempSum(arr + i + 1, n - i - 1, tempSum);
	}
	cout << "wo yi yue du guan yu chao xi de shuo ming" << endl;
	cout << count << endl;

	delete[]arr;
	system("PAUSE");
	return 0;
}

int existTempSum(int *arr, int n, int Sum) {
	int *head = arr;
	int *rear = arr + n - 1;
	int count = 0;
	while (head < rear) {
		if (*head + *rear == Sum)
			++count;
		if (*head + *rear < Sum)
			++head;
		else
			--rear;
	}
	return count;
}