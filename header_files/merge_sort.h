#include <iostream>
using namespace std;

void merge(int* arr, int start, int mid, int end) {
	int temp[end-start+1];
	int index = 0;

	int frontPtr = start, backPtr = mid+1;

	while(frontPtr <= mid && backPtr <= end) {
		if(arr[frontPtr] < arr[backPtr]) {
			temp[index++] = arr[frontPtr++];
		}
		else {
			temp[index++] = arr[backPtr++];
		}
	}
	while(frontPtr <= mid) {
		temp[index++] = arr[frontPtr++];
	}
	while(backPtr <= end) {
		temp[index++] = arr[backPtr++];
	}

	for(int i = 0 ; i < index ; ++i) {
		arr[start+i] = temp[i];
	}
}

void mergeSort(int* arr, int start, int end) {
	if(start < end) {
		int mid = start + (end - start) / 2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid+1, end);
		merge(arr, start, mid, end);
	}
}

int* merge_sort(int* arr, int size) {
	
	int* store = new int[size];
	for(int index = 0 ; index < size ; ++index) {
		store[index] = arr[index];
	}

	mergeSort(store, 0, size-1);
	return store;
}
