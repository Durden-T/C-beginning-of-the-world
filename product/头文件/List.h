#ifndef _LIST_H
#define _LIST_H
#define Error( Str )        fprintf( stderr, "%s\n", Str ), exit( 1 )
typedef struct ListRecord *List;
typedef int ElementType;//printf %d!!
struct ListRecord
{
	ElementType Value;
	List Next;
};



List CreateList(List L);
List CreateHList(void);
void DeleteList(List L);
List FindPrevious(int x, List L);
List Delete(int x, List L);
void ShowList(List L);



List CreateList(List L)
{
	List T = malloc(sizeof(struct ListRecord));
	if (!T)
		Error("Out of space.");
	T->Next = NULL;
	if(L)
		L->Next = T;
	return T;
}

List CreateHList(void)
{
	List Header = malloc(sizeof(struct ListRecord));
	if (!Header)
		Error("Out of space.");
	CreateList(Header);
	return Header;
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

List FindPrevious(int x, List L)
{
	if (L->Value==x)
		Error("It's the first.");
	while (L->Next&&L->Next->Value!=x)
		L = L->Next;
	if (!L->Next)
		return NULL;
	return L;
}

List Delete(int x, List L)
{
	List Previous;
	if (Previous = FindPrevious(x, L))
	{
		List Temp = Previous->Next->Next;
		free(Previous->Next);
		Previous->Next = Temp;
		return Previous;
	}
	else
		Error("Can't find previous.");
}

void ShowList(List L)
{
	while (L)
	{
		printf("%d\t", L->Value);
		L = L->Next;
	}
}
#endif