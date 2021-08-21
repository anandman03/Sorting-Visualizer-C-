#include <iostream>
using namespace std;

template<typename T>
T* bubble_sort(T* arr, int size) {
	
	T* store = new T[size];
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
