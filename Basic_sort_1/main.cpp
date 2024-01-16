
#include<iostream>
#include"head.h"
using namespace std;

int main() {

	int array[] = { 3,5,1,6,2,7,9,8,4 };

	for (int i = 0; i < sizeof(array) / sizeof(int); i++) {
		cout << array[i];
	}
	cout << endl;

	int len = sizeof(array) / sizeof(int);

	int selection;
	while (1) {
		cout << "请输入选择的算法：" << endl;
		cin >> selection;
		switch (selection) {
		case 1:
			SelectionSort(array, len);
			//////////////////////数组变量保存的就是指针，不能写数组的地址
			break;
		case 2:
			InsertSort(array, len);
			break;
		case 3: 
			BubbleSort(array, len);
			break;
		case 4:
			QuickSort(array,0,len-1);
			break;
		case 5:
			ShellSort(array, len);
			break;
		case 6:
			MergeSort(array, 0, len - 1);
			break;
		default:
			cout << "请重新输入！" << endl;
		}
		cout << "排序完成！" << endl;
		break;
	}
	
	for (int i = 0; i < sizeof(array) / sizeof(int); i++) {
		cout << array[i];
	}
	cout << endl;

	system("pause");
	return 0;

}