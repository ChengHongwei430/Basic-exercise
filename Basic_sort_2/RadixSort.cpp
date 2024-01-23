

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
	cout << "ԭ���У� " << endl;
	for (int i = 0; i < height; ++i) {
		cout << " " << A[i];
	}
	cout << endl;

	node_array S;//����β������
	for (int i = 0; i < 10; ++i) {
		S.array[i].table = i;
		S.array[i].next = NULL;
	}


	node* k = new node[height];//���������ڵ�
	for (int i = 0; i < height; ++i) {
		k[i].table = A[i];
		k[i].next = NULL;
	}

	for (int i = 0; i < height; ++i) {//��λ
		int temp = A[i] % 10;
		node* tempn = S.array[temp].next;
		S.array[temp].next = &k[i];
		k[i].next = tempn;
	}
	cout << endl;
	cout << "��β�����У� " << endl;
	for (int i = 0; i < 10; ++i) {
		node* temp = S.array[i].next;
		while (temp) {
			cout << " " << temp->table;
			temp = temp->next;
		}
		cout << endl;
	}


	cout << endl;//����
	int x = 0;
	for (int i = 0; i < 10; ++i) {
		node* temp = S.array[i].next;
		while (temp) {
			A[x++]=temp->table;//�����++���׺���
			temp = temp->next;
		}
	}
	for (int i = 0; i < height; ++i) {
		cout << " " << A[i];
	}
	cout << endl;




	for (int i = 0; i < 10; ++i) {//��ԭ����
		S.array[i].next = NULL;
	}
	for (int i = 0; i < height; ++i) {
		k[i].table = A[i];
		k[i].next = NULL;
	}

	for (int i = height-1; i >= 0; --i) {//��λ,�Ӻ���ǰ����
		int temp = A[i]/10;
		node* tempn = S.array[temp].next;
		S.array[temp].next = &k[i];
		k[i].next = tempn;
	}

	cout << endl;
	cout << "��ʮλ���У� " << endl;
	for (int i = 0; i < 10; ++i) {
		node* temp = S.array[i].next;
		while (temp) {
			cout << " " << temp->table;
			temp = temp->next;
		}
		cout << endl;
	}


	cout << endl;//���
	cout << "�����У� " << endl;
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