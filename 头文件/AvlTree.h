#ifndef _AVLTREE_H
#define _AVLTREE_H

#define Error( Str )        fprintf( stderr, "%s\n", Str ), exit( 1 )
#define MAX(x,y) (x)>(y)?(x):(y)
typedef int ElementType;
typedef struct AvlRecord *AvlTree;
struct AvlRecord
{
	ElementType Element;
	AvlTree     Left;
	AvlTree     Right;
	int         Height;
};



AvlTree MakeEmpty(AvlTree T);
AvlTree Find(ElementType X, AvlTree T);
AvlTree FindMin(AvlTree T);
AvlTree FindMax(AvlTree T);
static int Height(AvlTree P);
static AvlTree SingleRotateWithLeft(AvlTree K2);
static AvlTree SingleRotateWithRight(AvlTree K1);
static AvlTree DoubleRotateWithLeft(AvlTree K3);
static AvlTree DoubleRotateWithRight(AvlTree K1);
AvlTree Insert(ElementType X, AvlTree T);





AvlTree MakeEmpty(AvlTree T)
{
	if (T)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

AvlTree Find(ElementType X, AvlTree T)
{
	if (!T)
		return NULL;
	if (X < T->Element)
		return Find(X, T->Left);
	else
		if (X > T->Element)
			return Find(X, T->Right);
		else
			return T;
}

AvlTree FindMin(AvlTree T)
{
	if (T)
		while (T->Left)
			T = T->Left;
	return T;
}

AvlTree FindMax(AvlTree T)
{
	if (T)
		while (T->Right)
			T = T->Right;
	return T;
}

static int Height(AvlTree P)
{
	if (!P)
		return -1;
	else
		return P->Height;
}

/* This function can be called only if K2 has a left child */
/* Perform a rotate between a node (K2) and its left child */
/* Update heights, then return new root */

static AvlTree SingleRotateWithLeft(AvlTree K2)
{
	AvlTree K1;

	K1 = K2->Left;
	K2->Left = K1->Right;
	K1->Right = K2;

	K2->Height = MAX(Height(K2->Left), Height(K2->Right)) + 1;
	K1->Height = MAX(Height(K1->Left), K2->Height) + 1;

	return K1;  /* New root */
}
/* This function can be called only if K1 has a right child */
/* Perform a rotate between a node (K1) and its right child */
/* Update heights, then return new root */

static AvlTree SingleRotateWithRight(AvlTree K1)
{
	AvlTree K2;

	K2 = K1->Right;
	K1->Right = K2->Left;
	K2->Left = K1;

	K1->Height = MAX(Height(K1->Left), Height(K1->Right)) + 1;
	K2->Height = MAX(Height(K2->Right), K1->Height) + 1;

	return K2;  /* New root */
}


/* This function can be called only if K3 has a left */
/* child and K3's left child has a right child */
/* Do the left-right double rotation */
/* Update heights, then return new root */

static AvlTree DoubleRotateWithLeft(AvlTree K3)
{
	/* Rotate between K1 and K2 */
	K3->Left = SingleRotateWithRight(K3->Left);

	/* Rotate between K3 and K2 */
	return SingleRotateWithLeft(K3);
}


/* This function can be called only if K1 has a right */
/* child and K1's right child has a left child */
/* Do the right-left double rotation */
/* Update heights, then return new root */

static AvlTree DoubleRotateWithRight(AvlTree K1)
{
	/* Rotate between K3 and K2 */
	K1->Right = SingleRotateWithLeft(K1->Right);

	/* Rotate between K1 and K2 */
	return SingleRotateWithRight(K1);
}

AvlTree Insert(ElementType X, AvlTree T)
{
	if (!T)
	{
		T = malloc(sizeof(struct AvlRecord));
		if (!T)
			Error("Out of space");
		else
		{
			T->Element = X; T->Height = 0;
			T->Left = T->Right = NULL;
		}
	}
	else
		if (X < T->Element)
		{
			T->Left = Insert(X, T->Left);//?
			if (Height(T->Left) - Height(T->Right) == 2)
				if (X < T->Left->Element)
					T = SingleRotateWithLeft(T);
				else
					T = DoubleRotateWithLeft(T);
		}
		else
			if (X > T->Element)
			{
				T->Right = Insert(X, T->Right);
				if (Height(T->Right) - Height(T->Left) == 2)
					if (X > T->Right->Element)
						T = SingleRotateWithRight(T);
					else
						T = DoubleRotateWithRight(T);
			}
			/* Else X is in the tree already; we'll do nothing */
	T->Height = MAX(Height(T->Left), Height(T->Right)) + 1;
	return T;
}
#endif