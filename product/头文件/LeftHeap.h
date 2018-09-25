#ifndef _LeftHeap_H
#define _LeftHeap_H
//merge不大懂
#define Insert( X, H ) ( H = Insert1( ( X ), H ) )//可能会改变头节点
#define Error( Str )        fprintf( stderr, "%s\n", Str ), exit( 1 )
typedef int ElementType;
typedef struct LeftHeapNode *LeftHeap;
struct 
{
	ElementType   Element;
	LeftHeap      Left;
	LeftHeap      Right;
	int           Npl;
};
/* Minimal set of priority queue operations */
/* Note that nodes will be shared among several */
/* leftist heaps after a merge; the user must */
/* make sure to not use the old leftist heaps */

;
LeftHeap Merge(LeftHeap H1,LeftHeap H2);
/* DeleteMin macro is left as an exercise */
LeftHeap Insert1(ElementType X,LeftHeap H);
LeftHeap DeleteMin1(LeftHeap H);
static LeftHeap Merge1(LeftHeap H1,LeftHeap H2);



LeftHeap Merge(LeftHeap H1,LeftHeap H2)
{
	if(H1 == NULL)
		return H2;
	if(H2 == NULL)
		return H1;
	if(H1->Element < H2->Element)
		return Merge1(H1,H2);
	else
		return Merge1(H2,H1);
}

void SwapChildren(LeftHeap H)
{
	LeftHeap Tmp;

	Tmp = H->Left;
	H->Left = H->Right;
	H->Right = Tmp;
}

static LeftHeap Merge1(LeftHeap H1,LeftHeap H2)
{//H1->Element<H2->Element
	if(H1->Left == NULL)  // Single node
		H1->Left = H2;    /* H1->Right is already NULL,
					         H1->Npl is already 0 */
	else
	{
		H1->Right = Merge(H1->Right,H2);
		if(H1->Left->Npl < H1->Right->Npl)
			SwapChildren(H1);
		H1->Npl = H1->Right->Npl + 1;
	}
	return H1;
}

LeftHeap Insert1(ElementType X,LeftHeap H)
{
	LeftHeap SingleNode;
	SingleNode = malloc(sizeof(struct LeftHeapNode));
	if(!SingleNode)
		Error("Out of space");
	SingleNode->Element = X; 
	SingleNode->Npl = 0;
	SingleNode->Left = SingleNode->Right = NULL;
	H = Merge(SingleNode,H);
	}
	return H;
}

/* DeleteMin1 returns the new tree; */
/* To get the minimum, use FindMin */
/* This is for convenience */
LeftHeap DeleteMin1(LeftHeap H)
{
	LeftHeap LeftHeap,RightHeap;
	if(IsEmpty(H))
	{
		Error("Priority queue is empty");
		return H;
	}
	LeftHeap = H->Left;
	RightHeap = H->Right;
	free(H);
	return Merge(LeftHeap,RightHeap);
}
#endif