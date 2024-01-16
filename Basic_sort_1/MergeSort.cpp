
#include<iostream>
#include"head.h"
using namespace std;

void MergeSort(int* array, int low, int high) {

	int len = high - low + 1;//���鳤��
	if (len<=1) return;

	int mid = low+len/2;

	MergeSort(array,low,mid-1);
	MergeSort(array,mid,high);
	/////////////////////////////////////////�Ȼ��֣������

	int* a=new int[len];
	for (int k = 0; k < len; k++) {
		a[k] = 0;
	}

	int i = low;
	int j = mid;
	int k = 0;
	/////////////////////�����ر����״������������ʼλ�ú���ֹλ��Ҫע��

	while (i <= mid - 1 && j <= high) {
		if (array[i] < array[j]) {
			a[k++] = array[i++];
		}
		else {
			a[k++] = array[j++];
		}
	}

	while (i <= mid - 1) {
		////////////////////////////����Ҳ��while����ס
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