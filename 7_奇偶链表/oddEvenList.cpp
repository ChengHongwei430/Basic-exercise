
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
	for (int i = 1; i < 10; ++i) {
		ListNode* L = new ListNode();
		L->val = i+1;//生成1-9的随机数
		p->next = L;
		p = L;
	}

	ListNode*  L = L1;
	p = L;
	cout << "初始链表：";
	while (p) {
		cout << p->val << "\t";
		p = p->next;
	}
	cout << endl;


	ListNode* L2 = L1?L1->next:NULL;

	ListNode* a = L1;
	ListNode* ar = a;
	ListNode* b = L2;

	while(a&&b)
	{
		if(a && b){
			a->next = b->next;
			a = a->next;
		}
		if (a && b) {
			b->next = a->next;
			b = b->next;
		}
	}

	while (ar->next) {
		ar = ar->next;
	}
	ar->next = L2;

	cout << "新链表：";
	p = L1;
	while (p) {
		cout << p->val << "\t";
		p = p->next;
	}
	cout << endl;

	//class Solution {
	//public:
	//	ListNode* oddEvenList(ListNode* head) {

	//		if (head == NULL) return head;
	//		ListNode* a = head;
	//		ListNode* L = head->next;
	//		ListNode* b = head->next;

	//		while (b && b->next) {
	//			a->next = b->next;
	//			a = a->next;
	//			b->next = a->next;
	//			b = b->next;
	//		}
	//		a->next = L;
	//		return head;
	//	}
	//};

	system("pause");
	return 0;
}