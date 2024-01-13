
#include<iostream>
using namespace std;

void BubbleSort(int* arr, int len);

int main() {

	int arr[] = { 4,6,2,1,7,8,1,4,9,6,3 };
	int len = sizeof(arr) / sizeof(int);

	//BubbleSort(arr, len);//������������ľ��ǵ�ַ������Ҫ��&

	BubbleSort(&arr[0], len);//�����㴫�����һ������ĵ�ַ��Ҳ�������������ʽ����

	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
///////////////////////////////////////��ָ����ʽ������ð������
//void BubbleSort(int* arr, int len) {
//	int* p = arr;//����ָ���ʼλ��
//	for (int i = 0; i < (len-1) ; i++) {
//		p = arr;
//		for (int j = 0; j < len - i - 1; j++) {
//			if ((*p) > *(p + 1)){
//				int temp = *p;
//				*p = *(p + 1);
//				*(p + 1) = temp;
//			}
//			p++;
//		}
//	}
//}

//////////////////////Ҫʱ��ע��++x�ĺ��壬���׳���
//void BubbleSort(int* arr, int len) {
//	int* p = arr;//����ָ���ʼλ��
//	for (int i = 0; i < (len - 1); i++) {
//		p = arr;
//		for (int j = 0; j < len - i - 1; j++) {
//			if ((*p) > *(p + 1)) {
//				int temp = *p;
//				*(p-1)=*(++p);//��һ��ĺ�����൱��p=p+1;*(p-1)=*p;
//				*p = temp;
//			}
//			else {
//				++p;
//			}
//			
//		}
//	}
//}


///////////////////////��Ȼ�������һ����ַ����Ҳ�����������ʾ
void BubbleSort(int* arr, int len) {
	//�����㴫�����һ������ĵ�ַ��Ҳ�������������ʽ����
	for (int i = 0; i < (len - 1); i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (arr[j] > arr[j+1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];//��һ��ĺ�����൱��p=p+1;*(p-1)=*p;
				arr[j + 1]= temp;
			}
		}
	}
}
