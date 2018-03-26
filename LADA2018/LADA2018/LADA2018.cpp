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
	vector<int> arr;
	int num;
	while (cin >> num) {
		arr.push_back(num);
	}
	int n = arr.size();
	int pointer = 0, tempSum = 0;
	int bigNeg = INT32_MIN; //prevent all inputs are negative.
	for (int i = 0; i < n - 1; ++i) {
		if (arr[i] < 0 && arr[i] > bigNeg)
			bigNeg = arr[i];
		if (arr[i] == 0) continue;
		tempSum += arr[i];
		if (arr[i] * arr[i + 1] <= 0) { // deal with 0 --- 0 1 2 3 0 -1 -2 0 -3 1 2 3 -1
			if (pointer > 0 && tempSum * arr[pointer - 1] > 0)
				arr[pointer - 1] += tempSum;
			else 
				arr[pointer++] = tempSum;
			tempSum = 0;
		}
	}
	if ((tempSum + arr[n - 1]) != 0)
		arr[pointer++] = tempSum + arr[n - 1];

	for (int i = 0; i < n - pointer; ++i)
		arr.pop_back();


	if (arr.size() != 0 && arr[arr.size() - 1] < 0)
		arr.pop_back();
	if (arr[0] < 0)
		arr.erase(arr.begin());

	n = arr.size();

	//for (auto it = arr.cbegin(); it != arr.cend(); ++it) {
	//	cout << *it << ' ';
	//}
/*	int Max = 0, tempMax = 0, i = 0;
	while (i < n) //Wrong Algorithm
	{
		if (i == 0 && arr[i] < 0) {
			++i;
			continue;
		}
		tempMax = arr[i];
		while (i + 2 < n && arr[i + 1] + arr[i + 2] >= 0) {
			tempMax += (arr[i + 1] + arr[i + 2]);
			i += 2;
		} // Why there is no further margin constraint?

		if (Max < tempMax)
			Max = tempMax;
		i += 2;
	}	*/
	int tempMax, Max = 0;
	for (int i = 0; i < (n + 1) / 2; ++i) {
		if (i == 0) {
			Max = tempMax = arr[0];
			continue;
		}
		if (tempMax + arr[i * 2 - 1] > 0){
			tempMax += arr[i * 2 - 1];
		}
		else {
			if (Max < tempMax)
				Max = tempMax;
			tempMax = 0;
		}
		tempMax += arr[i * 2];
	}
	if (Max < tempMax)
		Max = tempMax;

	if (n == 0 && bigNeg != INT32_MIN)
		std::cout << bigNeg << endl;
	else
		std::cout << Max << endl;

	arr.clear();

	std::system("PAUSE");
	return 0;
}