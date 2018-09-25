//increased max heap
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Error( Str )        fprintf( stderr, "%s\n", Str ), exit( 1 )
#define RANDMAX 10000
typedef int ElementType;
int isSorted(ElementType *a,int n)
{
	for(int i=1; i<=n-1; i++)
		if(a[i]>a[i+1])
			return 0;
	return 1;
}
void getRandArray(int *a,int n)//只能int
{
	srand(time(NULL));
	for(int i=1; i<=n; i++)
		a[i]=rand()%RANDMAX;
}

void printArray(ElementType *a,int n)
{
	for(int i=1; i<=n; i++)
		printf("%d\t",a[i]);
	putchar('\n');
}

#define SWAP(x,y) {ElementType tmp=(x);(x)=(y);(y)=tmp;}
inline void PercolateDown(int position,ElementType *values,int n);
void BuildHeap(ElementType *values,int n);
ElementType DeleteMax(ElementType *values,int n);
void HeapSort(ElementType *values,int n);

int main(void)
{
	int n;
	while(scanf("%d",&n)&&n!=-1)
	{
		ElementType *array=(ElementType *)malloc((n+1)*sizeof(ElementType));
		getRandArray(array,n);
		printArray(array,n);
		HeapSort(array,n);//这里
		printArray(array,n);
		if(isSorted(array,n))
			printf("Sorted\n");
		else
			printf("Not sorted\n");
		free(array);
	}
	return 0;
}

inline void PercolateDown(int position,ElementType *values,int n)
{
	int i,Child,tmp=values[position];
	for(i=position;i*2<=n;i=Child)
	{
		Child=i*2;
		if(Child!=n&&values[Child+1]>values[Child])
			Child++;
		if(values[i]<values[Child])
			SWAP(values[i],values[Child])
		else
			break;
	}
	values[i]=tmp;
}

void BuildHeap(ElementType *values,int n)
{
	for(int i=n/2;i; i--)
		PercolateDown(i,values,n);
}

ElementType DeleteMax(ElementType *values,int n)
{
	ElementType max=values[1];
	values[1]=values[n--];
	PercolateDown(1,values,n);
	return max;
}

void HeapSort(ElementType *values,int n)
{
	BuildHeap(values,n);
	for(int i=n;i;i--)
		values[i]=DeleteMax(values,n--);
}
