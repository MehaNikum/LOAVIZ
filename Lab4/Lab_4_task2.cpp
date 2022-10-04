// Lab_4_task1.cpp: определ€ет точку входа дл€ консольного приложени€.
//
#include "StdAfx.h"
#include <stdlib.h>
#include "stdafx.h"
#include "malloc.h"
#include "locale.h"
#include "iostream"
using namespace std;
struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};
struct Node *root;
int amount = 0;
struct Node *CreateTree(struct Node *root, struct Node *r, int data)
{
	if (r == NULL)
	{
		r = (struct Node *)malloc(sizeof(struct Node));
		if (r == NULL)
		{
			printf("ќшибка выделени€ пам€ти");
			exit(0);
		}
		
		r->left = NULL;
		r->right = NULL;
		r->data = data;
		if (root == NULL) return r;

		if (data > root->data)	root->left = r;
		else root->right = r;	
		return r;
	}

	if (data > r->data)
		CreateTree(r, r->left, data);
	else
		CreateTree(r, r->right, data);

	return root;
}

void print_tree(struct Node *r, int l)
{
	
	if (r == NULL)
	{
		return;
	}
	
	print_tree(r->right, l + 1);
	for(int i = 0; i < l; i++)
	{
		printf(" ");
	}

	printf("%d\n", r->data);
	print_tree(r->left,  l+1);
}

int findint(Node *tree, int find)
{
	
	if (tree != NULL){  
    
	  
		if (find == tree->data){
       amount++;
		}
		
	
	 findint(tree->left, find);
	 findint(tree->right,find);      
   return 0;
	}
}
int replay(Node *tree, int D)
{

	if (tree != NULL){ 
		if (D == tree->data)
			tree->data = rand()%100;
			
		replay(tree->left, D);
	 replay(tree->right,D);    

	}
	return 0;
}
int main()
{
	struct Node* root;
	setlocale(LC_ALL, "");
	int D, start = 1;
	int k = 1;
	
	root = NULL;
	
	printf("-1 - окончание построени€ дерева\n");
	printf("¬ведите число: ");
	while (start)
	{
		
		scanf_s("%d", &D);
		//replay(root,D);
		if (D == -1)
		{
			printf("ѕостроение дерева окончено\n\n");
			start = 0;
		}
		else{
			root = CreateTree(root, root, D);
		}
	}

	print_tree(root,0);
	while (k)
	{
	cout << "\n1 - поиск элемента по дереву\n" << "0 - выход" << endl;
    cin >> k; 
	if (k == 1)
	{
	int find;
    cout << "¬ведите элемент поиска: \n";
	cin >> find;
    findint(root, find);
	
	if (amount != 0){
		cout << "Ёлемент найден! \n";
	    cout << "¬ходит: " << amount << " раз(а)\n";
	}
	else
		cout << "Ёлемент не найден! \n";
	}
	amount = 0;
	if (k == 0) 
    return 0; 
	}
	system("pause");
	return 0;
}




