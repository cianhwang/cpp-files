// Quicksort should be practiced more.
// 中位数附近2k+1个数
//题目描述
//给出一串整型数 A1, A2, ..., AN 以及一个较小的常数 K，找出这串数的中位数 M 和最接近 M 的小于等于 M 的 K 个数，以及最接近 M 的大于等于 M 的 K 个数。将这 2K + 1 个数按升序排序后输出。
//
//
//中位数定义：如果数串的大小是偶数 2J，中位数是从小到大排列的第 J 个数；如果数串的大小是奇数 2J + 1，中位数是从小到大排列的第 J + 1 个数。
//
//输入
//第一行是 K 的值和数串的长度 N。
//
//第二行是以空格隔开的 N 个整型数，最后一个数后面有空格。
//
//输出
//按升序排列的 2K + 1 个数，以空格分开，最后一个数后面没有空格。结果可能出现重复的数。
//样例输入
//2 10
//7 2 5 7 2 10 7 7 13 15
//样例输出
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

