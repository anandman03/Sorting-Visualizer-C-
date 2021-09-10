#include <iostream>
using namespace std;

int partition(int* arr, int start, int end) {
	int prev = start-1;
	for(int index = start ; index < end ; ++index) {
		if(arr[index] < arr[end]) {
			swap(arr[prev++], arr[index]);
		}
	}
	swap(arr[end], arr[prev+1]);
	return prev+1;
}

void quickSort(int* arr, int start, int end) {
	if(start < end) {
		int pivot = partition(arr, start, end);
		mergeSort(arr, start, pivot-1);
		mergeSort(arr, pivot+1, end);
	}
}

int* quick_sort(int* arr, int size) {
	
	int* store = new int[size];
	for(int index = 0 ; index < size ; ++index) {
		store[index] = arr[index];
	}

	quickSort(store, 0, size-1);
	return store;
}
