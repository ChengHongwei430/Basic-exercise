
#include<iostream>
#include"head.h"
using namespace std;

void QuickSort(int* array, int low, int high) {

	//int len = sizeof(array) / sizeof(int);
	// ������ôд����Ϊ�����array����ָ�룬���������鲻ͬ

	if (low >= high) return;
	//�ݹ����

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
	//////////////////////////////////����д���ԣ���Ϊ����ʹ�����������

	QuickSort(array, low, i - 1);//�ȵ������󻮷�
	QuickSort(array, i + 1, high);
}