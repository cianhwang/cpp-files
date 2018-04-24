// WELL-KNOWN PK method
// not consider a array without a frequent element.

#include "stdafx.h"
#include <iostream>
using namespace std;
int PKmethod(int *arr, int n, int &realnum);

int main()
{
	int n = 0; cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	int realnum = n;
	int freqEle = PKmethod(arr, n, realnum);
	cout << freqEle << endl;

	system("PAUSE");
	return 0;
}

// supposed easy question turned out to be not that easy.
int PKmethod(int *arr, int n, int &realnum) {
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
	realnum = (realnum + 1) / 2;
	if (head == rear)
		return PKmethod(arr, head - arr + 1, realnum);
	else
		return PKmethod(arr, head - arr, realnum);
}