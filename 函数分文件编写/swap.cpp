
//函数声明  意义是为了把函数写在主函数后面

#include <iostream>
#include "head.h"
using namespace std;

//void swap (int a, int b);

void swap(int a, int b) {

	int temp;
	temp = a;
	a = b;
	b = temp;
}
