//问题 B : 非完美二叉树的高度与直径
//时间限制 : 2 Sec  内存限制 : 3 MB
//	提交 : 103  解决 : 53
//
//	题目描述
//	记T为一棵二叉树，树中共有n个节点。
//
//	定义根节点的深度为0，其余节点的深度为其父节点的深度加1。T的高度定义为其叶节点深度的最大值。
//
//	定义树中任意两点a和b之间的距离为其间最短简单路径的长度。T的直径定义为T中所有点对间距离的最大值。
//
//	输入一棵二叉树T，请计算它的高度和直径。
//
//	输入
//	输入共三行。
//
//	第一行输入n的值，表示树中结点的总个数。
//
//	第二行为树的前序遍历表示，每个节点之间用空格隔开。
//
//	第三行为树的中序遍历表示，每个节点之间也用空格隔开。
//
//	输出
//	输出共三行。
//	第一行需要大家输出一行字符串，它是“我已阅读关于抄袭的说明”的英文翻译，即："I have read the rules about plagiarism punishment"。输出此行的提交我们将认为已经完全阅读并了解了“关于抄袭的说明”公告并同意关于抄袭的惩罚措施。
//	第二行输出树的高度。
//	第三行输出树的直径。
//
//
//
//	样例输入
//	10
//	0 1 9 3 8 4 2 7 5 6
//	3 9 8 1 2 4 0 5 7 6
//	样例输出
//	I have read the rules about plagiarism punishment
//	3
//	5
//	提示
//	分治算法可以在O(n)的时间内完成相应的计算。

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int treeDiameter(int* ahead, int* bhead, int *arear, int* brear, int &height);
int searchRear(int *arr, int value);
int Max(int, int, int);

int main()
{
	int n = 0; cin >> n;
	int *a = new int[n];
	int *b = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		cin >> b[i];

	int height = 0;
	int diameter = treeDiameter(a, b, a + n, b + n, height);
	cout << "I have read the rules about plagiarism punishment" << endl;
	cout << height << endl;
	cout << diameter;

	system("PAUSE");
	return 0;
}

int treeDiameter(int* ahead, int* bhead, int *arear, int* brear, int &height) {
	if (arear - ahead == 0 || arear - ahead == 1) {
		height = 0;
		return 0;
	}
	int idx = searchRear(bhead, ahead[0]);
	int hLeft, hRight;
	hLeft = hRight = 0;
	int leftDiameter = treeDiameter(ahead + 1, bhead, ahead + idx, bhead + idx - 1, hLeft);
	int rightDiameter = treeDiameter(ahead + idx, bhead + idx, arear, brear, hRight);
	height = Max(hLeft, hRight, 0) + 1;
	return Max(leftDiameter, rightDiameter, hLeft + hRight + 2);
}

//find the next postion of given value
int searchRear(int *arr, int value) {
	int i = 0;
	while (arr[i] != value)
		++i;
	return ++i;
}

int Max(int a, int b, int c) {
	if (a > b) {
		if (c > a)
			a = c;
	}
	else {
		if (b < c)
			a = c;
		else
			a = b;
	}
	return a;
}



