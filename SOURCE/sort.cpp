#include"sort.h"
#include<iostream>
using namespace std;

void selectionSort(int arr[], int n) {
	int minIndex;
	for (int i = 0; i < n - 1; i++) {
		minIndex = i;
		for (int j = i + 1; j < n; j++)
			if (arr[minIndex] > arr[j])
				minIndex = j;
		swap(arr[minIndex], arr[i]);
	}
}

void insertionSort(int arr[], int n) { //reference GFG
	int j, saved;
	for (int i = 1; i < n; i++) {
		saved = arr[i];
		for (j = i - 1; j >= 0; j--)
			if (saved < arr[j])
				arr[j + 1] = arr[j];
		arr[j + 1] = saved;
	}
}

void bubbleSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1 - i; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
}

void shakerSort(int arr[], int n) {
	int l = 0, r = n-1;
	bool isSwapped = true;
	while (isSwapped) {
		isSwapped = false;
		for (int j = l; j < r; j++) 
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				isSwapped = true;
			}
		if (!isSwapped) break;
		isSwapped = false;
		r--;
		for (int j = r - 1; j >= l; j--)
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				isSwapped = true;
			}
		l++;
	}
}

void shellSort(int arr[], int n){ //reference: GFG
	int j;
	for (int amount = n / 2; amount > 0; amount /= 2){
		for (int i = amount; i < n; i++){
			int tmp = arr[i];
			for (j = i; j >= amount && arr[j - amount] > tmp; j -= amount)
				arr[j] = arr[j - amount];
			arr[j] = tmp;
		}
	}
}

void heapify(int arr[], int n, int i) {
	int max = i;
	int leftNode = i * 2 + 1;
	int rightNode = i * 2 + 2;
	if (leftNode < n && arr[max] < arr[leftNode])
		max = leftNode;
	if (rightNode < n && arr[max] < arr[rightNode])
		max = rightNode;
	if (max != i) {
		swap(arr[max], arr[i]);
		heapify(arr, n, max);
	}
}

void heapSort(int arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--) { //build max heap
		heapify(arr, n, i);
	}
	for (int i = n - 1; i > 0; i--) {
		swap(arr[0], arr[i]); //swap max to the end of array
		heapify(arr, i, 0);
	}
}

void merge(int arr[], int l, int m, int r){
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int* left = new int[n1];
	int* right = new int[n2];
	for (i = 0; i < n1; i++)
		left[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		right[j] = arr[m + 1 + j];

	i = 0; 
	j = 0; 
	k = l;
	while (i < n1 && j < n2){
		if (left[i] <= right[j]){
			arr[k] = left[i];
			i++;
		} else{
			arr[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < n1){
		arr[k] = left[i];
		i++;
		k++;
	}
	while (j < n2){
		arr[k] = right[j];
		j++;
		k++;
	}
	delete[] left, right;
}

void mergeSort(int arr[], int l, int r) {
	if (l < r){
		int middle = l + (r - l) / 2;
		mergeSort(arr, l, middle);
		mergeSort(arr, middle + 1, r);
		merge(arr, l, middle, r);
	}
}

void mergeSortToUse(int arr[], int n){
	mergeSort(arr, 0, n-1);
}

void quickSort(int arr[], int l, int r) {
	if (l <= r) {
		int i = l, j = r, mid = arr[l + (r - l) / 2];
		while (i < j) {
			while (arr[i] < mid) i++;
			while (arr[j] > mid) j--;
			if (i <= j) {
				swap(arr[i], arr[j]);
				i++;
				j--;
			}
		}
		if (l < j)
			quickSort(arr, l, j);
		if (i < r) 
			quickSort(arr, i, r);
	}
}

void quickSortToUse(int arr[], int n){
	quickSort(arr, 0, n-1);
}

int findMax(int arr[], int n) {
	int max = arr[0];
	for (int i = 0; i < n; i++) {
		if (max < arr[i])
			max = arr[i];
	}
	return max;
}

void countingSort(int arr[], int n){
	int max = findMax(arr, n);
	int *count = new int[max + 1];
	int k = 0;
	for (int i = 0; i <= max; i++) 
		count[i] = 0;
	for (int i = 0; i < n; i++)
		count[arr[i]]++;
	for (int i = 0; i <= max; i++) {
		while (count[i] > 0) {
			arr[k] = i;
			k++;
			count[i]--;
		}
	}
	delete[] count;
}

void countRadixSort(int arr[], int n, int mu) {
	int count[10] = { 0 };
	int* res = new int[n];
	for (int i = 0; i < n; i++)
		count[(arr[i] / mu) % 10]++;
	for (int i = 1; i < 10; i++) {
		count[i] += count[i - 1];
	}
	for (int i = n - 1; i >= 0; i--) {
		res[count[(arr[i] / mu) % 10]-1] = arr[i];
		count[(arr[i] / mu) % 10]--;
	}
	for (int i = 0; i < n; i++)
		arr[i] = res[i];
	delete[] res;
}

void radixSort(int arr[], int n) {
	int max = findMax(arr, n);
	for (int i = 1; max / i > 0; i *= 10) {
		countRadixSort(arr, n, i);
	}
}

void flashSort(int a[], int n) { // reference Thay Nguyen Thanh Phuong video record
    int minValue = a[0], maxValue = a[0];
    for (int i = 1; i < n; i++){
        if (a[i] < minValue) minValue = a[i];
        if (a[i] > maxValue) maxValue = a[i];
    }
    int k, m = 0.43 * n;
    int* sub = new int[m];
    for (int i = 0; i < m; i++) sub[i] = 0;
    for (int i = 0; i < n; i++) {
        k = 1ll * (m - 1) * (a[i] - minValue) / (maxValue - minValue);
        sub[k]++;
    }
    for (int k = 1; k < m; k++) {
        sub[k] += sub[k - 1];
    }

    int count = 1;
    int i = 0;
    k = m - 1;
    while (count <= n) {
        while (i > sub[k] - 1) {
            i++;
            k = 1ll * (m - 1) * (a[i] - minValue) / (maxValue - minValue);
        }

        int save = a[i];
        if (k < 0) break;
        while (i <= sub[k] - 1) {
            k = 1ll * (m - 1) * (save - minValue) / (maxValue - minValue);
            int y = a[sub[k] - 1];
            a[sub[k] - 1] = save;
            save = y;
            sub[k]--;
            count++;
        }
    }

    for (k = 1; k < m; k++) {
        for (int i = sub[k] - 1; i >= sub[k - 1]; i--) {
            if (a[i] > a[i + 1]) {
                int t = a[i];
                int j = i;
                while (t > a[j + 1])
                    a[j++] = a[j + 1];
                a[j] = t;
            }
        }
    }
    delete[] sub;
}