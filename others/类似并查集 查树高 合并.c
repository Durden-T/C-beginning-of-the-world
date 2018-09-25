#include <stdio.h>
#include<stdlib.h>
#define Error( Str )        fprintf( stderr, "%s\n", Str ), exit( 1 )
typedef int* DisjSet;
typedef int ElementType;

DisjSet Initialize(int size);
void SetUnion(DisjSet S,int Root1,int Root2);
int *height;//


int main(void)
{
	int n,a,key;
	scanf("%d",&n);
	DisjSet S=Initialize(n);
	for(int i=0;i<n&&scanf("%d",&a);i++)
		if(a==-1)
			key=i;
		else
			SetUnion(S,i,a);
	printf("%d",height[key]);
	free(S);
	free(height);
	return 0;
}

DisjSet Initialize(int size)
{
	DisjSet S=malloc(sizeof(ElementType)*size);
	height=malloc(sizeof(int)*size);
	if(!S||!height)
		Error("Out of space.");
	for(int i=0;i<size;i++)
	{
		S[i]=-1;
		height[i]=1;
	}
	return S;
}


void SetUnion(DisjSet S,int a,int b)
{
	S[a]=b;
	int tmp=a,next=S[a];
	while(next>=0&&height[next]<=height[tmp])
	{
		height[next]=height[tmp]+1;
		tmp=next;
		next=S[tmp];
	}
}
