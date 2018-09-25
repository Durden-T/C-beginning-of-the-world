#ifndef _BinomialHeap_H
#define _BinomialHeap_H

#define MaxTrees (14)   /* Stores 2^14 -1 items */
#define Capacity (16383) //2^14 -1
#define InfinitelySmall (30000L)
#define Error( Str )        fprintf( stderr, "%s\n", Str ), exit( 1 )

typedef long ElementType;
typedef struct BinNode *BinTree;
struct BinNode
{
	ElementType Element;
	BinTree    LeftChild;
	BinTree    NextSibling;
};
struct Collection
{
	int CurrentSize;
	BinTree TheTrees[MaxTrees];
};
typedef struct Collection *BinQueue;


BinQueue Initialize(void);
void Destroy(BinQueue H);
BinQueue MakeEmpty(BinQueue H);
BinTree CombineTrees(BinTree T1,BinTree T2);
BinQueue Merge(BinQueue H1,BinQueue H2);
BinQueue Insert(ElementType Item,BinQueue H);
ElementType FindMin(BinQueue H);
ElementType DeleteMin(BinQueue H);





BinQueue Initialize(void)
{
	BinQueue H;
	int i;
	H = malloc(sizeof(struct Collection));
	if(!H)
		Error("Out of space");
	H->CurrentSize = 0;
	for(i = 0; i < MaxTrees; i++)
		H->TheTrees[i] = NULL;
	return H;
}

static void DestroyTree(BinTree T)
{
	if(T)
	{
		DestroyTree(T->LeftChild);
		DestroyTree(T->NextSibling);
		free(T);
	}
}

void Destroy(BinQueue H)
{
	for(int i = 0; i < H->CurrentSize; i++)
		DestroyTree(H->TheTrees[i]);
}

BinQueue MakeEmpty(BinQueue H)
{
	Destroy(H);
	for(int i = 0; i < H->CurrentSize; i++)
		H->TheTrees[i] = NULL;
	H->CurrentSize = 0;
	return H;
}

/* Return the result of merging equal-sized T1 and T2 */
BinTree CombineTrees(BinTree T1,BinTree T2)
{
	if(T1->Element > T2->Element)
		return CombineTrees(T2,T1);
	T2->NextSibling = T1->LeftChild;
	T1->LeftChild = T2;
	return T1;
}

/* Merge two binomial queues */
/* Not optimized for early termination */
/* H1 contains merged result */

BinQueue Merge(BinQueue H1,BinQueue H2)
{
	BinTree T1,T2;
	BinTree Carry = NULL;
	if(H1->CurrentSize + H2->CurrentSize > Capacity)
		Error("Merge would exceed capacity.");
	H1->CurrentSize += H2->CurrentSize;
	for(int i = 0,j = 1; j <= H1->CurrentSize; i++,j *= 2)
	{
		T1 = H1->TheTrees[i];
		T2 = H2->TheTrees[i];
		switch(!!T1 + 2 * !!T2 + 4 * !!Carry)
		{
			case 0: /* No trees */
			case 1: /* Only H1 */
				break;
			case 2: /* Only H2 */
				H1->TheTrees[i] = T2;
				H2->TheTrees[i] = NULL;
				break;
			case 4: /* Only Carry */
				H1->TheTrees[i] = Carry;
				Carry = NULL;
				break;
			case 3: /* H1 and H2 */
				Carry = CombineTrees(T1,T2);
				H1->TheTrees[i] = H2->TheTrees[i] = NULL;
				break;
			case 5: /* H1 and Carry */
				Carry = CombineTrees(T1,Carry);
				H1->TheTrees[i] = NULL;
				break;
			case 6: /* H2 and Carry */
				Carry = CombineTrees(T2,Carry);
				H2->TheTrees[i] = NULL;
				break;
			case 7: /* All three */
				H1->TheTrees[i] = Carry;
				Carry = CombineTrees(T1,T2);
				H2->TheTrees[i] = NULL;
				break;
		}
	}
	return H1;
}

/* Not optimized(最佳化的) for O(1) amortized (平摊) performance */

BinQueue Insert(ElementType Item,BinQueue H)
{
	BinTree NewNode;
	BinQueue OneItem;
	NewNode = malloc(sizeof(struct BinNode));
	if(!NewNode)
		Error("Out of space.");
	NewNode->LeftChild = NewNode->NextSibling = NULL;
	NewNode->Element = Item;
	OneItem = Initialize();
	OneItem->CurrentSize = 1;
	OneItem->TheTrees[0] = NewNode;
	return Merge(H,OneItem);
}

ElementType FindMin(BinQueue H)
{
	ElementType MinItem;
	if(!H->CurrentSize)
		Error("Empty binomial queue");
	MinItem = InfinitelySmall;
	for(int i = 0; i < H->CurrentSize; i++)
		if(H->TheTrees[i] &&H->TheTrees[i]->Element < MinItem)
			MinItem = H->TheTrees[i]->Element;
	return MinItem;
}

ElementType DeleteMin(BinQueue H)
{
	int MinTree;   /* The tree with the minimum item */
	BinQueue DeletedQueue;
	BinTree Tmp,OldRoot;
	ElementType MinItem;
	if(!H->CurrentSize)
		Error("Empty binomial queue");
	MinItem = InfinitelySmall;
	for(int i = 0; i < H->CurrentSize; i++)
		if(H->TheTrees[i] && H->TheTrees[i]->Element < MinItem)
		{
			/* Update minimum */
			MinItem = H->TheTrees[i]->Element;
			MinTree = i;
		}
	Tmp = H->TheTrees[MinTree];
	OldRoot = Tmp;
	Tmp = Tmp->LeftChild;
	free(OldRoot);
	DeletedQueue = Initialize();
	DeletedQueue->CurrentSize = (1 << MinTree) - 1;//2^MinTree -1
	for(int j = MinTree - 1; j >= 0; j--)
	{
		DeletedQueue->TheTrees[j] = Tmp;
		Tmp = Tmp->NextSibling;
		DeletedQueue->TheTrees[j]->NextSibling = NULL;
	}
	H->TheTrees[MinTree] = NULL;
	H->CurrentSize -= DeletedQueue->CurrentSize + 1;
	Merge(H,DeletedQueue);
	return MinItem;
}

#endif

