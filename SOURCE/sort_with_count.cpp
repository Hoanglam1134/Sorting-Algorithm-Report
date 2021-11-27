#include"sort_with_count.h"
#include<iostream>
#include<vector>
using namespace std;

long long selectionSortCount(int arr[], int n) {
	long long counter = 1;
	int minIndex;
	for (int i = 0; counter++ && i < n - 1; i++) {
		minIndex = i;
		for (int j = i + 1; counter++ && j < n; j++) 
			if (counter++ && arr[minIndex] > arr[j]) 
				minIndex = j;
		swap(arr[minIndex], arr[i]);
	}
	return counter;
}

long long insertionSortCount(int arr[], int n) { //reference GFG
	long long counter = 1;
	int j, saved;
	for (int i = 1; counter++ && i < n; i++) {
		saved = arr[i];
		for (j = i - 1; counter++ && j >= 0; j--)
			if (counter++ && saved < arr[j])
				arr[j + 1] = arr[j];
		arr[j + 1] = saved;
	}
	return counter;
}

long long bubbleSortCount(int arr[], int n) {
	long long counter = 1;
	for (int i = 0; counter++ && i < n - 1; i++)
		for (int j = 0; counter++ && j < n - 1 - i; j++)
			if (counter++ && arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
	return counter;
}

long long shakerSortCount(int arr[], int n) {
	long long counter = 1;
	int l = 0, r = n-1;
	bool isSwapped = true;
	while (isSwapped) {
		isSwapped = false;
		for (int j = l; counter++ && j < r; j++) 
			if (counter++ && arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				isSwapped = true;
			}
		if (!isSwapped) break;
		isSwapped = false;
		r--;
		for (int j = r - 1; counter++ && j >= l; j--)
			if ( counter++ &&arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				isSwapped = true;
			}
		l++;
	}
	return counter;
}

long long shellSortCount(int arr[], int n){ //reference: GFG
	long long counter = 1;
	int j;
	for (int amount = n / 2; counter++ && amount > 0; amount /= 2){
		for (int i = amount; counter++ && i < n; i++){
			int tmp = arr[i];
			for (j = i; counter++ && j >= amount && arr[j - amount] > tmp; j -= amount)
				arr[j] = arr[j - amount];
			arr[j] = tmp;
		}
	}
	return counter;
}

void heapify2(int arr[], int n, int i, long long& cnt) {
	int max = i;
	int leftNode = i * 2 + 1;
	int rightNode = i * 2 + 2;
	if ( cnt++ &&leftNode < n && arr[max] < arr[leftNode])
		max = leftNode;
	if ( cnt++ &&rightNode < n && arr[max] < arr[rightNode])
		max = rightNode;
	if (max != i) {
		swap(arr[max], arr[i]);
		heapify2(arr, n, max, cnt);
	}
}

long long heapSortCount(int arr[], int n) {
	long long counter = 1;
	for (int i = n / 2 - 1; counter++ && i >= 0; i--) { //build max heap
		heapify2(arr, n, i, counter);
	}
	for (int i = n - 1; counter++ && i > 0; i--) {
		swap(arr[0], arr[i]); //swap max to the end of array
		heapify2(arr, i, 0, counter);
	}
	return counter;
}

// https://nguyenvanhieu.vn/thuat-toan-sap-xep-merge-sort/
void merge2(int arr[], int l, int m, int r, long long& cnt){
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int* left = new int[n1];
	int* right = new int[n2];
	for (i = 0; cnt++ && i < n1; i++)
		left[i] = arr[l + i];
	for (j = 0; cnt++ && j < n2; j++)
		right[j] = arr[m + 1 + j];

	i = 0; 
	j = 0; 
	k = l;
	while ( cnt++ &&i < n1 && j < n2){
		if ( cnt++ && left[i] <= right[j]){
			arr[k] = left[i];
			i++;
		} else{
			arr[k] = right[j];
			j++;
		}
		k++;
	}
	while (cnt++ && i < n1){
		arr[k] = left[i];
		i++;
		k++;
	}
	while (cnt++ && j < n2){
		arr[k] = right[j];
		j++;
		k++;
	}
	delete[] left, right;
}

void mergeSort2(int arr[], int l, int r, long long& cnt) {
	if (cnt++ && l < r){
		int middle = l + (r - l) / 2;
		mergeSort2(arr, l, middle, cnt);
		mergeSort2(arr, middle + 1, r, cnt);
		merge2(arr, l, middle, r, cnt);
	}
}

long long mergeSortToUseCount(int arr[], int n){
	long long counter = 1;
	mergeSort2(arr, 0, n-1, counter);
	return counter;
}

void quickSort2(int arr[], int l, int r, long long& cnt) {
	if (cnt++ && l <= r) {
		int i = l, j = r, mid = arr[l + (r - l) / 2];
		while (cnt++ && i < j) {
			while ( cnt++ && arr[i] < mid) i++;
			while ( cnt++ && arr[j] > mid) j--;
			if (cnt++ && i <= j) {
				swap(arr[i], arr[j]);
				i++;
				j--;
			}
		}
		if (l < j) 
			quickSort2(arr, l, j, cnt);
		if (i < r) 
			quickSort2(arr, i, r, cnt);
	}
}

long long quickSortToUseCount(int arr[], int n){
	long long counter = 1;
	quickSort2(arr, 0, n-1, counter);
	return counter;
}

int findMax2(int arr[], int n, long long& cnt) {
	int max = arr[0];
	for (int i = 0; cnt++ && i < n; i++) {
		if ( cnt++ && max < arr[i])
			max = arr[i];
	}
	return max;
}

long long countingSortCount(int arr[], int n){
	long long counter = 1;
	int max = findMax2(arr, n, counter);
	int *count = new int[max + 1];
	int k = 0;
	for (int i = 0; counter++ && i <= max; i++) 
		count[i] = 0;
	for (int i = 0; counter++ && i < n; i++)
		count[arr[i]]++;
	for (int i = 0; counter++ && i <= max; i++) {
		while ( counter++ && count[i] > 0) {
			arr[k] = i;
			k++;
			count[i]--;
		}
	}
	delete[] count;
	return counter;
}

void countRadixSort2(int arr[], int n, int mu, long long& cnt) {
	int count[10] = { 0 };
	int* res = new int[n];
	for (int i = 0; cnt++ && i < n; i++)
		count[(arr[i] / mu) % 10]++;
	for (int i = 1; cnt++ && i < 10; i++) {
		count[i] += count[i - 1];
	}
	for (int i = n - 1; cnt++ && i >= 0; i--) {
		res[count[(arr[i] / mu) % 10]-1] = arr[i];
		count[(arr[i] / mu) % 10]--;
	}
	for (int i = 0; cnt++ && i < n; i++)
		arr[i] = res[i];
	delete[] res;
}

long long radixSortCount(int arr[], int n) {
	long long counter = 1;
	int max = findMax2(arr, n, counter);
	for (int i = 1; counter++ && max / i > 0; i *= 10) {
		countRadixSort2(arr, n, i, counter);
	}
	return counter;
}

long long flashSortCount(int a[], int n) { // reference Thay Nguyen Thanh Phuong video record
	long long counter = 1;
    int minValue = a[0], maxValue = a[0];
    for (int i = 1; counter++ && i < n; i++){
        if ( counter++ && a[i] < minValue) minValue = a[i];
        if ( counter++ && a[i] > maxValue) maxValue = a[i];
    }
    int k, m = 0.43 * n;
    int* sub = new int[m];
    for (int i = 0; counter++ && i < m; i++) sub[i] = 0;
    for (int i = 0; counter++ && i < n; i++) {
        k = 1ll * (m - 1) * (a[i] - minValue) / (maxValue - minValue);
        sub[k]++;
    }
    for (int k = 1; counter++ && k < m; k++) {
        sub[k] += sub[k - 1];
    }

    int count = 1;
    int i = 0;
    k = m - 1;
    while ( counter++ && count <= n) {
        while ( counter++ && i > sub[k] - 1) {
            i++;
            k = 1ll * (m - 1) * (a[i] - minValue) / (maxValue - minValue);
        }

        int save = a[i];
        if ( counter++ && k < 0) break;
        while ( counter++ && i <= sub[k] - 1) {
            k = 1ll * (m - 1) * (save - minValue) / (maxValue - minValue);
            int y = a[sub[k] - 1];
            a[sub[k] - 1] = save;
            save = y;
            sub[k]--;
            count++;
        }
    }

    for (k = 1; counter++ && k < m; k++) {
        for (int i = sub[k] - 1; counter++ && i >= sub[k - 1]; i--) {
            if ( counter++ && a[i] > a[i + 1]) {
                int t = a[i];
                int j = i;
                while ( counter++ && t > a[j + 1])
                    a[j++] = a[j + 1];
                a[j] = t;
            }
        }
    }
    delete[] sub;
	return counter;
}