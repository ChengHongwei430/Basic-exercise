
#include<iostream>
using namespace std;

// �������˻���Ϊ��
class Account {
public:
    static double m_rate;
    static void set_rate(const double& x) {
        m_rate = x;
        // ��ͨ�ĳ�Ա�����ǲ�������д��
        // ��Ϊ������ͨ�ĳ�Ա������ÿ�����������Ӧһ����Ա����
        // ����Ӧ����
    }
};

double Account::m_rate = 8.0;
// Ĭ��ֵ
// �Ҳ�����Ϊʲô��̬��������ֱ�����������ó�ʼֵ

int main(){

    Account::set_rate(5.0);
    // �ڻ�û�н��������֮ǰ���Ϳ�������m_rate��ֵ

    cout<< Account:: m_rate <<endl;

    Account a;
    a.set_rate(7.0);



    system("pause");
}