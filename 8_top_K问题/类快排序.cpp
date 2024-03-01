
#include<iostream>
#include"problem.h"
using namespace std;


int quicksort(int a[], int low, int high) {
	int mid = a[low];
	int i = low, j = high;
	while (i < j) {
		while (i < j && a[j] < mid) j--;
		a[i++] = a[j];
		while (i < j && a[i] > mid) i++;
		a[j--] = a[i];
	}
	a[i] = mid;
	//cout << a[i] << endl;
	//for (int ii = 0; ii < 15; ii++) {
	//	cout << a[ii] << " ";
	//}
	//cout << endl;
	return i;
}


int sort(int a[], int low, int high,int k) {

	int i=quicksort(a,low,high);
	if (k == i + 1) {
		return a[i];
	}
	else if(k < i + 1) {
		sort(a,low,i-1,k);
	}
	else {
		sort(a,i+1,high,k);//k不减少，因为是对数组操作
	}
}


int main() {

	for (int i = 0; i < len; i++) {
		a[i] = rand() % len;
	}

	int llen = len;

	int ax=sort(a,0,llen-1,20);

	cout << ax << endl;

	system("pause");
	return 0;

}



