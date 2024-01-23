
#include<iostream>
#include"head.h"
using namespace std;

void Heapify_sort(int* array, tree* T, int height) {

	int h = height-1;
	for (int i = 0; i < height; ++i,--h) {

		array[i] = T->tree[0].root;//�����������ֵ
		
		T->tree[0].root = T->tree[h].root;

		//T->tree[h].root = -1;//������Ӱ��
		if (h % 2 == 0) {
			T->tree[(h - 1) / 2].right_node = NULL;
		}
		else {
			T->tree[(h - 1) / 2].left_node = NULL;
		}//Ч����ͬ

		for (int j = h - 1; j >= 0; --j) { //���������

			int t = j;
			while (T->tree[t].left_node || T->tree[t].right_node) {

				//ѡ�����ҽڵ��нϴ�ֵ
				int temp = 2 * t + 1;
				if (T->tree[t].right_node) {
					if (T->tree[t].left_node->root < T->tree[t].right_node->root) {
						temp = 2 * t + 2;
					}
				}

				//����
				if (T->tree[temp].root > T->tree[t].root) {
					int temp_node = T->tree[t].root;
					T->tree[t].root = T->tree[temp].root;
					T->tree[temp].root = temp_node;
				}
				else {
					break;//δ���н�����������while
				}

				t = temp;
			}

		}
	}
}