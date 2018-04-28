//问题 A : 变位词
//时间限制 : 2 Sec  内存限制 : 10 MB
//	提交 : 313  解决 : 55
//
//	题目描述
//	请大家在做oj题之前，仔细阅读关于抄袭的说明http ://www.bigoh.net/JudgeOnline/.
//
//
//变位词是指由相同的字母组成的单词，如eat、tea是变位词。本次问题给出一串单词，你需要找到所有的变位词。
//
//输入
//输入由两行组成：第一行是所有单词的总数，第二行是由空格分隔的单词列表。两行末尾都有空格。
//
//注：为防歧义，输入的单词都是小写
//
//输出
//这次需要大家先输出一个字符串，它是“我已阅读关于抄袭的说明”的汉语拼音.输出此行的提交我们将认为已经完全阅读并了解了“关于抄袭的说明”公告.
//
//第二行是变位词组的个数，后面是所有的变位词。每个输出的变位词占一行。一组变位词只需要输出一个字典序最小的代表即可，如eat、tea中eat字典序小于tea，所以输出eat。变位词与变位词也按照字典序从小到大排列，如eat和el中eat字典序小于el所以eat在el前面。
//
//输出的每一行最后都没有空格。
//
//样例输入
//9
//a ew vc tea oe eat zoo el le
//样例输出
//wo yi yue du guan yu chao xi de shuo ming
//2
//eat
//el
//提示
//使用代价为O(nlgn)的方法。

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
		list[i].value = Eyclo(list[i].origin);// origin的字典序
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
