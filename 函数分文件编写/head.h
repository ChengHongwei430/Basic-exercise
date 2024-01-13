
#pragma once//只要在头文件的最开始加入这条预处理指令，
//就能够保证头文件只被编译一次，防止头文件被重复引用。

//头文件里也使用了iostream的内容，所以也要包括
#include<iostream>
using namespace std;

//函数声明
void swap(int a, int b);
