// Swapping array elements

#include "stdafx.h"
#include <iostream>
using namespace std;

int Times = 0;
int Times2 = 0;
void swapArray(int *, int, int);	// Reculsion: linear times
void Swap(int &a, int &b) {	// O(1) space
	++Times2;
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int n; cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; ++i) {
		arr[i] = i + 1;
	}
	int pos; cin >> pos;
	swapArray(arr, n, pos);

	// Evaluation: suppose input is 1 to n, err denotes the deviation between arr and correct answer.
	int *err = new int[n];
	for (int i = 0; i < n - pos; ++i)
		err[i] = pos + i + 1 - arr[i];
	for (int i = 0; i < pos; ++i)
		err[n - pos + i] = i + 1 - arr[n - pos + i];

	for (int i = 0; i < n; ++i)
		cout << err[i] << ' ';
	cout << endl;
	cout << Times << ' ' << Times2 << endl;
	system("pause");
	return 0;
}

void swapArray(int *arr, int n, int pos)
{
	++Times;
	if (!pos || n == 1) // pos=0 && n>1 is possible.
		return;
	if (n - pos > pos) {

		for (int i = 0; i < pos; ++i)
			Swap(arr[i], arr[n - pos + i]);
		//for (int i = 0; i < n; ++i)
		//	cout << arr[i];
		//cout << endl;
		swapArray(arr, n - pos, pos);
	}
	else {
		for (int i = 0; i < n - pos; ++i)
			Swap(arr[i], arr[pos + i]);
		//for (int i = 0; i < n; ++i)
		//	cout << arr[i];
		//cout << endl;
		swapArray(arr + n - pos, pos, 2 * pos - n);
	}
}

