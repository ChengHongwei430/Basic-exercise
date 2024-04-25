
#include<iostream>
using namespace std;

// 以银行账户类为例
class Account {
public:
    static double m_rate;
    static void set_rate(const double& x) {
        m_rate = x;
        // 普通的成员变量是不能这样写的
        // 因为对于普通的成员变量，每个类变量都对应一个成员变量
        // 所以应该在
    }
};

double Account::m_rate = 8.0;
// 默认值
// 我不明白为什么静态变量不能直接在类里设置初始值

int main(){

    Account::set_rate(5.0);
    // 在还没有建立类变量之前，就可以设置m_rate的值

    cout<< Account:: m_rate <<endl;

    Account a;
    a.set_rate(7.0);



    system("pause");
}