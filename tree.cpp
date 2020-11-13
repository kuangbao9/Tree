#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;

int front = 0;
int rear = 0;
typedef struct BiTreeNode
{
	ElemType data;
	struct BiTreeNode *lchild, *rchild;
}BiTreeNode, *pTree;

int i = 0;
void CreateTree(pTree *T, ElemType arr[])
{
	//char c;
	//scanf_s("%c", &c);
	if (arr[i] == ' ')
	{
		*T = NULL;
		i++;
	}
	else
	{
		*T = (BiTreeNode*)malloc(sizeof(BiTreeNode));
		(*T)->data = arr[i];
		i++;
		CreateTree(&(*T)->lchild, arr);
		CreateTree(&(*T)->rchild, arr);
	}
}

void PreOrder(pTree T)
{
	if (T != NULL)
	{
		printf("%c ", T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

void InOrder(pTree T)
{
	if (T != NULL)
	{
		InOrder(T->lchild);
		printf("%c ", T->data);
		InOrder(T->rchild);
	}
}

void PostOrder(pTree T)
{
	if (T != NULL)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		printf("%c ", T->data);
	}
}

void EnQueue(pTree *T, pTree node)
{
	T[rear++] = node;
}

BiTreeNode *DeQueue(pTree *T)
{
	return T[front++];
}

void LevelOrder(pTree T)
{
	BiTreeNode *p;
	pTree a[20];
	EnQueue(a, T);
	while (front < rear)
	{
		p = DeQueue(a);
		printf("%c ", p->data);
		if (p->lchild != NULL)
			EnQueue(a, p->lchild);
		if (p->rchild != NULL)
			EnQueue(a, p->rchild);
	}
}

int main()
{
	pTree T;
	ElemType arr[13] = { 'A', 'B', 'D', ' ', ' ', 'E', ' ', ' ', 'C', 'F', ' ', ' ',' ' };//PreOrder
	CreateTree(&T, arr);
	printf("PreOrder: ");
	PreOrder(T);
	printf("\nInOrder: ");
	InOrder(T);
	printf("\nPostOrder: ");
	PostOrder(T);
	printf("\nLevelOrder: ");
	LevelOrder(T);
	getchar();
	return 0;
}