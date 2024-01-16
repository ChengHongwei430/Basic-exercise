
#include<iostream>
#include"head.h"
using namespace std;

void InsertSort(int* array, int len) {

	//int len = sizeof(array) / sizeof(int);
	// 不能这么写，因为这里的array代表指针，长度与数组不同

	for (int i = 1; i < len; ++i) {

		//找到合适的插入位置
		int temp = i;
		int tempp = array[i];
		for (int j = i-1; j>=0 ; --j) {
			if (tempp < array[j]) {
				temp = j;
			}
		}
		//插入，包括temp编号在内的，直到i-1的后移一位
		if (temp <= i - 1) {
			for (int k = i - 1; k >= temp; --k) {
				array[k + 1] = array[k];
			}
		}
		array[temp] = tempp;
	}

}