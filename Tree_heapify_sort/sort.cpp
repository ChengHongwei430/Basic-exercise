
#include<iostream>
#include"head.h"
using namespace std;

void Heapify_sort(int* array, tree* T, int height) {

	int h = height-1;
	for (int i = 0; i < height; ++i,--h) {

		array[i] = T->tree[0].root;//输出大根堆最大值
		
		T->tree[0].root = T->tree[h].root;

		//T->tree[h].root = -1;//加上有影响
		if (h % 2 == 0) {
			T->tree[(h - 1) / 2].right_node = NULL;
		}
		else {
			T->tree[(h - 1) / 2].left_node = NULL;
		}//效果相同

		for (int j = h - 1; j >= 0; --j) { //调整大根堆

			int t = j;
			while (T->tree[t].left_node || T->tree[t].right_node) {

				//选出左右节点中较大值
				int temp = 2 * t + 1;
				if (T->tree[t].right_node) {
					if (T->tree[t].left_node->root < T->tree[t].right_node->root) {
						temp = 2 * t + 2;
					}
				}

				//交换
				if (T->tree[temp].root > T->tree[t].root) {
					int temp_node = T->tree[t].root;
					T->tree[t].root = T->tree[temp].root;
					T->tree[temp].root = temp_node;
				}
				else {
					break;//未进行交换，则跳出while
				}

				t = temp;
			}

		}
	}
}