
#include <iostream>
using namespace std;


struct ListNode {
	int val;
	struct ListNode* next;
};

int main() {

	ListNode* L1 = new ListNode();
	L1->val = 0;

	ListNode* p = L1;
	for (int i = 1; i < 10; ++i) {
		ListNode* L = new ListNode();
		L->val = i;//生成1-9的随机数
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

	//长度
	p = L1;
	int len = 0;
	while (p) {
		len++;
		p = p->next;
	}

	p = L1;
	int i = 0;
	while (p) {
		if (i >= (len-1) / 2) {
			break;
		}
		p = p->next;
		i++;
	}

	ListNode* P = p->next;
	p->next = NULL;
	ListNode* a = P->next;
	P->next = NULL;
	ListNode* b = (a) ? a->next:NULL;
	while (a) {
		a->next = P;
		P = a;
		a = b;
		b=(a)? a->next : NULL;
	}

	a = P;
	b = L1->next;
	p = L1;

	while (a || b) {
		if(a){
			p->next = a;
			a = a->next;
			p = p->next;
		}
		if(b){
			p->next = b;
			b = b->next;
			p = p->next;
		}
	}
	p->next = NULL;

	cout << "新链表：";
	p = L1;
	while (p) {
		cout << p->val << "\t";
		p = p->next;
	}
	cout << endl;

	//class Solution {
	//public:
	//	void reorderList(ListNode* head) {

	//		//计算链表长度
	//		ListNode* p = head;
	//		int len = 0;
	//		while (p) {
	//			len++;
	//			p = p->next;
	//		}

	//		if (len <= 1)
	//			return;

	//		//将后半段拆开成一个新链表
	//		p = head;
	//		int i = 0;
	//		while (p) {
	//			if (i >= (len - 1) / 2) {
	//				break;
	//			}
	//			p = p->next;
	//			i++;
	//		}


	//		// 逆序后半链表
	//		ListNode* P = p->next;
	//		p->next = NULL;
	//		if (P->next) {
	//			ListNode* aa = P->next;
	//			P->next = NULL;
	//			ListNode* bb = (aa) ? aa->next : NULL;
	//			while (aa) {
	//				aa->next = P;
	//				P = aa;
	//				aa = bb;
	//				bb = (aa) ? aa->next : NULL;
	//			}
	//		}

	//		// 直接合并两个链表
	//		ListNode* a = P;
	//		ListNode* b = head->next;

	//		p = head;

	//		while (a || b) {
	//			if (a) {
	//				p->next = a;
	//				a = a->next;
	//				p = p->next;
	//			}
	//			if (b) {
	//				p->next = b;
	//				b = b->next;
	//				p = p->next;
	//			}
	//		}
	//		p->next = NULL;
	//	}
	//};

	system("pause");
	return 0;
}