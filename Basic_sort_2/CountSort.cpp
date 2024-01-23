

#include<iostream>
using namespace std;
#define INF 1000

int main() {

	int array[] = { 23,23,35,35,35,35,13,25,45,45,45,45,45,36,17,26,26,26,38,29,31 };
	//int array[] = { 3,3,4,4,6,7,8,8,8,9,7,5,4 };

	int height = sizeof(array) / sizeof(int);
	int max_table = -INF;
	int min_table = INF;

	for (int i = 0; i < height; ++i) {
		if (array[i] < min_table) min_table = array[i];
		if (array[i] > max_table) max_table = array[i];
	}//找最值

	int* CountArray = new int[max_table- min_table+1];//用new新建一个指针
	for (int i = 0; i < max_table - min_table + 1; ++i) {
		CountArray[i] = 0;
	}

	for (int i = 0; i < height; ++i) {
		++CountArray[array[i] - min_table];
	}

	for (int i = 0; i < max_table - min_table + 1; ++i) {
		for (int j = 0; j < CountArray[i]; j++) {
			cout << " " << i + min_table;
		}
	}
	cout << endl;


	system("pause");
	return 0;
}