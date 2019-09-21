// alpha.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
using namespace std;


void sort(int arr[], int n){ // Shell sort
	int i, j, tmp;
	for (int d = 3; d > 0; d--)
		for (i = d; i < n; i++) {
			tmp = arr[i];
			for (j = i - d; j >= 0 && tmp > arr[j]; j -= d) arr[j + d] = arr[j];
			arr[j + d] = tmp;
		}
}

int bsearch(int arr[], int X, int amount) {
	int result = -1;
	for (int i = 0; i < amount; i++) {
		if (arr[i] < X) {
			result = i; break;
		}
	}
	return result;
}

int main()
{
	int amount, X, result;
	cout << "Enter amount of array elements: ";
	cin >> amount;
	if (amount < 1) {
		cout << "Error! Amount of array elements must be bigger than 0" << endl;
		return 0;
	}
	int *arr = new int[amount];
	for (int i = 0; i < amount; i++) {
		cout << "arr[" << i << "]= ";
		cin >> arr[i];
	}
	sort(arr, amount);
	cout << "Enter X: ";
	cin >> X;
	result = bsearch(arr, X, amount);
	if (result == -1) cout << "X is smaller than any element of array" << endl;
	else cout<<"Result is index " << result <<endl;
	delete(arr);
	system("pause");
    return 0;
}

