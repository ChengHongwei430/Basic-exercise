
#include<iostream>
using namespace std;

//一个通用型的类
//负数类
template<typename T>//template是固定的，typename也是固定的
class complex {
public:
    complex(T r = 0, T i = 0) : re(r), im(i) {
    };
    complex& operator += (const complex&);
    T real() const {//函数不会改变调用函数的类变量值
        return re;
    };
    T imag() const {
        return im;
    };
private:
    T re, im;
    friend complex& _doapl(complex*, const complex&);
    //友元函数可以直接使用类的私有成员函数和变量                        
};

class stone {
public:
    stone(int w, int h)
        : _w(w), _h(h), _we(w*h)
    {}
    stone(){
        _w=0, _h=0, _we=0;
    }
    bool operator< (const stone& s) const {
        //<是对左边的变量来调用的，就像b调用<函数，使用a参数代入
        return _we < s._we;
    }
    void show() const {
        cout << _w << " " << _h << " " << _we << endl;
    }
private:
    int _w, _h, _we;
};

template <typename T>//每次用之前都要写一遍
const T& smin(const T& a, const T& b) {
    return b < a ? b : a;
    //<是对左边的变量来调用的，就像b调用<函数，使用a参数代入
}


int main() {

    complex<double> c1(2.5, 2.5);
    complex<int> c2(2, 2);

    cout << c1.real() << endl;
    cout << c2.real() << endl;

    stone r1(2, 3), r2(3, 3), r3;
    r3 = smin(r1, r2);//函数模板的输入参数类型不会直接指明
    r3.show();

    system("pause");

};