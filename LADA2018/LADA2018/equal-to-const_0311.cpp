// ���� C: ��������֮���Ƿ���ڸ�����
//��Ŀ����
//����һ�� int ���� arr��Ԫ�ذ������������Ҹ�����ͬ��������һ��Ŀ���� c�������ҳ� arr �����е����� a, b��ʹ�� a + b = c��
//����
//����Ϊ���У���һ��Ϊ arr ��Ԫ�ظ������ڶ���Ϊ arr��Ԫ���Կո�ָ���������ΪĿ���� c��
//���
//���з������������� a, b��a �� b �Կո�ֿ���ÿ������ռ��һ�С�ÿ���� a < b���������������ĵ�һ������Ҳ���� a ��ֵ���������С�
//	��������
//	9
//	- 2 0 1 2 3 5 6 8 10
//	8
//	�������
//	- 2 10
//	0 8
//	2 6
//	3 5

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int n;	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	int c;	cin >> c;
	int *p = arr;
	int *q = arr + n - 1;
	while (p < q) {
		while (*p + *q > c)
			--q;
		if (c == (*p + *q))
			cout << *p << ' ' << *q << endl;
		++p;
	}

	system("pause");
    return 0;
}

