
#include<iostream>
using namespace std;

//һ��ͨ���͵���
//������
template<typename T>//template�ǹ̶��ģ�typenameҲ�ǹ̶���
class complex {
public:
    complex(T r = 0, T i = 0) : re(r), im(i) {
    };
    complex& operator += (const complex&);
    T real() const {//��������ı���ú����������ֵ
        return re;
    };
    T imag() const {
        return im;
    };
private:
    T re, im;
    friend complex& _doapl(complex*, const complex&);
    //��Ԫ��������ֱ��ʹ�����˽�г�Ա�����ͱ���                        
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
        //<�Ƕ���ߵı��������õģ�����b����<������ʹ��a��������
        return _we < s._we;
    }
    void show() const {
        cout << _w << " " << _h << " " << _we << endl;
    }
private:
    int _w, _h, _we;
};

template <typename T>//ÿ����֮ǰ��Ҫдһ��
const T& smin(const T& a, const T& b) {
    return b < a ? b : a;
    //<�Ƕ���ߵı��������õģ�����b����<������ʹ��a��������
}


int main() {

    complex<double> c1(2.5, 2.5);
    complex<int> c2(2, 2);

    cout << c1.real() << endl;
    cout << c2.real() << endl;

    stone r1(2, 3), r2(3, 3), r3;
    r3 = smin(r1, r2);//����ģ�������������Ͳ���ֱ��ָ��
    r3.show();

    system("pause");

};