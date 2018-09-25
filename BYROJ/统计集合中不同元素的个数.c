/*
#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a, const void *b)
{
	return(*(int *)b - *(int *)a);
}
int main(void)
{
	int n, count = 1;
	scanf("%d", &n);
	int *a=malloc(4*n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	qsort(a, n, 4, cmp);
	for (int i = 0; i < n - 1; i++)
		if (a[i] != a[i + 1])
			count++;
	printf("%d", count);

		return 0;
}*/


#include<stdio.h>
int cmp(const void *a, const void *b)
{
	return(*(int *)b - *(int *)a);
}
int main(void)
{
	int n, count = 1;
	scanf("%d", &n);
	int a[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	qsort(a, n, 4, cmp);
	for (int i = 0; i < n - 1; i++)
		if (a[i] != a[i + 1])
			count++;
	printf("%d", count);
	return 0;
}