
#include <iostream>
using namespace std;

void QuickSort(int* data,int low,int high) {

	if (low >= high) return;///////////һ��Ҫһ���ݹ����
	int temp = data[low];
	int i = low;
	int j = high;
	while (i < j) {
		while (i < j && data[j]>temp) --j;
		if(i < j) data[i++] = data[j];/////////©�˸��º������ı䶯
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
		data[i]= 1 + rand() % (9 - 1 + 1);//����1-9�������;
	}

	cout << "��ʼ��";
	int i = 0;
	while (i<len) {
		cout << data[i] << "\t";
		++i;
	}
	cout << endl;

	QuickSort(data, 0, len - 1);

	cout << "�µı�";

	i = 0;
	while (i < len) {
		cout << data[i] << "\t";
		++i;
	}
	cout << endl;


	system("pause");
	return 0;
}