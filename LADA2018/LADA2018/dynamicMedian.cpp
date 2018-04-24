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

void fixMaxHeap(vector<int> &); //add a new value in the rear;
void fixMinHeap(vector<int> &);
void fMaxH_HEAD(vector<int> &); //adjust from the top;
void fMinH_HEAD(vector<int> &);
int Max(int, int);
int Min(int, int);
void Swap(int &, int &);

//structure: minHeap(with top > median and other values > top)
//				|
//			  median
//				|
//			 maxHeap(with top = median and other values < top)
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
		else if (median - num > 0) { //new value should be placed in maxHeap.
			if (maxHeap.size() > minHeap.size()) {
				minHeap.push_back(maxHeap[0]); //push_head??
				fixMinHeap(minHeap);

				maxHeap[0] = num;
				fMaxH_HEAD(maxHeap);
			}
			else {
				maxHeap.push_back(num);
				fixMaxHeap(maxHeap);
			}
		}
		else { // whether should be placed in maxHeap or minHeap
			if (maxHeap.size() > minHeap.size()) {
				minHeap.push_back(num);
				fixMinHeap(minHeap);
			}
			else {
				if (minHeap[0] < num) { // IMPORTANT!
					maxHeap.push_back(minHeap[0]); //push_head??
					fixMaxHeap(maxHeap);

					minHeap[0] = num;
					fMinH_HEAD(minHeap);
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

int Max(int a, int b) {
	return (a > b) ? a : b;
}

int Min(int a, int b) {
	return (a < b) ? a : b;
}

void Swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
	return;
}

void fixMaxHeap(vector<int> &maxHeap) {
	int n = maxHeap.size();
	while (n > 1 && maxHeap[n - 1] > maxHeap[n / 2 - 1]) {
		Swap(maxHeap[n - 1], maxHeap[n / 2 - 1]);
		n = n / 2;
	}
}

void fixMinHeap(vector<int> &minHeap) {
	int n = minHeap.size();
	while (n > 1 && minHeap[n - 1] < minHeap[n / 2 - 1]) {
		Swap(minHeap[n - 1], minHeap[n / 2 - 1]);
		n = n / 2;
	}
}

void fMaxH_HEAD(vector<int> &maxHeap) {
	int i = 0;
	while (2 * i + 2 < maxHeap.size() && maxHeap[i] < Max(maxHeap[2 * i + 1], maxHeap[2 * i + 2])) {
		if (maxHeap[2 * i + 1] < maxHeap[2 * i + 2]) {
			Swap(maxHeap[i], maxHeap[2 * i + 2]);
			i = 2 * i + 2;
		}
		else {
			Swap(maxHeap[i], maxHeap[2 * i + 1]);
			i = 2 * i + 1;
		}
	}
	if (2 * i + 1 < maxHeap.size() && maxHeap[i] < maxHeap[2*i+1]) {
		Swap(maxHeap[i], maxHeap[2 * i + 1]);
	}
}

void fMinH_HEAD(vector<int> &minHeap) {
	int i = 0;
	while (2 * i + 2 < minHeap.size() && minHeap[i] > Min(minHeap[2 * i + 1], minHeap[2 * i + 2])) {
		if (minHeap[2 * i + 1] > minHeap[2 * i + 2]) {
			Swap(minHeap[i], minHeap[2 * i + 2]);
			i = i * 2 + 2;
		}
		else {
			Swap(minHeap[i], minHeap[2 * i + 1]);
			i = i * 2 + 1;
		}
	}
	if (2 * i + 1 < minHeap.size() && minHeap[i] > minHeap[2 * i + 1]) {
		Swap(minHeap[i], minHeap[2 * i + 1]);
	}
}