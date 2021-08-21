#include <iostream>
using namespace std;

template<typename T>
T* insertion_sort(T* arr, int size) {
	
	T* store = new T[size];
	for(int index = 0 ; index < size ; ++index) {
		store[index] = arr[index];
	}

	for(int outIndex = 0 ;  outIndex < size ; ++outIndex) {
		int key = store[outIndex];
		int inIndex = outIndex-1;
		while(inIndex >= 0 && key < store[inIndex]) {
			store[inIndex+1] = store[inIndex];
			--inIndex;
		}
		store[inIndex+1] = key;
	}
	return store;
}
