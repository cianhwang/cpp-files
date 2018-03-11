// Swapping array elements

#include "stdafx.h"
#include <iostream>
using namespace std;

int Times = 0;
int Times2 = 0;
void swapArray(int *, int, int);
void Swap(int &a, int &b) {
	++Times2;
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int n = 8;
	//int *arr = new int[n];
	//for (int i = 0; i < n; ++i) {
	//	cin >> arr[i];
	//}
	int arr[] = {1,2,3,4,5,6,7,8};
	int pos = 6;

	swapArray(arr, n, pos);
	for (int i = 0; i < n; ++i)
		cout << arr[i];
	cout << endl;
	cout << Times << ' ' << Times2 << endl;
	system("pause");
    return 0;
}

void swapArray(int *arr, int n, int pos)
{
	++Times;
	if (!pos || n == 1)
		return;
	if (n - pos > pos) {

		for (int i = 0; i < pos; ++i)
			Swap(arr[i], arr[n-pos+i]);
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
		swapArray(arr + n-pos, pos, 2*pos-n);
	}
}

