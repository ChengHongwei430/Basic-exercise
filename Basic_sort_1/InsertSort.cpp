
#include<iostream>
#include"head.h"
using namespace std;

void InsertSort(int* array, int len) {

	//int len = sizeof(array) / sizeof(int);
	// ������ôд����Ϊ�����array����ָ�룬���������鲻ͬ

	for (int i = 1; i < len; ++i) {

		//�ҵ����ʵĲ���λ��
		int temp = i;
		int tempp = array[i];
		for (int j = i-1; j>=0 ; --j) {
			if (tempp < array[j]) {
				temp = j;
			}
		}
		//���룬����temp������ڵģ�ֱ��i-1�ĺ���һλ
		if (temp <= i - 1) {
			for (int k = i - 1; k >= temp; --k) {
				array[k + 1] = array[k];
			}
		}
		array[temp] = tempp;
	}

}