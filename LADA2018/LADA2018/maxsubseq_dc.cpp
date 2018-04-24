//问题 A: 最大子序列和问题

//分治算法 O(nlogn)

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int maxSumSeq(int *, int, int&, int&);
int Max(int, int);
//int arrSum(int *, int, int);
// 1 2 2 3 3 4 -100 1 2 3 4
// 没考虑...
// 10 -1 | 20 -25 21
int main()
{
	int num;
	vector<int> v;
	while (cin >> num)
		v.push_back(num);
	int n = v.size();
	int *arr = new int[n];
	// input
	for (int i = 0; i < n; ++i) {
		arr[i] = v[i];
	}
	v.clear();

	int head, rear;
	cout << maxSumSeq(arr, n, head, rear) << endl;
	//cout << head << ' ' << rear << endl;
	system("PAUSE");
	return 0;
}

int maxSumSeq(int *arr, int n, int &head, int &rear) {
	// rear为数组末尾后一位
	if (n == 1) {
		head = 0; rear = 1;
		return arr[0];
	}
	int head1, head2, rear1, rear2;
	int Left = maxSumSeq(arr, n / 2, head1, rear1);
	int Right = maxSumSeq(arr + n / 2, n - n / 2, head2, rear2);
	if (Left < Right){
		head = n / 2 + head2; rear = n / 2 + rear2;
	}
	else {
		head = head1; rear = rear1;
	}

	//indicate that the interval between rear1 and head2(+n/2) not simply
	//add up. Inside elements may effectuate.
	int tempMax = Max(Left, Right);
	int tempLeftCross = Left, tempRightCross = Right;
	for (int i = rear1; i < n / 2 + rear2; ++i) {
		tempLeftCross += arr[i];
		if (tempLeftCross > tempMax) {
			tempMax = tempLeftCross;
			head = head1;
			rear = i + 1;
		}
	}
	for (int i = n / 2 + head2 - 1; i > head1 - 1; --i) {
		tempRightCross += arr[i];
		if (tempRightCross > tempMax) {
			tempMax = tempRightCross;
			rear = n / 2 + rear2;
			head = i;
		}
	}
	return tempMax;
}

int Max(int a, int b) {
	if (a < b)
		a = b;
	return a;
}
