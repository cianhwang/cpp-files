// WELL-KNOWN PK method

#include "stdafx.h"
#include <iostream>
using namespace std;
int PKmethod(int *arr, int n, int realnum);

int main()
{
	int n = 0; cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	int freqEle = PKmethod(arr, n, n);
	cout << freqEle << endl;

	system("PAUSE");
	return 0;
}

// supposed easy question turned out to be not that easy.
int PKmethod(int *arr, int n, int realnum) {
	// base case
	// ... chain would be better. easy to delete.
	// realnum help to detect the base case.
	// -1 to indicate 'has been deleted'
	if (realnum == 1)
		for (int i = 0; i < n; ++i)
			if (arr[i] != -1)
				return arr[i];

	int *head = arr;
	int *rear = arr + n - 1;
	while (head < rear) {
		if (*head == -1) { ++head; continue; }
		if (*rear == -1) { --rear; continue; }

		if (*head != *rear) {
			*head = *rear = -1;
			realnum -= 2;
		}
		++head; --rear;
	}
	int freqEle = 0;
	realnum = (realnum + 1) / 2;
	if (head == rear)
		freqEle = PKmethod(arr, head - arr + 1, realnum);
	else
		freqEle = PKmethod(arr, head - arr, realnum);
	// judge: if not the frequent element.. ERROR
	int count = 0;
	for (int i = 0; i < n; ++i) {
		if (arr[i] == freqEle)
			++count;
	}
	if (count * 2 <= n)
		freqEle = -1;
	return freqEle;
}
//#1:51
//1
//45
//1
//1
//1
//1
//1
//78
//1
//1
//65
//37
//1
//1
//58
//1
//5
//95
//1
//39
//19
//96
//6
//10
//1
//80
//1
//46
//1
//75
//49
//63
//25
//36
//79
//1
//1
//49
//1
//1
//55
//9
//2
//24
//74
//65
//41
//1
//1
//52
//1
//1
//1
//1
//1
//93
//54
//82
//37
//1
//82
//79
//30
//19
//1
//1
//12
//1
//1
//1
//1
//1
//1
//69
//1
//1
//1
//51
//1
//1
//1
//44
//1
//14
//1
//91
//1
//1
//1
//1
//1
//17
//1
//83
//31
//34
//38
//1
//65
//1