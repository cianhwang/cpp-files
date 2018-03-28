//问题 A : 最大子序列和问题
//时间限制 : 1 Sec  内存限制 : 4 MB
//	提交 : 194  解决 : 72
//
//	题目描述
//	给定一整数序列 a1, a2, …, an，求 a1~an 的一个子序列 ai~aj，使得从 ai 到 aj 的和最大。
//	只需要求出最大子序列的和，而不需要求出最大的那个序列。
//
//	输入
//	一组整数，数字和数字之间以空格隔开。
//	输出
//	该整数序列中最大子序列的和
//	样例输入
//	- 2 11 - 4 13 - 5 - 2
//	样例输出
//	20
//	提示
//
//	应用穷举法可以得到 O(n3) 的算法，优化它即可得到 O(n2) 的算法。这两个算法将会超时。
//	利用分治的思想可以有 O(n*logn) 的算法。
//	也有聪明的算法，它的复杂度是 O(n) 的。
//	另请注意：输入多少个数是未知的。请思考如何处理。

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<long> arr;
	long num;
	while (cin >> num) {
		arr.push_back(num);
	}
	vector<long> arr2, arr3;
	//merge
	long MaxNeg = INT32_MIN; // all negative inputs
	for (long i = 0; i < arr.size(); ++i) {
		if (MaxNeg < arr[i])
			MaxNeg = arr[i];
		if (arr[i] != 0)
			arr3.push_back(arr[i]);
	}
	arr.clear();

	long tempSum = 0;
	for (long i = 0; i < arr3.size(); ++i) {
		if (MaxNeg < arr3[i])
			MaxNeg = arr3[i];
		tempSum += arr3[i];
		if (i < arr3.size() - 1 && arr3[i] * arr3[i + 1] < 0) {
			if (arr2.size() != 0 || tempSum > 0)
				arr2.push_back(tempSum);
			tempSum = 0;
		}
	}
	if (tempSum > 0)
		arr2.push_back(tempSum);
	arr3.clear();
	//for (auto it = arr2.cbegin(); it != arr2.cend(); ++it) {
	//	cout << *it << ' ';
	//}
	long n = arr2.size();
	//process
	long Max = 0; //Max maintain update anytime！ if input is 8 -2 1, if not update promptly, ...
	for (long i = 0; i < n; i += 2) {
		if (i == 0) {
			if (Max < tempSum)
				Max = tempSum;
			tempSum = arr2[0];
		}
		else if (i > 0 && tempSum + arr2[i - 1] > 0){
			if (Max < tempSum)
				Max = tempSum;
			tempSum += arr2[i - 1] + arr2[i];
		}
		else {
			if (Max < tempSum) 
				Max = tempSum;
			tempSum = arr2[i];
		}
	}
	if (Max < tempSum)
		Max = tempSum;
	if (MaxNeg < 0)
		Max = MaxNeg;
	cout << Max << endl;

	arr2.clear();
	system("PAUSE");
	return 0;
}