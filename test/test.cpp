#include <iostream>
#include <fstream>

#define print(x) std::cout << x << std::endl

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
LinkList Union(LinkList A, LinkList B)
{
	LNode* la = A->next, *lb = B->next,*p,*q=A;
	while (la != NULL && lb != NULL)
	{
		if (la->data == lb->data)
		{
			q->next = la;
			q = la;
			p = lb;
			lb = lb->next;
			free(p);
			la = la->next;
		}
		else if (la->data > lb->data)
		{
			p = lb;
			lb = lb->next;
			free(p);
		}
		else if (la->data < lb->data)
		{
			p = la;
			la = la->next;
			free(p);
		}
	}
	while (la)
	{
		p = la;
		la = la->next;
		free(p);
	}
	while (lb)
	{
		p = lb;
		lb = lb->next;
		free(p);
	}
	q->next = NULL;
	free(B);
	return A;
}
bool Patten(LinkList A,LinkList B)
{
	LNode* la = A->next, * lb = B->next;
	while (la->data != lb->data && la != NULL) la = la->next;
	while (la != NULL && lb != NULL)
	{
		if (la->data!=lb->data)
		{
			return false;
		}
		la = la -> next;
		lb = lb -> next;
	}
	if (la == NULL && lb != NULL)return false;
	return true;
}

LNode* FindLoopStart(LNode* head)
{
	LNode* fast = head, * slow = head;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		//print(slow->data);
		fast = fast->next ->next;
		if (slow == fast) break;

	}
	if (fast == NULL || fast->next == NULL)
		return NULL;
	LNode* p1 = head, * p2 = slow;
	while (p1 != p2)
	{
		p1 = p1->next;
		p2 = p2->next;

	}
	return p1;
}
void InitLoopTest(LinkList& L)
{
	LNode* s,*a,*b;
	L = (LinkList)malloc(sizeof(LNode));
	a = L;
	for (int i = 0; i < 20; i++)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = i;
		a->next = s;
		a = s;
	}
	b = s;
	for (int i = 30; i < 50; i++)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = i;
		a->next = s;
		a = s;
	}
	a->next = b;
}
int main()
{
	LinkList L;
	InitLoopTest(L);
	LNode* q = L->next;
	//while (q!=NULL)
	//{
	//	std::cout << q->data << std::endl;
	//	q = q->next;
	//}
	LNode* p = FindLoopStart(L);
	std::cout << p->data << std::endl;
	std::cout << "BBBBBBBBB" << std::endl;
	/*LinkList B =DeleteSame(L);
	LNode* p = B->next;
	while (p != NULL)
	{
		std::cout << p->data << std::endl;
		p = p->next;
	}*/
	
}
