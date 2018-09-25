#ifndef _Tree_H
#define _Tree_H

#define Error( Str )        fprintf( stderr, "%s\n", Str ), exit( 1 )
typedef int ElementType;
struct SearchTreeRecord
{
	ElementType Element;
	SearchTree  Left;
	SearchTree  Right;
};
typedef struct SearchTreeRecord *SearchTree;



SearchTree MakeEmpty(SearchTree T);
SearchTree Find(ElementType X, SearchTree T);
SearchTree FindMin(SearchTree T);
SearchTree FindMax(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);





SearchTree MakeEmpty(SearchTree T)
{
	if (T)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

SearchTree Find(ElementType X, SearchTree T)
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

SearchTree FindMin(SearchTree T)
{
	if (T)
		while (T->Left)
			T = T->Left;
	return T;
}

SearchTree FindMax(SearchTree T)
{
	if (T)
		while (T->Right)
			T = T->Right;
	return T;
}


SearchTree Insert(ElementType X, SearchTree T)
{
	if (!T)
	{
		/* Create and return a one-node tree */
		T = malloc(sizeof(struct SearchTreeRecord));
		if (!T)
			Error("Out of space");
		else
		{
			T->Element = X;
			T->Left = T->Right = NULL;
		}
	}
	else
		if (X < T->Element)
			T->Left = Insert(X, T->Left);
		else
			if (X > T->Element)
				T->Right = Insert(X, T->Right);
	/* Else X is in the tree already; we'll do nothing */
	return T;
}

SearchTree Delete(ElementType X, SearchTree T)
{
	if (!T)
		Error("Tree not found");
	else
		if (X < T->Element)  /* Go left */
			T->Left = Delete(X, T->Left);
		else
			if (X > T->Element)  /* Go right */
				T->Right = Delete(X, T->Right);
			else  /* Found element to be deleted */
				if (T->Left && T->Right)  /* Two children */
				{
					/* Replace with smallest in right subtree */
					TmpCell = FindMin(T->Right);
					T->Element = TmpCell->Element;
					T->Right = Delete(T->Element, T->Right);
				}
				else  /* One or zero children */
				{
					if (!T->Left) /* Also handles 0 children */
						T = T->Right;
					else if (!T->Right)
						T = T->Left;
					free(T);
					T == NULL;
				}
	return T;
}


