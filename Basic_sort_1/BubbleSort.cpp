
#include<iostream>
#include"head.h"
using namespace std;


void BubbleSort(int* array, int len) {

	//int len = sizeof(array) / sizeof(int);
	// 不能这么写，因为这里的array代表指针，长度与数组不同

	for (int i = 0; i < len-1; ++i) {
		for (int j = 0; j < len-i-1 ; ++j) {
			if ( array[j] > array[j+1] ) {
				swap(&array[j], &array[j+1]);
				/////////////////函数内嵌套函数，也可以这样写
				/*int temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;*/
			}
		}
	}

}