#include<stdio.h> //cpp p410 6
#include<stdlib.h>
#include<time.h>
#define LIML 1000
#define LIM 10
int cmp(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}
int main(void)
{
	int arr[LIML];
	srand((unsigned int)time(0));
	int ans[LIM] = {0};
	for (int i = 0; i < LIML; i++)
	{
		arr[i] = rand() % LIM + 1;
		ans[arr[i] - 1]++;
	}
	qsort(arr, LIML, sizeof(arr[0]), cmp);
	for(int i = 0; i < LIM; i++)
		printf("%d:%d\n", i+1,ans[i]);
	return 0;
}