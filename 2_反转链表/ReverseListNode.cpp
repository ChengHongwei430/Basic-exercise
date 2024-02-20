
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
		L->val = 1+rand()%(9-1+1);//生成1-9的随机数
		p->next = L;
		p = L;
	}
	p = L1;
	cout << "初始链表：";
	while (p) {
		cout << p->val << "\t";
		p = p->next;
	}
	cout << endl;

	p = L1->next;
	L1->next = NULL;//头插法，断开第一个节点
	ListNode* q = p-> next;
	while (p) {
		p->next=L1;
		L1 = p;
		p = q;
		if(q) q = q->next;
	}

	cout << "新链表：";
	p = L1;
	while (p) {
		cout << p->val << "\t";
		p = p->next;
	}
	cout << endl;



	system("pause");
	return 0;
}