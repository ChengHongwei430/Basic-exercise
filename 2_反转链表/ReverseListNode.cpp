
#include <iostream>
using namespace std;


struct ListNode {
	int val;
	struct ListNode* next;
};

int main() {

	ListNode* L1 = new ListNode();
	L1->val = 1;

	ListNode* p = L1;
	for (int i = 0; i < 10; ++i) {
		ListNode* L = new ListNode();
		L->val = 1+rand()%(9-1+1);//����1-9�������
		p->next = L;
		p = L;
	}
	p = L1;
	cout << "��ʼ����";
	while (p) {
		cout << p->val << "\t";
		p = p->next;
	}
	cout << endl;

	p = L1->next;
	L1->next = NULL;//ͷ�巨���Ͽ���һ���ڵ�
	ListNode* q = p-> next;
	while (p) {
		p->next=L1;
		L1 = p;
		p = q;
		if(q) q = q->next;
	}

	cout << "������";
	p = L1;
	while (p) {
		cout << p->val << "\t";
		p = p->next;
	}
	cout << endl;



	system("pause");
	return 0;
}