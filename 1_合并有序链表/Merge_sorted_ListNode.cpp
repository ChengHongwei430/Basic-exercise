

//给定两个以 有序链表 形式记录的训练计划 l1、l2，
// 分别记录了两套核心肌群训练项目编号，请合并这两个训练计划,
// 按训练项目编号 升序 记录于链表并返回。

//建一个新节点ListNode* prehead=new ListNode();
//建立尾指针ListNode* Tail=prehead;
//比较链接两个链表
//合并剩余链表
//输出prehead->next

#include<iostream>
using namespace std;

struct List_Node
{
	int val;
	struct List_Node* next;
};

int main() {

	List_Node* l1 = new List_Node();//只有加（），才会使next为null
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

    //ListNode* head = new ListNode();//快捷方法，一把背住
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