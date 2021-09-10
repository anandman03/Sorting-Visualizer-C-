#include <iostream>
using namespace std;

void mergeModified(int* arr, int start, int mid, int end) {
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

void insertionSort(int* arr, int start, int end) {
	for(int outIndex = start ;  outIndex <= end ; ++outIndex) {
		int key = arr[outIndex];
		int inIndex = outIndex-1;
		while(inIndex >= 0 && key < arr[inIndex]) {
			arr[inIndex+1] = arr[inIndex];
			--inIndex;
		}
		arr[inIndex+1] = key;
	}
}

void mergeSortModified(int* arr, int start, int end) {
	if(start < end) {
		if(start - end >= 15) {
			insertionSort(arr, start, end);
		}
		int mid = start + (end - start) / 2;
		mergeSortModified(arr, start, mid);
		mergeSortModified(arr, mid+1, end);
		mergeModified(arr, start, mid, end);
	}
}

int* twist_sort(int* arr, int size) {
	
	int* store = new int[size];
	for(int index = 0 ; index < size ; ++index) {
		store[index] = arr[index];
	}

	mergeSortModified(store, 0, size-1);
	return store;
}
