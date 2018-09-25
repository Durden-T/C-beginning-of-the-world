#include<stdio.h>
#include<stdlib.h>
typedef struct ListRecord *List;
struct ListRecord
{
	int Value;
	List Next;
};

#ifndef _LIST_H
void error(char *a);
List CreateList(List L);
List CreateHList(void);
List CreateNHList(void);
void DeleteList(List L);

void error(char *a)
{
	puts(a);
	exit(EXIT_FAILURE);
}

List CreateList(List L)
{
	List T = malloc(sizeof(struct ListRecord));
	if (!T)
		error("Out of space.\n");
	T->Next = NULL;
	L->Next = T;
	return T;
}

List CreateHList(void)
{
	List Header = malloc(sizeof(struct ListRecord));
	if (!Header)
		error("Out of space.\n");
	CreateList(Header);
	return Header;
}

List CreateNHList(void)
{
	List T = malloc(sizeof(struct ListRecord));
	if (!T)
		error("Out of space.\n");
	T->Next = NULL;
	return T;
}

void DeleteList(List L)
{
	List T;
	while (L)
	{
		T = L->Next;
		free(L);
		L = T;
	}
}

#endif
void printlots(List L, List P)
{
	int index;
	List Temp;
	while (P)
	{
		index =1;
		Temp = L;
		while (index++<P->Value)
			Temp = Temp->Next;
		printf("%d ", Temp->Value);
		P = P->Next;
	}
}

int main(void)
{
	List L = CreateNHList();
	List P = CreateNHList();
	List Temp = L;
	for (int i = 1; i<=4; i++)
	{
		Temp->Value = i;
		Temp = CreateList(Temp);
	}
	free(Temp);
	Temp = NULL;
	CreateList(P);
	P->Value = 2;
	P->Next->Value = 1;
	P->Next->Next = NULL;
	printlots(L, P);
	return 0;
}