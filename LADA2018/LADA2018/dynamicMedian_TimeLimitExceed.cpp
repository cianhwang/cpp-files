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