//���� A : ��λ��
//ʱ������ : 2 Sec  �ڴ����� : 10 MB
//	�ύ : 313  ��� : 55
//
//	��Ŀ����
//	��������oj��֮ǰ����ϸ�Ķ����ڳ�Ϯ��˵��http ://www.bigoh.net/JudgeOnline/.
//
//
//��λ����ָ����ͬ����ĸ��ɵĵ��ʣ���eat��tea�Ǳ�λ�ʡ������������һ�����ʣ�����Ҫ�ҵ����еı�λ�ʡ�
//
//����
//������������ɣ���һ�������е��ʵ��������ڶ������ɿո�ָ��ĵ����б�����ĩβ���пո�
//
//ע��Ϊ�����壬����ĵ��ʶ���Сд
//
//���
//�����Ҫ��������һ���ַ��������ǡ������Ķ����ڳ�Ϯ��˵�����ĺ���ƴ��.������е��ύ���ǽ���Ϊ�Ѿ���ȫ�Ķ����˽��ˡ����ڳ�Ϯ��˵��������.
//
//�ڶ����Ǳ�λ����ĸ��������������еı�λ�ʡ�ÿ������ı�λ��ռһ�С�һ���λ��ֻ��Ҫ���һ���ֵ�����С�Ĵ����ɣ���eat��tea��eat�ֵ���С��tea���������eat����λ�����λ��Ҳ�����ֵ����С�������У���eat��el��eat�ֵ���С��el����eat��elǰ�档
//
//�����ÿһ�����û�пո�
//
//��������
//9
//a ew vc tea oe eat zoo el le
//�������
//wo yi yue du guan yu chao xi de shuo ming
//2
//eat
//el
//��ʾ
//ʹ�ô���ΪO(nlgn)�ķ�����

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class Word {
public:
	string origin;
	string value;
};

int Comp(const void *a, const void *b) {
	return (((Word*)a)->origin.size() - ((Word*)b)->origin.size());
}

int Comp2(const void *a, const void *b) {
	if (((Word*)a)->value < ((Word*)b)->value) return -1;
	if (((Word*)a)->value == ((Word*)b)->value) return 0;
	if (((Word*)a)->value > ((Word*)b)->value) return 1;
}

int Comp3(const void *a, const void *b) {
	if (((Word*)a)->origin < ((Word*)b)->origin) return -1;
	if (((Word*)a)->origin == ((Word*)b)->origin) return 0;
	if (((Word*)a)->origin >((Word*)b)->origin) return 1;
}

string Eyclo(string s) {
	int n = s.size();
	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (s[i] > s[j]) {
				auto temp = s[i];
				s[i] = s[j];
				s[j] = temp;
			}
		}
	}
	return s;
}

int main()
{
	int n = 0; cin >> n;
	Word *list = new Word[n];
	for (int i = 0; i < n; ++i) {
		cin >> list[i].origin;
		list[i].value = Eyclo(list[i].origin);// origin���ֵ���
	}
	qsort(list, n, sizeof(Word), Comp);
	int idx = 1;
	int tempHead = 0, tempEnd = 0;
	while (idx < n) {
		if (list[idx - 1].origin.size() != list[idx].origin.size()){
			tempEnd = idx - 1;
			qsort(list+tempHead, tempEnd - tempHead + 1, sizeof(Word), Comp2);
			tempHead = idx;
		}
		++idx;
	}
	tempEnd = idx - 1;
	qsort(list + tempHead, tempEnd - tempHead + 1, sizeof(Word), Comp2);

	//for (int i = 0; i < n; ++i) {
	//	cout << list[i].origin << ' ';
	//}

	idx = 1;
	tempHead = tempEnd = 0;
	int count = 0;
	vector<string> v;
	while (idx < n) {
		if (list[idx - 1].value != list[idx].value) {
			tempEnd = idx - 1;
			if (tempEnd - tempHead > 0) {
				qsort(list + tempHead, tempEnd - tempHead + 1, sizeof(Word), Comp3);
				v.push_back(list[tempHead].origin);
				++count;
			}
			tempHead = idx;
		}
		++idx;
	}
	tempEnd = idx - 1;
	if (tempEnd - tempHead > 0) {
		qsort(list + tempHead, tempEnd - tempHead + 1, sizeof(Word), Comp3);
		v.push_back(list[tempHead].origin);
		++count;
	}
	
	for (int i = 0; i < v.size() - 1; ++i) {
		for (int j = i + 1; j < v.size(); ++j) {
			if (v[i] > v[j]) {
				auto temp = v[i];
				v[i] = v[j];
				v[j] = temp;
			}
		}
	}

	cout << "wo yi yue du guan yu chao xi de shuo ming" << endl;
	cout << count << endl;
	for (auto it = v.cbegin(); it != v.cend(); ++it) {
		cout << (*it) << endl;
	}

	system("PAUSE");
	return 0;
}
