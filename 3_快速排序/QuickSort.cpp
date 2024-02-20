
#include <iostream>
using namespace std;

void QuickSort(int* data,int low,int high) {

	if (low >= high) return;///////////一定要一个递归出口
	int temp = data[low];
	int i = low;
	int j = high;
	while (i < j) {
		while (i < j && data[j]>temp) --j;
		if(i < j) data[i++] = data[j];/////////漏了更新后索引的变动
		while (i < j && data[i]<temp) ++i;
		if(i < j) data[j--] = data[i];
	}
	data[i] = temp;
	QuickSort(data, low, i-1);
	QuickSort(data, i + 1, high);
}


int main() {

	int len = 12;
	int * data = new int[len] ;

	srand(time(0));
	for (int i = 0; i < len; ++i) {
		data[i]= 1 + rand() % (9 - 1 + 1);//生成1-9的随机数;
	}

	cout << "初始表：";
	int i = 0;
	while (i<len) {
		cout << data[i] << "\t";
		++i;
	}
	cout << endl;

	QuickSort(data, 0, len - 1);

	cout << "新的表：";

	i = 0;
	while (i < len) {
		cout << data[i] << "\t";
		++i;
	}
	cout << endl;


	system("pause");
	return 0;
}