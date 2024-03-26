
#include<iostream>
#include"complexx.h"
using namespace std;

int main() {

	complexx c1(1,1),c2(2,2),c3(3,1,2);

	cout <<"("<< c3.realshow() <<","<< c3.imagshow() << ")" << endl;
	//cout << c1.re << endl;私有不可访问

	c1 += c2;
	cout << "(" << c1.realshow() << "," << c1.imagshow() << ")" << endl;

	c2 = c1 + c3;
	cout << "(" << c2.realshow() << "," << c2.imagshow() << ")" << endl;

	system("pause");
}