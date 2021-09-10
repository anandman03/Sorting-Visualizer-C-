#include <iostream>
using namespace std;

int* bubble_sort(int* arr, int size) {
	
	int* store = new int[size];
	for(int index = 0 ; index < size ; ++index) {
		store[index] = arr[index];
	}

	for(int outIndex = 0 ;  outIndex < size ; ++outIndex) {
		for(int inIndex = 0 ; inIndex < size-outIndex-1 ; ++inIndex) {
			if(store[inIndex] > store[inIndex+1]) {
				swap(store[inIndex], store[inIndex+1]);
			}
		}
	}
	return store;
}
