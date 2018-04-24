//���� A : ��̬��λ������
//ʱ������ : 1 Sec  �ڴ����� : 8 MB
//	�ύ : 538  ��� : 66
//
//	��Ŀ����
//	����һ������a1, a2, ��, an ��ÿ����һ���������������ʱΪֹ����λ����
//
//	��λ�����壺��������Ĵ�С��ż�� 2j����λ���Ǵ�С�������еĵ� j ��������������Ĵ�С������ 2j + 1����λ���Ǵ�С�������еĵ� j + 1 ������
//
//	����
//	һ�����������ֺ�����֮���Կո������
//	���
//	һ�����������ֺ�����֮���Կո���������һ��������Ҳ�пո�
//
//	�� i ���������������ǰ i ���������λ����
//
//	��������
//	- 18 - 2 14 - 20 - 6 7 2 14 11 6
//	�������
//	- 18 - 18 - 2 - 18 - 6 - 6 - 2 - 2 2 2
//	��ʾ
//
//	ʱ�临�Ӷ��벻Ҫ����O(nlogn)��
//	�����������������Ƚϴ�����Ƽ�ʹ��c�����е�scanf��printf��������������������ܱ�c++��cin��cout��ʡ���ʱ�䡣
//
//
//	���ﱾ����һ����ʾ������������ʦ�Ͽβ�С��˵©���ˣ��������̺��ĵذ���ע�͵��� ����
//
//
//	/*�ڴ��������ʱ���ѽṹҲ���ܸ���������벻���İ�����*/

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