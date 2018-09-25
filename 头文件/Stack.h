#ifndef _STACK_H
#define _STACK_H
#define EMPTY -1
#define Error( Str )        fprintf( stderr, "%s\n", Str ), exit( 1 )

typedef struct StackRecord *Stack;
typedef int ElementType;
struct StackRecord
{
	int Capacity;
	int TopOfStack;
	ElementType *Array;
};



Stack CreateStack(int size);
void DestroyStack(Stack S);
_Bool IsEmpty(Stack S);
void push(ElementType X, Stack S);
ElementType top(Stack S);
ElementType pop(Stack S);



Stack CreateStack(int size)
{
	Stack S;
	S = malloc(sizeof(struct StackRecord));
	S->Array=malloc(sizeof(ElementType)*size);
	if (!S||!S->Array)
		Error("Out of space");
	S->Capacity = size;
	S->TopOfStack = EMPTY;
	return S;
}
void DestroyStack(Stack S)
{
	if (S)
	{
		free(S->Array);
		free(S);
		S = NULL;
	}
}
_Bool IsEmpty(Stack S)
{
	return !(S->TopOfStack+1);
}
void push(ElementType X, Stack S)
{
	if (S->Capacity!=S->TopOfStack+1)
		S->Array[++S->TopOfStack] = X;
	else
		Error("Stack is full");
}
ElementType top(Stack S)
{
	return S->Array[S->TopOfStack];
}
ElementType pop(Stack S)
{
	if (S->TopOfStack!=EMPTY)
		return S->Array[S->TopOfStack--];
	Error("Stack is empty");
}
#endif