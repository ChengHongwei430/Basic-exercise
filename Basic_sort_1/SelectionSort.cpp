
#include<iostream>
#include"head.h"
using namespace std;

void SelectionSort(int* array,int len) {

	//int len = sizeof(array) / sizeof(int);
	//////////////////////////////// ������ôд����Ϊ�����array����ָ�룬���������鲻ͬ

	for (int i = 0; i < len-1 ; i++) {
		int temp = i;
		for (int j = i+1; j < len-1; j++) {
			if (array[j + 1] < array[temp]) {
				temp = j + 1;
			}
		}
		if (temp != i) {
			int tempp = array[temp];
			array[temp] = array[i];
			array[i] = tempp;
		}
	}

}