
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
		L->val = i;//����1-9�������
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

	//����
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

	cout << "������";
	p = L1;
	while (p) {
		cout << p->val << "\t";
		p = p->next;
	}
	cout << endl;

	//class Solution {
	//public:
	//	void reorderList(ListNode* head) {

	//		//����������
	//		ListNode* p = head;
	//		int len = 0;
	//		while (p) {
	//			len++;
	//			p = p->next;
	//		}

	//		if (len <= 1)
	//			return;

	//		//�����β𿪳�һ��������
	//		p = head;
	//		int i = 0;
	//		while (p) {
	//			if (i >= (len - 1) / 2) {
	//				break;
	//			}
	//			p = p->next;
	//			i++;
	//		}


	//		// ����������
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

	//		// ֱ�Ӻϲ���������
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