#include <iostream>
#include <fstream>



#define Initsize 100

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode,*LinkList;
void InitLinkList(LinkList &L)
{
	LNode *s;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	LNode* q = L;
	for (int i = 0; i < 20; i++)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = i;
		q->next = s;
		q = s;
	}
	q->next = NULL;
}
void InitLinkListScanf(LinkList& L)
{
	int x;
	LNode* s;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	LNode* q = L;
	std::cin >> x;
	while (x != 999)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		q->next = s;
		q = s;
		std::cin >> x;
	}
	q->next = NULL;
}
LinkList DisCreat_2(LinkList& A)
{
	LinkList B = (LinkList)malloc(sizeof(LNode));
	B->next = NULL;
	LNode* p = A->next, * q;
	LNode* ra = A;
	while (p != NULL)
	{
		//ra->next = p; ra = p;
		p = p->next;
		if (p != NULL)
		{
			q = p->next;
			p->next = B->next;
			B->next = p;
			p = q;
		}
	}
	ra->next = NULL;
	return B;
}
LinkList DeleteSame(LinkList& L)
{
	LNode* p = L->next;
	LNode* q;
		
	
	while (p->next != NULL)
	{
		q = p->next;
		if (p->data == q->data)
		{
			p->next = q->next;
			free(q);
		}
		else {
			p = p->next;//忘记
		}
	}
	return L;
}
LinkList FindSame(LinkList A,LinkList B)
{
	LNode* s;
	LinkList C = (LinkList)malloc(sizeof(LNode));
	LNode* q = C;
	C->next = NULL;

	LNode* a = A->next; LNode* b = B->next;
	while (a != NULL || b != NULL)
	{
		if (a->data == b->data)
		{
			s = (LNode*)malloc(sizeof(LNode));
			s->data = a->data;
			q->next = s;
			q = s;
			a = a->next;
			b = b->next;
		}else if(a->data > b->data)
		{
			b = b->next;
		}
		else if (a->data < b->data)
		{
			a = a->next;
		}
	}
	return C;
}
int Union(LinkList A, LinkList B)
{

}
int main()
{
	LinkList L;
	InitLinkListScanf(L);
	LNode* q = L->next;
	while (q!=NULL)
	{
		std::cout << q->data << std::endl;
		q = q->next;
	}
	std::cout << "BBBBBBBBB" << std::endl;
	LinkList B =DeleteSame(L);
	LNode* p = B->next;
	while (p != NULL)
	{
		std::cout << p->data << std::endl;
		p = p->next;
	}
	
}
