
#include<iostream>
#include"head.h"
using namespace std;

void MergeSort(int* array, int low, int high) {

	int len = high - low + 1;//数组长度
	if (len<=1) return;

	int mid = low+len/2;

	MergeSort(array,low,mid-1);
	MergeSort(array,mid,high);
	/////////////////////////////////////////先划分，后调整

	int* a=new int[len];
	for (int k = 0; k < len; k++) {
		a[k] = 0;
	}

	int i = low;
	int j = mid;
	int k = 0;
	/////////////////////这里特别容易错，三个数组的起始位置和终止位置要注意

	while (i <= mid - 1 && j <= high) {
		if (array[i] < array[j]) {
			a[k++] = array[i++];
		}
		else {
			a[k++] = array[j++];
		}
	}

	while (i <= mid - 1) {
		////////////////////////////这里也是while，记住
		a[k++] = array[i++];
	}
	while (j <= high) {
		a[k++] = array[j++];
	}
	for (int k = 0; k < len; k++) {
		array[low+k] = a[k];
	}

	delete[] a;
}