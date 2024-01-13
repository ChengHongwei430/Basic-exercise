
#include<iostream>
using namespace std;

void swap1(int* p1, int* p2);
void swap2(int* p1, int* p2);

////////函数返回指针数组
// C++天然不支持返回数组，返回多个数据，以后使用结构体来返回
//using arrT = int*[2];//先定义一个数组的别名
//arrT swap(int* p1, int* p2) {
//	int* p = p1;
//	p1 = p2;
//	p2 = p;
//	//return {p1,p2};//指针不能用这种形式组成数组
//	int* pp[2] = { p1,p2 };
//	return pp;
//}

int main() {

	int a = 10;

	int* p;// *和int组成int* 表示整型的指针

	////////////////不管什么类型（32位操作系统4字节，64的8B）
	cout << sizeof(int*) << endl;
	cout << sizeof(char*) << endl;
	cout << sizeof(double*) << endl;
	cout << sizeof(float*) << endl;
	// x86就是32位操作系统，空间大小与指针类型无关

	p = &a;// & 就表示变量的地址
	cout << &a << endl;
	cout << p << endl;// 指针变量保存的就是地址，即指针=地址
	cout << *p << endl;// *表示解引用，可以理解为指针（地址）保存的值


	/////////////////////理解base64
	//计算机传输信息使用的是01代码，一般我们都是把日常字符转化为ASCII码
	//不同的传输协议对ASCII码的使用存在部分偏差，所以需要将ASCII码转为更基础大众通用的base64，以便再转为01

	/////////////////空指针里不能解引用
	//因为空指针所指地址（0）不允许访问，只能用来初始化，其实不写也行


	////////////////////////常量指针与指针常量
	const int* p1;//值不能改，指针地址可以改，所以不用初始化
	p1 = &a;
	cout << *p1 << "\t" << p1 << endl;
	int b = *p1;
	p1 = &b;
	cout << *p1 << "\t" << p1 << endl;


	int* const p2=&a;
	cout << *p2 << "\t" << p2 << endl;
	a = 99;
	cout << *p2 << "\t" << p2 << endl;
	const int* const p3 = &a;

	//////////利用指针访问数组
	int array[] = { 1,2,3,4,5,6,7,8,9 };
	int* pp = array;//数组名变量中保存的就是数组首元素的地址
	cout << *pp << "\t" << *array << endl;//数组也可以解引用，因为数组是引用型变量，类似指针


	///////////////////////////////////
	//sizeof返回的是数组所占内存，而不是元素个数
	int ii=10;
	for (int i = 0; i < sizeof(array)/(sizeof(int)); i++) {
		cout << *pp << "\t";
		pp++;///////////////////////指针后移
		if (i== (sizeof(array) / (sizeof(int)) - 1)){
			ii = i+1;
			int iii = i + 1;
		}	
	}
	////////////////////////////////
	//在for中定义的变量用完i就被删除了
	cout << endl;
	cout << ii << endl;
	//cout << iii << endl;//会报错

	///////////////////指针与函数
	int a1 = 10;
	int a2 = 20;

	cout << a1 << "-" << &a1 << "\t" << a2 << "-" << &a2 << endl;
	swap1(&a1, &a2);
	cout << a1 << "-" << &a1 << "\t" << a2 << "-" << &a2 << endl;
	swap2(&a1, &a2);
	cout << a1 << "-" << &a1 << "\t" << a2 << "-" << &a2 << endl;

	system("pause");

	return 0;
}

void swap1(int* p1, int* p2) {//交换了指针p1的p2内容（也就是地址），但没有改变指针所指向的变量a，b的值
	cout << p1 << "-" << *p1 << "\t" << p2 << "-" << *p2 << endl;
	int* p = p1;
	p1 = p2;
	p2 = p;
	int* x[] = { p,p1,p2 };
	cout << p1 << "-" << *p1 << "\t" << p2 << "-" << *p2 << endl;
}

//int* swap1(int* p1, int* p2) {//交换了指针p1的p2内容（也就是地址），但没有改变指针所指向的变量a，b的值
//	cout << p1 << "-" << *p1 << "\t" << p2 << "-" << *p2 << endl;
//	int* p = p1;
//	p1 = p2;
//	p2 = p;
//	cout << p1 << "-" << *p1 << "\t" << p2 << "-" << *p2 << endl;
//	return p1;
//}//不能重载只按返回值区分的函数



void swap2(int* p1, int* p2) {
	int p = *p1;
	*p1 = *p2;
	*p2 = p;
}