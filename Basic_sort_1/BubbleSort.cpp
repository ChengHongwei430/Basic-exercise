
#include<iostream>
#include"head.h"
using namespace std;


void BubbleSort(int* array, int len) {

	//int len = sizeof(array) / sizeof(int);
	// ������ôд����Ϊ�����array����ָ�룬���������鲻ͬ

	for (int i = 0; i < len-1; ++i) {
		for (int j = 0; j < len-i-1 ; ++j) {
			if ( array[j] > array[j+1] ) {
				swap(&array[j], &array[j+1]);
				/////////////////������Ƕ�׺�����Ҳ��������д
				/*int temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;*/
			}
		}
	}

}