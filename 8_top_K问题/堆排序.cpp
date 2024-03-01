
#include<iostream>
#include"problem.h"
using namespace std;

void adjust(int a[],int len) {//大根堆调整

	int d = (len - 1) / 2;
	for (int i = d; d >= 0; --d) {
		int x = 2 * d + 1;
		if (2 * d + 2 < len) {//符号不能错
			if (a[2*d+2] > a[2 * d + 1]) {
				x = 2 * d + 2;
			}
		}
		if (a[x] > a[d]) {
			int temp = a[x];
			a[x] = a[d];
			a[d] = temp;
		}
	}

}

int sort(int a[], int len,int k) {

	adjust(a, len);
	while(k-1)
	{
		cout << a[0] << endl;
		len--;
		a[0] = a[len];
		adjust(a, len);
		k--;
	}
	return a[0];
}


int main() {

	for (int i = 0; i < 10000; i++) {
		a[i] = rand() % 10000;
	}

	int llen = len;

	int ax = sort(a, llen, 20);

	cout << ax << endl;

	//for (int i = 0; i < 100; i++) {
	//	cout << a[i] << endl;
	//}

	system("pause");
	return 0;

}



