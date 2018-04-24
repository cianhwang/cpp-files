// n: #data
// pos: position needs changing
// input: 6 2
//		1 2 3 4 5 6
// output: 3 4 5 6 1 2

#include "stdafx.h"
#include <iostream>
using namespace std;

void Swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void upsideDown(int *head, int *rear) {
	while (head < rear) {
		Swap(*head, *rear);
		++head;
		--rear;
	}
}

int main()
{
	int n = 0; cin >> n;
	int pos = 0; cin >> pos;
	int *arr = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	pos = n - pos;

	// O(n)
	upsideDown(arr, arr + n);
	upsideDown(arr, arr + pos);
	upsideDown(arr + pos, arr + n);

	for (int i = 0; i < n; ++i) {
		cout << arr[i] << ' ';
	}

	system("PAUSE");
	return 0;
}