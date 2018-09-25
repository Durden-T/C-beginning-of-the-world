#include <stdio.h>
#include<stdlib.h>
#define EMPTY -1
#define Error( Str )        fprintf( stderr, "%s\n", Str ), exit( 1 )
#define SIZE 100000
#define ISOPEN(a) (a=='['||a=='{'||a=='(')
typedef struct StackRecord *Stack;
typedef char ElementType;
struct StackRecord
{
	int Capacity;
	int TopOfStack;
	ElementType *Array;
};



Stack CreateStack(int size);
void DestroyStack(Stack S);
_Bool IsEmpty(Stack S);
void push(ElementType X,Stack S);
ElementType top(Stack S);
ElementType pop(Stack S);


int main(void)
{
	Stack S=CreateStack(SIZE);
	char a;
	int index[SIZE];
	int count=0,opencount=0;
	while((a=getchar())!='\n')
	{
		count++;
		if(ISOPEN(a))
		{
			push(a,S);
			index[opencount++]=count;
		}
		else if(a==')')
		{
			if(!IsEmpty(S)&&top(S)=='(')
			{
				pop(S);
				opencount--;
			}
			else
			{
				printf("%d",count);
				goto End;
			}
		}
		else if(a==']')
		{
			if(!IsEmpty(S)&&top(S)=='[')
			{
				pop(S);
				opencount--;
			}
			else
			{
				printf("%d",count);
				goto End;
			}
		}
		else if(a=='}')
		{
			if(!IsEmpty(S)&&top(S)=='{')
			{
				pop(S);
				opencount--;
			}
			else
			{
				printf("%d",count);
				goto End;
			}
		}
	}
	if(IsEmpty(S))
		printf("Success");
	else
		printf("%d",index[opencount-1]);
End: DestroyStack(S);
	return 0;
}


Stack CreateStack(int size)
{
	Stack S;
	S=malloc(sizeof(struct StackRecord));
	S->Array=malloc(sizeof(ElementType)*size);
	if(!S||!S->Array)
		Error("Out of space");
	S->Capacity=size;
	S->TopOfStack=EMPTY;
	return S;
}
void DestroyStack(Stack S)
{
	if(S)
	{
		free(S->Array);
		free(S);
		S=NULL;
	}
}
_Bool IsEmpty(Stack S)
{
	return !(S->TopOfStack+1);
}
void push(ElementType X,Stack S)
{
	if(S->Capacity!=S->TopOfStack+1)
		S->Array[++S->TopOfStack]=X;
	else
		Error("Stack is full");
}
ElementType top(Stack S)
{
	return S->Array[S->TopOfStack];
}
ElementType pop(Stack S)
{
	if(S->TopOfStack!=EMPTY)
		return S->Array[S->TopOfStack--];
	Error("Stack is empty");
}