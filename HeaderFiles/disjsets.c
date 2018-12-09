//disjoint set  ���� -rank

#define Error( Str )        fprintf( stderr, "%s\n", Str ), exit( 1 )
typedef int* DisjSet;
typedef int ElementType;

DisjSet Initialize(int size);
void SetUnion(DisjSet S,int a,int b);
int Find(ElementType X,DisjSet S);


DisjSet Initialize(int size)
{
	DisjSet S=malloc(sizeof(ElementType)*size);
	if(!S)
		Error("Out of space.");
	for(int i=size;i>=0;i--)
		S[i]=-1;
	return S;
}

void SetUnion(DisjSet S,int a,int b)
{
	int Root1=Find(a),Root2=Find(b);
	if(S[Root1]<S[Root2]) /* Root1 is deeper set */
		S[Root2]=Root1;  /* Make Root1 new root */
	else
	{
		if(S[Root1]==S[Root2])  /* Same height, */
			S[Root2]--;               /* so update */
		S[Root1]=Root2;
	}
}

int Find(ElementType X,DisjSet S)
{
	/*if(S[X]<0)
	return X;
	else
	return S[X]=Find(S[X],S);*/

    int p=X,t;
	while(S[p]>=0)
		p=S[p];
	while(X!=p)
	{
		t=S[X];
		S[X]=p;
		X=t;
	}
	return X;
}

main()
{
	DisjSet S;
	int j,k;

	Initialize(S);
	j=k=0;
	while(k<=8)
	{
		j=0;
		while(j<=NumSets)
		{
			SetUnion(S,j,j+k);
			j+=2*k;
		}
		k*=2;
	}
	for(int i=0; i<NumSets; i++)
		printf("%d**",Find(i,S));
	printf("\n");
	return 0;
}

