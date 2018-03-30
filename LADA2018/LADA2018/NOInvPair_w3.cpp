//问题 B : 所有的逆序对
//时间限制 : 2 Sec  内存限制 : 5 MB
//	提交 : 313  解决 : 53
//
//	题目描述
//	请大家在做oj题之前，仔细阅读关于抄袭的说明http ://www.bigoh.net/JudgeOnline/.
//
//
//给出一个字符串数组，如果（按照字典序）一个大的字符串在比它小的字符串前面我们称这两个字符串组成一个“逆序对”。你需要找到所有的逆序对的个数。
//
//输入
//第一行是数组大小，第二行是以空格分隔的字符串数组.
//
//注：预先知道每个字符串的长度都是 10.
//
//输出
//所有的逆序对个数.这次需要大家先输出一个字符串，它是“我已阅读关于抄袭的说明”的汉语拼音.输出此行的提交我们将认为已经完全阅读并了解了“关于抄袭的说明”公告.
//
//注意：结果比较大，请用 long 类型保存.
//
//样例输入
//3
//aaaaaaaaaa cccccccccc bbbbbbbbbb
//样例输出
//wo yi yue du guan yu chao xi de shuo ming
//1
//提示
//不要使用蛮力算法

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

long countInverse(string *, long);
long InvBetLeftRight(string *, long);
void quickSort(string *, long);
long partition(string *, string, long);
void output(string *, long);

// O(n*log^2(n))
int main()
{
	long n; // if told to use 'long', then use it.
	string *arr;
	cin >> n;
	arr = new string[n];
	for (long i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	long count = countInverse(arr, n);
	cout << "wo yi yue du guan yu chao xi de shuo ming" << endl;
	cout << count << endl;

	delete[]arr;
	system("pause");
	return 0;
}

long countInverse(string *arr, long n) {
	if (n == 1) return 0;
	long count = countInverse(arr, n / 2) + countInverse(arr + n / 2, n - n / 2);
	count += InvBetLeftRight(arr, n); // !!! if placed ahead, sort function would shuffle
										// the array, and cause destructive result.
	return count;
}

long InvBetLeftRight(string *arr, long n) {
	quickSort(arr, n / 2);
	quickSort(arr + n / 2, n - n / 2);
	long left = 0, right = n / 2;
	long count = 0;
	while (left < n / 2) {
		if (arr[left] > arr[right]) {
			while (right < n && arr[left] > arr[right]) {
				count += (n / 2 - left);
				++right;
			}
			if (right == n) break; // gauantee it wont visit arr[n].
		}
		++left;
	}
	return count;
}

void output(string *arr, long n) {
	for (long i = 0; i < n - 1; ++i) {
		cout << arr[i] << ' ';
	}
	cout << arr[n - 1] << endl;
}

void quickSort(string *arr, long n) {
	if (n == 1 || n == 0) return;
	string pivot = arr[n / 2];
	string temp = arr[0]; 
	arr[0] = arr[n / 2]; arr[n / 2] = temp;
	long k = partition(arr, pivot, n);
	quickSort(arr, k);
	quickSort(arr + k + 1, n - k - 1);
}

long partition(string *arr, string pivot, long n) {
	long head = 0, rear = n - 1;
	string temp;
	while (head < rear) {
		while (arr[rear] > pivot) 
			--rear;
		temp = arr[head]; arr[head] = arr[rear]; arr[rear] = temp;
		while (arr[head] <= pivot && head < rear) 
			++head;
		temp = arr[rear]; arr[rear] = arr[head]; arr[head] = temp;
	}
	return head;
}