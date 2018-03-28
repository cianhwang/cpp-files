//���� A : ��������к�����
//ʱ������ : 1 Sec  �ڴ����� : 4 MB
//	�ύ : 194  ��� : 72
//
//	��Ŀ����
//	����һ�������� a1, a2, ��, an���� a1~an ��һ�������� ai~aj��ʹ�ô� ai �� aj �ĺ����
//	ֻ��Ҫ�����������еĺͣ�������Ҫ��������Ǹ����С�
//
//	����
//	һ�����������ֺ�����֮���Կո������
//	���
//	��������������������еĺ�
//	��������
//	- 2 11 - 4 13 - 5 - 2
//	�������
//	20
//	��ʾ
//
//	Ӧ����ٷ����Եõ� O(n3) ���㷨���Ż������ɵõ� O(n2) ���㷨���������㷨���ᳬʱ��
//	���÷��ε�˼������� O(n*logn) ���㷨��
//	Ҳ�д������㷨�����ĸ��Ӷ��� O(n) �ġ�
//	����ע�⣺������ٸ�����δ֪�ġ���˼����δ���

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
	long Max = 0; //Max maintain update anytime�� if input is 8 -2 1, if not update promptly, ...
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