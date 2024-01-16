
#include<iostream>
#include"head.h"
using namespace std;


void ShellSort(int* array, int len) {

	int mid = len / 3;

	int* a = new int[len];
	//////////////////////////////////用变量作为数组长度

	cout << "变长数组初始值：" ;
	for (int i = 0; i < 9; i++) {
		cout << a[i]<<"\t";//生成的初始值很特别
	}
	cout << endl;

	for (int i = 0; i < len; i++) {
		a[i]=0;
	}/////////////////////////要初始化，不然存的都是很特别的数

	int k = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < mid; j++) {
			a[k++] = array[i + j * mid];
		}
		InsertSort(&a[i * mid], mid);//小组内插入排序
	}

	cout << "小组内插入排序结果：" ;
	for (int i = 0; i < 9; i++) {
		cout << a[i];
	}
	cout << endl;

	//返回
	for (int k = 0; k < len; k++) {
		array[k] = a[k];
	}
	InsertSort(array, len);


}