

//���������� �������� ��ʽ��¼��ѵ���ƻ� l1��l2��
// �ֱ��¼�����׺��ļ�Ⱥѵ����Ŀ��ţ���ϲ�������ѵ���ƻ�,
// ��ѵ����Ŀ��� ���� ��¼���������ء�

//��һ���½ڵ�ListNode* prehead=new ListNode();
//����βָ��ListNode* Tail=prehead;
//�Ƚ�������������
//�ϲ�ʣ������
//���prehead->next

#include<iostream>
using namespace std;

struct List_Node
{
	int val;
	struct List_Node* next;
};

int main() {

	List_Node* l1 = new List_Node();//ֻ�мӣ������Ż�ʹnextΪnull
	List_Node* l2 = new List_Node();
	
	List_Node* p=l1;
	for (int i = 0; i < 10; ++i) {
		List_Node* L = new List_Node();
		L->val = 3+i+(i+10)%3;
		p->next=L;
		p = L;
	}

    p = l1;
    while (p != NULL) {
        cout << p->val << "  ";
        p = p->next;
    }
    cout << endl;

    p = l2;
    for (int i = 0; i < 10; ++i) {
        List_Node* L = new List_Node();
        L->val = 2 + i + (i + 10) % 2;
        p->next = L;
        p = L;
    }

    p = l2;
    while (p != NULL) {
        cout << p->val << "  ";
        p = p->next;
    }
    cout << endl;

	
     List_Node* head = NULL;
     List_Node* tail = NULL;

        while(l1!=NULL&&l2!=NULL){

            if(l1->val<=l2->val){
                head=l1;
                tail=l1;
                l1=l1->next;
            }
            else{
                head=l2;
                tail=l2;
                l2=l2->next;
            }

            while(l1!=NULL&&l2!=NULL){
                if(l1->val<=l2->val){
                    tail->next=l1;
                    l1=l1->next;
                }
                else{
                    tail->next=l2;
                    l2=l2->next;
                }
                tail=tail->next;
            }
        }

        if(l1!=NULL) tail->next=l1;
        if(l2!=NULL) tail->next=l2;

        p = head;
        while (p!=NULL) {
        	cout << p->val<<"  ";
        	p = p->next;
        }
        cout << endl;

    //ListNode* head = new ListNode();//��ݷ�����һ�ѱ�ס
    //ListNode* tail = head;

    //while (l1 && l2) {
    //    if (l1->val <= l2->val) {
    //        tail->next = l1;
    //        l1 = l1->next;
    //        tail = tail->next;
    //    }
    //    else {
    //        tail->next = l2;
    //        l2 = l2->next;
    //        tail = tail->next;
    //    }
    //}
    //if (l1) tail->next = l1;
    //if (l2) tail->next = l2;


	system("pause");
	return 0;
}