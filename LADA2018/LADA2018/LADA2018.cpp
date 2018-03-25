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

	int Max = 0, tempMax = 0, i = 0;
	if (arr.size() != 0 && arr[arr.size() - 1] < 0)
		arr.pop_back();

	//for (auto it = arr.cbegin(); it != arr.cend(); ++it)
	//	std::cout << *it << ' ';

	n = arr.size();
	while (i < n)
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
	}
	if (n == 0 && bigNeg != INT32_MIN)
		std::cout << bigNeg << endl;
	else
		std::cout << Max << endl;

	std::system("PAUSE");
	return 0;
}