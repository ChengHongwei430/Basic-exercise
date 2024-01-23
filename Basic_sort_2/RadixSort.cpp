

#include<iostream>
using namespace std;

struct node {
	int table;
	struct node* next;
};

struct node_array {
	struct node array[10];
};

int main() {

	int A[] = {3,23,25,35,15,35,13,23,25,45,45,35,5,6,17,26,36,26,8,69,91 };

	int height = sizeof(A) / sizeof(int);
	cout << endl;
	cout << "原数列： " << endl;
	for (int i = 0; i < height; ++i) {
		cout << " " << A[i];
	}
	cout << endl;

	node_array S;//定义尾数链表
	for (int i = 0; i < 10; ++i) {
		S.array[i].table = i;
		S.array[i].next = NULL;
	}


	node* k = new node[height];//建立排序表节点
	for (int i = 0; i < height; ++i) {
		k[i].table = A[i];
		k[i].next = NULL;
	}

	for (int i = 0; i < height; ++i) {//个位
		int temp = A[i] % 10;
		node* tempn = S.array[temp].next;
		S.array[temp].next = &k[i];
		k[i].next = tempn;
	}
	cout << endl;
	cout << "按尾数排列： " << endl;
	for (int i = 0; i < 10; ++i) {
		node* temp = S.array[i].next;
		while (temp) {
			cout << " " << temp->table;
			temp = temp->next;
		}
		cout << endl;
	}


	cout << endl;//保存
	int x = 0;
	for (int i = 0; i < 10; ++i) {
		node* temp = S.array[i].next;
		while (temp) {
			A[x++]=temp->table;//这里的++容易忽略
			temp = temp->next;
		}
	}
	for (int i = 0; i < height; ++i) {
		cout << " " << A[i];
	}
	cout << endl;




	for (int i = 0; i < 10; ++i) {//还原链表
		S.array[i].next = NULL;
	}
	for (int i = 0; i < height; ++i) {
		k[i].table = A[i];
		k[i].next = NULL;
	}

	for (int i = height-1; i >= 0; --i) {//百位,从后往前放入
		int temp = A[i]/10;
		node* tempn = S.array[temp].next;
		S.array[temp].next = &k[i];
		k[i].next = tempn;
	}

	cout << endl;
	cout << "按十位排列： " << endl;
	for (int i = 0; i < 10; ++i) {
		node* temp = S.array[i].next;
		while (temp) {
			cout << " " << temp->table;
			temp = temp->next;
		}
		cout << endl;
	}


	cout << endl;//输出
	cout << "新数列： " << endl;
	int xx = 0;
	for (int i = 0; i < 10; ++i) {
		node* temp = S.array[i].next;
		while (temp) {
			A[xx++]= temp->table;
			temp = temp->next;
		}
	}

	for (int i = 0; i < height; ++i) {
		cout << " " << A[i];
	}
	cout << endl;


	
	system("pause");
	return 0;
}