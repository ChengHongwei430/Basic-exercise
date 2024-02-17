#include<iostream>
using namespace std;

int main()
{

	int aa[] = { 3, 5, 7, 9 ,2, 4, 1, 8, 2, 4 };

	cout << "待排序数组为：" << endl;
	for (int i = 0; i < sizeof(aa); i++) {
		cout << aa[i] << " ";
	}
	cout << endl;


	
	for (int i = 0; i < sizeof(aa) - 1; i++) {
		bool flag = false;
		for (int j = 0; j < sizeof(aa) - i - 1; j++) {
			if (aa[j] > aa[j + 1]) {
				flag = true;
				int temp = aa[j];
				aa[j] = aa[j + 1];
				aa[j + 1] = temp;
			}
		}
		if (flag == false) {
			break;
		}
	}


	cout << "排序后的数组为：" << endl;
	for (int i = 0; i < sizeof(aa); i++) {
		cout << aa[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;

}
