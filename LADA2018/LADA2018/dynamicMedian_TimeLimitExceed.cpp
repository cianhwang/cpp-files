//问题 A : 动态中位数问题
//时间限制 : 1 Sec  内存限制 : 8 MB
//	提交 : 538  解决 : 66
//
//	题目描述
//	输入一组整数a1, a2, …, an ，每输入一个整数，输出到此时为止的中位数。
//
//	中位数定义：如果数串的大小是偶数 2j，中位数是从小到大排列的第 j 个数；如果数串的大小是奇数 2j + 1，中位数是从小到大排列的第 j + 1 个数。
//
//	输入
//	一组整数，数字和数字之间以空格隔开。
//	输出
//	一组整数，数字和数字之间以空格隔开。最后一个数后面也有空格。
//
//	第 i 个输出的整数，是前 i 个输入的中位数。
//
//	样例输入
//	- 18 - 2 14 - 20 - 6 7 2 14 11 6
//	样例输出
//	- 18 - 18 - 2 - 18 - 6 - 6 - 2 - 2 2 2
//	提示
//
//	时间复杂度请不要超过O(nlogn)。
//	由于输入输出的量会比较大，因此推荐使用c语言中的scanf和printf函数来进行输入输出，能比c++中cin和cout节省许多时间。
//
//
//	这里本来有一行提示，但是由于老师上课不小心说漏嘴了，于是助教狠心地把它注释掉了 ；）
//
//
//	/*在处理该问题时，堆结构也许能给你带来意想不到的帮助。*/

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

void fixMaxHeap(vector<int> &);
void fixMinHeap(vector<int> &);

int main()
{
	vector<int> maxHeap;
	vector<int> minHeap;
	int num;
	int median;
	while (scanf_s("%d", &num) != EOF) {
		if (!maxHeap.size()) {
			maxHeap.push_back(num);
		}
		else if (median - num > 0) {
			if (maxHeap.size() > minHeap.size()) {
				minHeap.push_back(maxHeap[0]); //push_head??
				fixMinHeap(minHeap);

				maxHeap.erase(maxHeap.begin());
				fixMaxHeap(maxHeap);
				maxHeap.push_back(num);
				fixMaxHeap(maxHeap);
			}
			else {
				maxHeap.push_back(num);
				fixMaxHeap(maxHeap);
			}
		}
		else {
			if (maxHeap.size() > minHeap.size()) {
				minHeap.push_back(num);
				fixMinHeap(minHeap);
			}
			else {
				if (minHeap[0] < num) { // IMPORTANT!
					maxHeap.push_back(minHeap[0]); //push_head??
					fixMaxHeap(maxHeap);

					minHeap.erase(minHeap.begin());
					fixMinHeap(minHeap);
					minHeap.push_back(num);
					fixMinHeap(minHeap);
				}
				else {
					maxHeap.push_back(num);
					fixMaxHeap(maxHeap);
				}
			}
		}
		median = maxHeap[0];
		printf("%d ", median);
	}
	system("PAUSE");
	return 0;
}

void fixMaxHeap(vector<int> &maxHeap) {
	int n = maxHeap.size();
	while (n > 1 && maxHeap[n - 1] > maxHeap[n / 2 - 1]) {
		int temp = maxHeap[n - 1];
		maxHeap[n - 1] = maxHeap[n / 2 - 1];
		maxHeap[n / 2 - 1] = temp;
		n = n / 2;
	}
}

void fixMinHeap(vector<int> &minHeap) {
	int n = minHeap.size();
	while (n > 1 && minHeap[n - 1] < minHeap[n / 2 - 1]) {
		int temp = minHeap[n - 1];
		minHeap[n - 1] = minHeap[n / 2 - 1];
		minHeap[n / 2 - 1] = temp;
		n = n / 2;
	}
}