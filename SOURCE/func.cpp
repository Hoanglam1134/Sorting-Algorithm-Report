#include "func.h"
#include "constants.h"
#include "sort.h"
#include "sort_with_count.h"

double calcTimeAlgo(int arr[], int n, int type){
	clock_t start = clock(); 
	doAlgo(arr, n, type);
    clock_t end = clock();
	return (double(end - start) / CLOCKS_PER_SEC) * 1000;
}

void doAlgo(int arr[], int n, int index){
	switch (index){
	case 1:
		selectionSort(arr, n);
		break;
	case 2:
		insertionSort(arr, n);
		break;
	case 3:
		bubbleSort(arr, n);
		break;
	case 4:
		shakerSort(arr, n);
		break;
	case 5:
		shellSort(arr, n);
		break;
	case 6:
		heapSort(arr, n);
		break;
	case 7:
		mergeSortToUse(arr, n);
		break;
	case 8:
		quickSortToUse(arr, n);
		break;
	case 9:
		countingSort(arr, n);
		break;
	case 10:
		radixSort(arr, n);
		break;
	case 11:
		flashSort(arr, n);
		break;
	default:
		break;
	}
}

long long doAlgoCount(int arr[], int n, int index){
	long long cnt = 0;
    switch (index){
	case 1:
		cnt = selectionSortCount(arr, n);
		break;
	case 2:
		cnt = insertionSortCount(arr, n);
		break;
	case 3:
		cnt = bubbleSortCount(arr, n);
		break;
	case 4:
		cnt = shakerSortCount(arr, n);
		break;
	case 5:
		cnt = shellSortCount(arr, n);
		break;
	case 6:
		cnt = heapSortCount(arr, n);
		break;
	case 7:
		cnt = mergeSortToUseCount(arr, n);
		break;
	case 8:
		cnt = quickSortToUseCount(arr, n);
		break;
	case 9:
		cnt = countingSortCount(arr, n);
		break;
	case 10:
		cnt = radixSortCount(arr, n);
		break;
	case 11:
		cnt = flashSortCount(arr, n);
		break;
	default:
		break;
	}
	return cnt - 1;
}

bool isNum(char *s){
    for (int i = 0; i < strlen(s); i++)
        if (!(s[i] >= '0' && s[i] <= '9'))
            return false;
    return true;
}

int getType(char* c){
	string name = c;
	for(int i = 0; i < 11; i++){
		if(name == sortName[i])
			return i+1;
	}
	return -1;
}

int getOrder(char* c){
	string order = c;
	for(int i = 0;i<4;i++){
		if(order == dataType[i])
			return i;
	}
	return -1;
}

void printResults(int mode, string time1, string time2, string comparisions1, string comparisions2, 
string algo1, string algo2, string input, string size, string order){
	if(mode == 1){
		cout << "ALGORITHM MODE\n";
		cout << "Algorithm: " << algo1 << endl;
		if(input != "")
			cout << "Input file: " << input << endl;
		if(size != "")
			cout << "Input size: " << size << endl;
		if(order != "")
			cout << "Input order: " << order << endl;
		cout << "------------------------------\n";
		cout << "Running time (if required): ";
		if(time1 != "-1.000000")
			cout << time1 << "ms";
		cout << "\nComparisions (if required): "; 
		if(comparisions1 != "-1")
			cout << comparisions1 << endl;
		cout << endl;
	}
	else {
		cout << "COMPARE MODE\n";
		cout << "Algorithm: " << algo1 << " | " << algo2 << endl;
		if(input != "")
			cout << "Input file: " << input << endl;
		if(size != "")
			cout << "Input size: " << size << endl;
		if(order != "")
			cout << "Input order: " << order << endl;
		cout << "------------------------------\n";
		cout << "Running time: " << time1 << "ms | " << time2 << "ms";
		cout << "\nComparisions: " << comparisions1 << " | " << comparisions2 << endl;
		cout << endl;
	}

}

void checkRequest(char* c, double& time, long long& comparisions, int a[], int n, int type){
	if (strcmp(c, "-both") == 0)
	{
		int *subArr = new int[n];
		for(int i = 0;i<n;i++)
			subArr[i] = a[i];
		time = calcTimeAlgo(a, n, type);
		comparisions = doAlgoCount(subArr, n, type);
		delete[]subArr;
	}
	else if (strcmp(c, "-time") == 0){
		time = calcTimeAlgo(a, n, type);
	}
	else{
		comparisions = doAlgoCount(a, n, type);
	}
}