//m jobs n threads
/*Input Format.The first line of the input contains integers 𝑛 and 𝑚.
The second line contains 𝑚 integers 𝑡𝑖 — the times in seconds it takes any thread to process 𝑖-th job.
The times are given in the same order as they are in the list from which threads take jobs.
Threads are indexed starting from 0.
Constraints. 1 ≤ 𝑛 ≤ 105
; 1 ≤ 𝑚 ≤ 105
; 0 ≤ 𝑡𝑖 ≤ 109
.
Output Format.Output exactly 𝑚 lines.𝑖-th line(0-based index is used) should contain two space separated
integers — the 0-based index of the thread which will process the 𝑖-th job and the time in
seconds when it will start processing that job.*/
#include<stdio.h>
#include<stdlib.h>
#define Error( Str )        fprintf( stderr, "%s\n", Str ), exit( 1 )
#define SWAP(x,y) {ElementType tmp=(x);(x)=(y);(y)=tmp;}
typedef long long ElementType;
struct HeapStruct
{
	int Capacity;
	int Size;
	ElementType *Elements;
	ElementType *Indexs;
};
typedef struct HeapStruct *BinHeap;

BinHeap Initialize(int n);
inline void PercolateUp(int position,BinHeap H);
inline void PercolateDown(int position,BinHeap H);
inline int FindIndex(ElementType X,BinHeap H);
void Insert(ElementType X,BinHeap H);
ElementType DeleteMin(BinHeap H);
BinHeap BuildHeap(int n);


int c=0,cc=0;
int main(void)
{
	int m,n,i;
	long long a,t,k;
	scanf("%d %d",&n,&m);
	BinHeap H=BuildHeap(n);
	t=H->Elements[1];
	while(H->Size&&c<m)
	{
		do
		{
			k=DeleteMin(H);
			i=FindIndex(0,H);
			printf("%d %lld\n",i,t);
			c++;
		}
		while(H->Size&&k==H->Elements[1]&&c<m);
		while(H->Size!=n&&cc<m)
		{
			scanf("%lld",&a);
			Insert(a+t,H);
			cc++;
		}
		t=H->Elements[1];
	}
	return 0;
}


BinHeap Initialize(int n)
{
	BinHeap H;
	H=malloc(sizeof(struct HeapStruct));
	if(!H)
		Error("Out of space");
	H->Elements=malloc(sizeof(ElementType)*(n+1));
	H->Indexs=malloc(sizeof(ElementType)*n);
	if(!H->Elements||!H->Indexs)
		Error("Out of space");
	H->Capacity=n;
	H->Size=0;
	return H;
}

inline void PercolateUp(int position,BinHeap H)
{
	int i;
	long long tmp=H->Elements[position];
	for(i=position;i/2&&H->Elements[i]<H->Elements[i/2];i/=2)
		SWAP(H->Elements[i],H->Elements[i/2])
		H->Elements[i]=tmp;
}

inline void PercolateDown(int position,BinHeap H)
{
	int i,Child;
	long long tmp=H->Elements[position];
	for(i=position;i*2<=H->Size;i=Child)
	{
		Child=i*2;
		if(Child!=H->Size && H->Elements[Child+1]<H->Elements[Child])
			Child++;
		if(H->Elements[i]>H->Elements[Child])
			SWAP(H->Elements[i],H->Elements[Child])
		else
			break;
	}
	H->Elements[i]=tmp;
}

inline int FindIndex(ElementType X,BinHeap H)
{
	int i;
	for(i=0;H->Indexs[i]!=X;i++);
	return i;
}

void Insert(ElementType X,BinHeap H)
{
	int i;
	if(H->Size==H->Capacity)
		Error("Priority queue is full.");
	i=FindIndex(0,H);
	H->Indexs[i]=H->Elements[++H->Size]=X;
	PercolateUp(H->Size,H);
}

ElementType DeleteMin(BinHeap H)
{
	int i;
	ElementType min=H->Elements[1];
	i=FindIndex(min,H);
	H->Indexs[i]=0;
	H->Elements[1]=H->Elements[H->Size--];
	PercolateDown(1,H);
	return min;
}

BinHeap BuildHeap(int n)
{
	long long t;
	BinHeap H=Initialize(n);
	H->Size=n;
	for(int i=1; i<=n; i++)
	{
		scanf("%lld",&t);
		c++;
		cc++;
		H->Elements[i]=H->Indexs[i-1]=t;
		printf("%d 0\n",i-1);
	}
	for(int i=n/2;i; i--)
		PercolateDown(i,H);
	return H;
}