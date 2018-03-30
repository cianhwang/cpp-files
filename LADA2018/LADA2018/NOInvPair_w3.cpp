//���� B : ���е������
//ʱ������ : 2 Sec  �ڴ����� : 5 MB
//	�ύ : 313  ��� : 53
//
//	��Ŀ����
//	��������oj��֮ǰ����ϸ�Ķ����ڳ�Ϯ��˵��http ://www.bigoh.net/JudgeOnline/.
//
//
//����һ���ַ������飬����������ֵ���һ������ַ����ڱ���С���ַ���ǰ�����ǳ��������ַ������һ��������ԡ�������Ҫ�ҵ����е�����Եĸ�����
//
//����
//��һ���������С���ڶ������Կո�ָ����ַ�������.
//
//ע��Ԥ��֪��ÿ���ַ����ĳ��ȶ��� 10.
//
//���
//���е�����Ը���.�����Ҫ��������һ���ַ��������ǡ������Ķ����ڳ�Ϯ��˵�����ĺ���ƴ��.������е��ύ���ǽ���Ϊ�Ѿ���ȫ�Ķ����˽��ˡ����ڳ�Ϯ��˵��������.
//
//ע�⣺����Ƚϴ����� long ���ͱ���.
//
//��������
//3
//aaaaaaaaaa cccccccccc bbbbbbbbbb
//�������
//wo yi yue du guan yu chao xi de shuo ming
//1
//��ʾ
//��Ҫʹ�������㷨

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