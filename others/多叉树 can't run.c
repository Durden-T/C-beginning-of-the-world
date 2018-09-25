#include <stdio.h>
#include<stdlib.h>
#define Error( Str )        fprintf( stderr, "%s\n", Str ), exit( 1 )
typedef struct TreeRecord *Tree;
typedef int ElementType;
struct TreeRecord
{
	ElementType Index;
	Tree FChild;
	Tree NSibling;
	Tree Father;
	int Height;
};

Tree CreateTree(Tree L,int index);
Tree Find(Tree L,ElementType index);

int main(void)
{
	int n,a;
	Tree T;
	scanf("%d",&n);
	for(int i=0;i<n&&scanf("%d",&a);i++)
		if(a==-1)
			T=CreateTree(NULL,i);
		else
			CreateTree(Find(T,a),i);
	printf("%d",T->Height);
	return 0;
}

Tree CreateTree(Tree L,int index)
{
	Tree T=malloc(sizeof(struct TreeRecord));
	T->FChild=T->NSibling=NULL;
	T->Index=index;
	T->Height=1;
	if(L)
	{
		L->Height++;
		Tree Tmp=L->Father;
		while(Tmp->Father)
		{
			Tmp->Height++;
			Tmp=Tmp->Father;
		}
		if(L->FChild)
		{
			L=L->FChild;
			while(L->NSibling)
				L=L->NSibling;
			L->NSibling=T;
			return T;
		}
		L->FChild=T;
	}
	return T;
}

Tree Find(Tree L,ElementType index)
{
	if(L)
	{
		if(L->Index==index)
			return L;
		Tree T=NULL;
		T=Find(L->FChild,index);
		if(T)
			return T;
		return Find(L->NSibling,index);
	}
	return NULL;
}