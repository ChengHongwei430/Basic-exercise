
#include<iostream>
#include"head.h"
using namespace std;


int main() {

	int array[] = { 3,1,5,4,2,6,9,8,7,3,6,3,6,4,6,4,4,5,5,6,5,5,6,2 };
	cout << "排序前序列：" << endl;

	int height = sizeof(array) / sizeof(int);
	for (int i = 0; i < height; ++i) {
		cout << array[i] << " ";
	}
	cout << endl;

	tree T;
	Creat_max_heapify(array,&T,height);//结构体变量也要写地址
	Heapify_sort(array, &T, height);


	cout << "排序后序列：" << endl;
	for (int i = 0; i < height; ++i) {
		cout << array[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}

