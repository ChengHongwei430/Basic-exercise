
#pragma once
#include<iostream>
using namespace std;
#define MAX 100

struct tree_node
{
	int root;
	struct tree_node* left_node;
	struct tree_node* right_node;
};

struct tree
{
	struct tree_node tree[MAX];
};

void Creat_max_heapify(int* array, tree* T, int height);
void Heapify_sort(int* array, tree* T, int height);
