// 问题 C: 任意两数之和是否等于给定数
//题目描述
//给定一个 int 数组 arr，元素按照升序排列且各不相同。另外有一个目标数 c，请你找出 arr 中所有的数对 a, b，使得 a + b = c。
//输入
//输入为三行，第一行为 arr 的元素个数，第二行为 arr，元素以空格分隔，第三行为目标数 c。
//输出
//所有符合条件的数对 a, b。a 和 b 以空格分开，每个数对占据一行。每行中 a < b，所有数对以它的第一个数（也就是 a 的值）升序排列。
//	样例输入
//	9
//	- 2 0 1 2 3 5 6 8 10
//	8
//	样例输出
//	- 2 10
//	0 8
//	2 6
//	3 5

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int n;	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	int c;	cin >> c;
	int *p = arr;
	int *q = arr + n - 1;
	while (p < q) {
		while (*p + *q > c)
			--q;
		if (c == (*p + *q))
			cout << *p << ' ' << *q << endl;
		++p;
	}

	system("pause");
    return 0;
}

