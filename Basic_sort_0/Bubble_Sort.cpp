#include<iostream>
using namespace std;

int main()
{

	//int x;
	//cin >> x;
	//cout << x << endl;//�������


	//void bubbleSort(vector<int>&a, int n) {
	int n = 10;
	int a[] = { 3, 5, 7, 2, 4, 1, 8, 2, 9, 4 };

	cout << "����ǰ������Ϊ��" << endl;
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}


	cout << "����������Ϊ��" << endl;
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;

	// �ȶ��������㷨��ð���塢��
	// ���ȶ����п졢ѡ��ϣ������
	// ������Ͱ������
	// 
	//}

}
