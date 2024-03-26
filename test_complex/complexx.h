
#ifndef _complexx_
#define _complexx_//——一定要加，不知道为什么不加就报错，无法识别类名

class complexx;
complexx& doapl(complexx* a, const complexx& b);

class complexx{

public:
	complexx(double a=0,double b=0) : re(a),im(b) { }//参数值初始化的写法
	complexx(double a, double b, double c) : re(a), im(b+c) { }
	//构造函数重载，不能设默认值，那会让编译器无法识别
	complexx& operator +=(const complexx& a) {
		return doapl(this,a);
	}//实现+=的操作符重载
	
	double realshow() const { return this->re; }
	double imagshow() const { return this->im; }
	//函数不会改变变量值，必须加上const
private:
	double re, im;

friend complexx& doapl(complexx*, const complexx&);//友元只写类型不写变量名

};

//友元，可以直接使用complexx的私有变量
complexx& doapl(complexx* a, const complexx& b) {
	a->re = b.re + a->re;
	a->im = b.im + a->im;
	return *a;//返回a的值，但采用引用方式接收
}

complexx operator +(const complexx& x, const complexx& y) {
	return complexx( x.realshow()+ y.realshow(), x.imagshow() + y.imagshow());
}//放到类定义函数外面的函数
//创建临时对象，不能采用引用方式接收

#endif // !complex