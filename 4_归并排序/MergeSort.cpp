

#include <iostream>
using namespace std;

void MergeSort(int* data, int low, int high) {

	if (low >= high) return;///////////һ��Ҫһ���ݹ����
	int mid = (low + high) / 2;

	MergeSort(data, low, mid);
	MergeSort(data, mid+1, high);

	int* newdata = new int[high-low+1];///////Ĭ�ϵ���һ��0-len-1��������
	int i = low, j = mid + 1, k = 0;

	while (i <= mid && j <= high) {
		newdata[k++] = (data[i] < data[j]) ? data[i++] : data[j++];
	}
	while (i <= mid) newdata[k++] = data[i++];
	while (j <= high) newdata[k++] = data[j++];

	k = 0;
	while (low <= high) data[low++] = newdata[k++];
	delete newdata;
}


int main() {

	int len = 12;
	int* data = new int[len];

	srand(time(0));
	for (int i = 0; i < len; ++i) {
		data[i] = 1 + rand() % (9 - 1 + 1);//����1-9�������;
	}

	cout << "��ʼ��";
	int i = 0;
	while (i < len) {
		cout << data[i] << "\t";
		++i;
	}
	cout << endl;

	MergeSort(data, 0, len - 1);

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