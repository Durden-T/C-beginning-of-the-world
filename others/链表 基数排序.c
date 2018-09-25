#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define RANDMAX 10000
typedef struct Node *List;
struct Node
{
	int value;
	List next;
};
void getRandArray(int *a,int size);
void printArray(int *a,int size);
void radixSort(int *a,int size);
int getMaxLength(int *a,int size);
int isSorted(int *a,int size);

int main(void)
{
	int size;
	scanf("%d",&size);
	int *array=(int *)malloc(size*sizeof(int));
	getRandArray(array,size);
	printArray(array,size);
	radixSort(array,size);
	printArray(array,size);
	if(isSorted(array,size))
		printf("Sorted");
	else
		printf("Not sorted");
	free(array);
	return 0;
}

void getRandArray(int *a,int size)
{
	srand(time(NULL));
	for(int i=0; i<size; i++)
		a[i]=rand()%RANDMAX;
}

void printArray(int *a,int size)
{
	for(int i=0; i<size; i++)
		printf("%d ",a[i]);
	putchar('\n');
}

void radixSort(int *a,int size)
{
	int MaxLength=getMaxLength(a,size);
	List tmp;
	List larray[10];
	for(int i=0;i<10;i++)
	{
		larray[i]=(List)malloc(sizeof(struct Node));
		larray[i]->value=0;
		larray[i]->next=NULL;
	}
	for(int i=1,div=1; i<=MaxLength; i++,div*=10)
	{
		for(int j=0; j<size; j++)
		{
			tmp=larray[(a[j]/div)%10];
			while(tmp->value)
				tmp=tmp->next;
			tmp->value=a[j];
			if(!tmp->next)
			{
				tmp->next=(List)malloc(sizeof(struct Node));
				tmp->next->value=0;
				tmp->next->next=NULL;
			}
		}
		tmp=larray[0];
        int listi = 0, arrayi = 0;
        while(arrayi<size)
		{
			if(tmp->value)
			{
				a[arrayi++]=tmp->value;
				tmp->value=0;
				tmp=tmp->next;
			}
			else
				tmp=larray[++listi];
		}
	}
}

int getMaxLength(int *a,int size)
{
	int max=a[0];
	for(int i=1; i<size; i++)
		if(a[i]>max)
            max = a[i];
    int res=1;
	while(max/=10)
		res++;
	return res;
}

int isSorted(int *a,int size)
{
	for(int i=0; i<size-1; i++)
		if(a[i]>a[i+1])
			return 0;
	return 1;
}

