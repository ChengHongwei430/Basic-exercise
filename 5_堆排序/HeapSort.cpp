

#include <iostream>
using namespace std;


void Adjust(int* data, int len) {//调整大根堆
	//父 (i-1)/2
	//左子 2*i+1
	//右子 2*i+2
	//最后一个有孩子的父 len / 2 - 1
	for (int i = len / 2 - 1; i >= 0; --i) {
		int maxson = 2 * i + 1;
		if (2 * i + 2 <= len - 1) {
			if (data[2 * i + 2]> data[2 * i + 1]) maxson = 2 * i + 2;
		}
		if (data[maxson] > data[i]) {
			int temp = data[maxson];//注意交换的写法
			data[maxson] = data[i];
			data[i] = temp;
		}
	}
	
}

void HeapSort(int* data, int len) {//堆排序

	cout << "新的表：";
	while (len) {
		Adjust(data, len);
		cout << data[0] << "\t";
		data[0] = data[len - 1];
		--len;
	}
	cout << endl;
	
}


int main() {

	int len = 6;
	int* data = new int[len];

	srand(10242);
	for (int i = 0; i < len; ++i) {
		data[i] = 1 + rand() % (9 - 1 + 1);//生成1-9的随机数;
	}

	cout << "初始表：";
	int i = 0;
	while (i < len) {
		cout << data[i] << "\t";
		++i;
	}
	cout << endl;

	HeapSort(data,len);


	system("pause");
	return 0;
}