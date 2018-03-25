// Quicksort

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

//template<typename T>
//class Element {
//public:
//	T value;
//};
//
//template<typename T>
//void input(Element<T> *Ele, int n);
void quickSort(int *, int);
int partition(int *, int, int);
void output(int *, int);


int main()
{
	int *arr, n;
	cin >> n;
	arr = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	quickSort(arr, n);

	output(arr, n);
	delete[]arr;
	system("pause");
	return 0;
}

void output(int *arr, int n) {
	for (int i = 0; i < n - 1; ++i) {
		cout << arr[i] << ' ';
	}
	cout << arr[n - 1] << endl;
}

void quickSort(int *arr, int n) {
	if (n == 1 || n == 0) return;
	int pivot = arr[0];
	int k = partition(arr, pivot, n);
	quickSort(arr, k);
	quickSort(arr + k + 1, n - k - 1);
}

int partition(int *arr, int pivot, int n) {
	int head = 0, rear = n - 1;
	int temp;
	while (head < rear) {
		while (arr[rear] > pivot) 
			--rear;
		temp = arr[head]; arr[head] = arr[rear]; arr[rear] = temp;
		while (arr[head] <= pivot && head < rear) 
			++head;
		temp = arr[rear]; arr[rear] = arr[head]; arr[head] = temp;
	}
	return head;
}