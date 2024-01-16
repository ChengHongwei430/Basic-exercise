
#include<iostream>
#include"head.h"
using namespace std;

void QuickSort(int* array, int low, int high) {

	//int len = sizeof(array) / sizeof(int);
	// 不能这么写，因为这里的array代表指针，长度与数组不同

	if (low >= high) return;
	//递归出口

	int temp = array[low];
	int i = low;
	int j = high;
	while (i < j) {
		while (i<j && array[j]>temp) --j;
		array[i] = array[j];
		while (i<j && array[i]<temp) ++i;
		array[j] = array[i];
	}
	array[i] = temp;

	/*QuickSort(&array[low], low, i - 1);
	QuickSort(&array[i + 1], i + 1, high);*/
	//////////////////////////////////这样写不对，因为这样使数组的起点变了

	QuickSort(array, low, i - 1);//先调整，后划分
	QuickSort(array, i + 1, high);
}