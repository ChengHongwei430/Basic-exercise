
#include<iostream>
#include"head.h"
using namespace std;


void ShellSort(int* array, int len) {

	int mid = len / 3;

	int* a = new int[len];
	//////////////////////////////////�ñ�����Ϊ���鳤��

	cout << "�䳤�����ʼֵ��" ;
	for (int i = 0; i < 9; i++) {
		cout << a[i]<<"\t";//���ɵĳ�ʼֵ���ر�
	}
	cout << endl;

	for (int i = 0; i < len; i++) {
		a[i]=0;
	}/////////////////////////Ҫ��ʼ������Ȼ��Ķ��Ǻ��ر����

	int k = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < mid; j++) {
			a[k++] = array[i + j * mid];
		}
		InsertSort(&a[i * mid], mid);//С���ڲ�������
	}

	cout << "С���ڲ�����������" ;
	for (int i = 0; i < 9; i++) {
		cout << a[i];
	}
	cout << endl;

	//����
	for (int k = 0; k < len; k++) {
		array[k] = a[k];
	}
	InsertSort(array, len);


}