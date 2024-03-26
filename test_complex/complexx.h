
#ifndef _complexx_
#define _complexx_//����һ��Ҫ�ӣ���֪��Ϊʲô���Ӿͱ����޷�ʶ������

class complexx;
complexx& doapl(complexx* a, const complexx& b);

class complexx{

public:
	complexx(double a=0,double b=0) : re(a),im(b) { }//����ֵ��ʼ����д��
	complexx(double a, double b, double c) : re(a), im(b+c) { }
	//���캯�����أ�������Ĭ��ֵ���ǻ��ñ������޷�ʶ��
	complexx& operator +=(const complexx& a) {
		return doapl(this,a);
	}//ʵ��+=�Ĳ���������
	
	double realshow() const { return this->re; }
	double imagshow() const { return this->im; }
	//��������ı����ֵ���������const
private:
	double re, im;

friend complexx& doapl(complexx*, const complexx&);//��Ԫֻд���Ͳ�д������

};

//��Ԫ������ֱ��ʹ��complexx��˽�б���
complexx& doapl(complexx* a, const complexx& b) {
	a->re = b.re + a->re;
	a->im = b.im + a->im;
	return *a;//����a��ֵ�����������÷�ʽ����
}

complexx operator +(const complexx& x, const complexx& y) {
	return complexx( x.realshow()+ y.realshow(), x.imagshow() + y.imagshow());
}//�ŵ��ඨ�庯������ĺ���
//������ʱ���󣬲��ܲ������÷�ʽ����

#endif // !complex