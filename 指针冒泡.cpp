
#include<iostream>
using namespace std;

void BubbleSort(int* arr, int len);

int main() {

	int arr[] = { 4,6,2,1,7,8,1,4,9,6,3 };
	int len = sizeof(arr) / sizeof(int);

	//BubbleSort(arr, len);//数组变量本身存的就是地址，不需要加&

	BubbleSort(&arr[0], len);//哪怕你传入的是一个纯粹的地址，也可以用数组的形式调用

	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
///////////////////////////////////////纯指针形式的数组冒泡排序
//void BubbleSort(int* arr, int len) {
//	int* p = arr;//保存指针初始位置
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

//////////////////////要时刻注意++x的含义，容易出错
//void BubbleSort(int* arr, int len) {
//	int* p = arr;//保存指针初始位置
//	for (int i = 0; i < (len - 1); i++) {
//		p = arr;
//		for (int j = 0; j < len - i - 1; j++) {
//			if ((*p) > *(p + 1)) {
//				int temp = *p;
//				*(p-1)=*(++p);//这一句的含义就相当于p=p+1;*(p-1)=*p;
//				*p = temp;
//			}
//			else {
//				++p;
//			}
//			
//		}
//	}
//}


///////////////////////虽然传入的是一个地址，但也可以用数组表示
void BubbleSort(int* arr, int len) {
	//哪怕你传入的是一个纯粹的地址，也可以用数组的形式调用
	for (int i = 0; i < (len - 1); i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (arr[j] > arr[j+1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];//这一句的含义就相当于p=p+1;*(p-1)=*p;
				arr[j + 1]= temp;
			}
		}
	}
}
