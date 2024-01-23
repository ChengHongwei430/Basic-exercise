

#include<iostream>
#include"head.h"
using namespace std;

void Creat_max_heapify(int* array, tree* T, int height) {

	//建立初始树结构
	for (int i = 0; i <  height; ++i) {
		T->tree[i].root = array[i];
	}

	for (int i = 0; i < height; ++i) {
		if (2*i + 1 < height) {
			T->tree[i].left_node = &T->tree[2 * i + 1];
		}
		else {
			T->tree[i].left_node = NULL;
		}
		if (2 * i + 2 < height) {
			T->tree[i].right_node = &T->tree[2 * i + 2];
		}
		else {
			T->tree[i].right_node = NULL;
		}
	}

	cout << "建堆前树结构展示：" << endl;
	for (int i = 0; i < height; ++i) {
		if (T->tree[i].left_node && T->tree[i].right_node) cout << T->tree[i].root << "\t" << T->tree[i].left_node->root << "\t" << T->tree[i].right_node->root << endl;
		if (!T->tree[i].left_node) cout << T->tree[i].root << "\t" << endl;
		if (T->tree[i].left_node && !T->tree[i].right_node) cout << T->tree[i].root << "\t" << T->tree[i].left_node->root << endl;
	}

	for (int i = height-1; i >= 0; --i) {

		int t = i;
		while(T->tree[t].left_node|| T->tree[t].right_node){

			//选出左右节点中较大值
			int temp = 2 * t + 1;
			if (T->tree[t].right_node) {
				if (T->tree[t].left_node->root < T->tree[t].right_node->root) {
					temp = 2 * t + 2;
				} 
			}

			//交换
			if (T->tree[temp].root > T->tree[t].root) {
				int temp_node= T->tree[t].root;
				T->tree[t].root = T->tree[temp].root;
				T->tree[temp].root = temp_node;
			}
			else {
				break;//未进行交换，则跳出while
			}

			t = temp;		
		}
		
	}

	cout << "建堆后树结构展示：" << endl;
	for (int i = 0; i < height; ++i) {
		if (T->tree[i].left_node && T->tree[i].right_node) cout<< T->tree[i].root << "\t" << T->tree[i] .left_node->root << "\t" << T->tree[i].right_node->root<<endl;
		if (!T->tree[i].left_node) cout << T->tree[i].root << "\t" << endl;
		if (T->tree[i].left_node && !T->tree[i].right_node) cout << T->tree[i].root << "\t" << T->tree[i].left_node->root << endl;
	}

}