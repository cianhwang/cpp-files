//问题 B : 三数之和
//时间限制 : 1 Sec  内存限制 : 2 MB
//	提交 : 124  解决 : 59
//
//	题目描述
//	一个没有重复元素的整数数组，给定某个整数，找到所有triple之和等于该整数的个数，其中triple是数组中的不同的3个数。
//	输入
//	数组长度，以及要求的三数之和；
//
//	没有重复元素的数组。
//
//	输出
//	已阅读抄袭的说明；
//
//	所有triple的个数。
//
//	样例输入
//	6 3
//	8 0 - 5 - 2 6 - 1
//	样例输出
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